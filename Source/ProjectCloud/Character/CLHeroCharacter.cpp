// Fill out your copyright notice in the Description page of Project Settings.


#include "CLHeroCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "CLPlayerState.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/InputComponent.h"
#include "ProjectCloud/Components/CLAttackerNodeComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "ProjectCloud/System/CLCharacterAttributeSet.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"

//UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Attack, "Input.Action.Attack");
//UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Health, "Attribute.Data.Health");

ACLHeroCharacter::ACLHeroCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetCanBeDamaged(true);

	SetRemoteRoleForBackwardsCompat(ROLE_SimulatedProxy);
	bReplicates = true;
	NetPriority = 3.0f;

	BaseEyeHeight = 0.0f;
	bCollideWhenPlacing = false;
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetMovementComponent()->UpdatedComponent = RootComponent;

	AttackerComponent = CreateDefaultSubobject<UCAttackerNodeComponent>(TEXT("AttackerNodeComponent"));	
	AttackerComponent->SetupAttachment(RootComponent);

	// This is the default pawn class, we want to have it be able to move out of the box.
	bAddDefaultMovementBindings = true;

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	AttributeSet = CreateDefaultSubobject<UCLCharacterAttributeSet>(TEXT("AttributeSet"));
}

void ACLHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	SetAbilitySystemComponent();

	if (GetPlayerController())
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetPlayerController()->GetLocalPlayer()))
			SubSystem->AddMappingContext(InputContext, 0);
	}
}

void ACLHeroCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

//Duplicated?
void InitializeDefaultPawnInputBindings()
{
	static bool bBindingsAdded = false;
	if (!bBindingsAdded)
	{
		bBindingsAdded = true;

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::W, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::S, -1.f));
		
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveRight", EKeys::A, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveRight", EKeys::D, 1.f));

		// HACK: Android controller bindings in ini files seem to not work
		//  Direct overrides here some to work
#if !PLATFORM_ANDROID
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_LeftThumbstick, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_RightThumbstick, -1.f));
#else
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveRight", EKeys::Gamepad_LeftX, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::Gamepad_LeftY, 1.f));		;
#endif
	}
}

void ACLHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	if (bAddDefaultMovementBindings)
	{
		InitializeDefaultPawnInputBindings();

		PlayerInputComponent->BindAxis("DefaultPawn_MoveForward", this, &ACLHeroCharacter::MoveForward);
		PlayerInputComponent->BindAxis("DefaultPawn_MoveRight", this, &ACLHeroCharacter::MoveRight);
	}

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACLHeroCharacter::Move);

		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &ACLHeroCharacter::BaseAttack);

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
	PlayerInputComponent->BindVectorAxis(EKeys::Mouse2D, this, &ACLHeroCharacter::TrackingMousePosition);

}

void ACLHeroCharacter::UpdateNavigationRelevance()
{
	if (RootComponent)
	{
		RootComponent->SetCanEverAffectNavigation(bCanAffectNavigationGeneration);
	}
}

void ACLHeroCharacter::MoveForward(float Val)
{
	if (Val != 0.f)
	{
		if (Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			// transform to world space and add it
			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), Val);
		}
	}
}

void ACLHeroCharacter::MoveRight(float Val)
{
	if (Val != 0.f)
	{
		if (Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			// transform to world space and add it
			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), Val);
		}
	}
}

void ACLHeroCharacter::MoveUp_World(float Val)
{
	if (Val != 0.f)
	{
		AddMovementInput(FVector::UpVector, Val);
	}
}

