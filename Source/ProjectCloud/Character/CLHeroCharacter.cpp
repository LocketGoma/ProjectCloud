// Fill out your copyright notice in the Description page of Project Settings.


#include "CLHeroCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/Controller.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/InputComponent.h"
#include "ProjectCloud/Components/CLAttackerNodeComponent.h"


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
}

void ACLHeroCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

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
		PlayerInputComponent->BindVectorAxis(EKeys::Mouse2D, this, &ACLHeroCharacter::TrackingMousePosition);
	}
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
