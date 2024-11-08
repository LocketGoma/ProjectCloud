// Fill out your copyright notice in the Description page of Project Settings.


#include "CLHeroCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "CLPlayerState.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Components/CLAttackerNodeComponent.h"
#include "ProjectCloud/System/CLCharacterAttributeSet.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"
#include "ProjectCloud/Input/CLInputComponent.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"


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

void ACLHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	// Set up action bindings
	if (UCLInputComponent* CLInputComponent = Cast<UCLInputComponent>(PlayerInputComponent)) {

		// Native		
		CLInputComponent->BindNativeAction(InputConfig, TAG_Input_Move, ETriggerEvent::Triggered, this, &ACLHeroCharacter::Input_Move, false);
		//CLInputComponent->BindNativeAction(InputConfig, TAG_Input_Look_Mouse, ETriggerEvent::Triggered, this, &ACLHeroCharacter::Input_LookMouse, false);

		TArray<uint32> BindHandles;
		CLInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::Input_AbilityInputTagPressed, &ThisClass::Input_AbilityInputTagReleased, /*out*/ BindHandles);
	}
	else
	{
		UE_LOG(LogCloud, Error, TEXT("'%s' Failed to find an Cloud Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
	//To do : Enhanced로 전부 교체해야됨!
	PlayerInputComponent->BindVectorAxis(EKeys::Mouse2D, this, &ACLHeroCharacter::TrackingMousePosition);

}

void ACLHeroCharacter::UpdateNavigationRelevance()
{
	if (RootComponent)
	{
		RootComponent->SetCanEverAffectNavigation(bCanAffectNavigationGeneration);
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

		UCLCharacterAttributeSet* NewAttributeSet = NewObject<UCLCharacterAttributeSet>(this);
		GetAbilitySystemComponent()->AddAttributeSetSubobject(NewAttributeSet);

		if (IsValid(AttributeGameplayEffect))
		{
			GetAbilitySystemComponent()->AddGameplayEffect(AttributeGameplayEffect);
		}		
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
	const UCLCharacterAttributeSet* AttributeSet = GetAbilitySystemComponent()->GetSet<UCLCharacterAttributeSet>();

	return AttributeSet->GetHealth();
}

APlayerController* ACLHeroCharacter::GetPlayerController() const
{
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
		return PlayerController;

	return nullptr;
}

//TO DO : 어빌리티로 변경
void ACLHeroCharacter::Input_Move(const FInputActionValue& Value)
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

void ACLHeroCharacter::RotateAttackPoint(float Val)
{	
	if (AttackerComponent && Val != 0.f)
	{
		AttackerComponent->AddRotation(Val);
	}
}

void ACLHeroCharacter::Input_AbilityInputTagPressed(FGameplayTag InputTag)
{
	UCLAbilitySystemComponent* CloudASC = GetAbilitySystemComponent();
	CloudASC->AbilityInputTagPressed(InputTag);
}

void ACLHeroCharacter::Input_AbilityInputTagReleased(FGameplayTag InputTag)
{
	UCLAbilitySystemComponent* CloudASC = GetAbilitySystemComponent();
	CloudASC->AbilityInputTagReleased(InputTag);
}

//얘 왜 클릭해야 작동하냐? <- 일단 나중에 수정하기
void ACLHeroCharacter::Input_LookMouse(const FInputActionValue& InputActionValue)
{
	const FVector2D Value = InputActionValue.Get<FVector2D>();

	TrackingMousePosition(Value);
}

void ACLHeroCharacter::TrackingMousePosition(FVector Position)
{
	const FVector2D Value = FVector2D(Position.X, Position.Y);

	TrackingMousePosition(Value);
}

void ACLHeroCharacter::TrackingMousePosition(FVector2D MousePosition)
{
	FHitResult HitResult;	
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

			if (bDebug)
			{
				//UE_LOG(LogTemp, Log, TEXT("Mouse Pos :: (%f, %f), Rotation : (%f)"), MousePosition.X, MousePosition.Y, TargetRotation.Yaw);
				GEngine->AddOnScreenDebugMessage(-1, 0.016f, FColor::Blue, FString::Printf(TEXT("Mouse Pos :: (%f, %f), Rotation : (%f)"), MousePosition.X, MousePosition.Y, TargetRotation.Yaw));
			}
		}
	}
	
}