void ACLHeroCharacter::SetAbilitySystemComponent()
{
	UEnhancedInputComponent* EnhancedInputComponent = GetComponentByClass<UEnhancedInputComponent>();

	if (ACLPlayerState * PS = Cast<ACLPlayerState>(GetPlayerState()))
	{
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);
		PS->SetAbilitiesFromActionSet(AbilitySet);
		PS->GetAbilitySystemComponent()->BindInputActions(InputConfig, EnhancedInputComponent);

		//특정 GameplayEffect에서 데이터 가져오는 방법
		if (IsValid(HealthGE))
		{
			//FGameplayEffectContextHandle EffectContext = PS->GetAbilitySystemComponent()->MakeEffectContext();
			//FGameplayEffectSpecHandle SpecHandle = PS->GetAbilitySystemComponent()->MakeOutgoingSpec(HealthGE, 1.0f, EffectContext);

			//if (SpecHandle.IsValid())
			//{
			//	const FGameplayEffectSpec* Spec = SpecHandle.Data.Get();
			//	float Health = Spec->Modifiers[0].GetEvaluatedMagnitude();

			//	AttributeSet->SetHealth(Health);
			//}

			const UGameplayEffect* GameplayEffect = HealthGE.GetDefaultObject();


			for (const FGameplayModifierInfo& Modifier : GameplayEffect->Modifiers)
			{
				if (Modifier.Attribute == AttributeSet->HealthAttribute())
				{
					float Health;
					Modifier.ModifierMagnitude.GetStaticMagnitudeIfPossible(0, Health);

					AttributeSet->SetHealth(Health);
				}
			}

		}
		PS->GetAbilitySystemComponent()->AddAttributeSetSubobject(AttributeSet);
	}
}

UCLAbilitySystemComponent* ACLHeroCharacter::GetAbilitySystemComponent()
{
	if (ACLPlayerState* PS = Cast<ACLPlayerState>(GetPlayerState()))
	{
		return PS->GetAbilitySystemComponent();
	}

	return nullptr;
}

UCAttackerNodeComponent* ACLHeroCharacter::GetAttackerNode()
{
	if (!ensure(AttackerComponent))
	{
		return nullptr;
	}

	return AttackerComponent;
}

ACLWeapon* ACLHeroCharacter::GetWeaponActor()
{
	if (!ensure(AttackerComponent))
	{
		return nullptr;
	}

	return AttackerComponent->GetWeaponActor();
}

float ACLHeroCharacter::GetHealth()
{
	return 0.0f;
}

APlayerController* ACLHeroCharacter::GetPlayerController() const
{
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
		return PlayerController;

	return nullptr;
}

//TO DO : 어빌리티로 변경
void ACLHeroCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

//TO DO : 어빌리티로 변경
void ACLHeroCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ACLHeroCharacter::BaseAttack(const FInputActionValue& Value)
{
	if (ACLPlayerState* PS = Cast<ACLPlayerState>(GetPlayerState()))
	{
		FGameplayEventData TempPayload;
		TempPayload.EventTag = TAG_Attack;
		PS->GetAbilitySystemComponent()->HandleGameplayEvent(TAG_Attack, &TempPayload);		
	}
}

void ACLHeroCharacter::RotateAttackPoint(float Val)
{	
	if (AttackerComponent && Val != 0.f)
	{
		AttackerComponent->AddRotation(Val);
	}
}

void ACLHeroCharacter::TrackingMousePosition(FVector Position)
{
	FHitResult HitResult;
	FVector2D MousePosition = FVector2D(Position.X, Position.Y);
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		PlayerController->GetMousePosition(MousePosition.X, MousePosition.Y);		

		if (PlayerController->GetHitResultAtScreenPosition(MousePosition, ECC_Visibility, true, HitResult))
		{
			FVector TargetLocation = HitResult.Location;
			FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TargetLocation);

			if (AttackerComponent)
			{
				AttackerComponent->UpdateRotation(TargetRotation.Yaw);
			}

			if (bDebugMove)
			{
				//UE_LOG(LogTemp, Log, TEXT("Mouse Pos :: (%f, %f), Rotation : (%f)"), MousePosition.X, MousePosition.Y, TargetRotation.Yaw);
				GEngine->AddOnScreenDebugMessage(-1, 0.016f, FColor::Blue, FString::Printf(TEXT("Mouse Pos :: (%f, %f), Rotation : (%f)"), MousePosition.X, MousePosition.Y, TargetRotation.Yaw));
			}
		}
	}
	
}
