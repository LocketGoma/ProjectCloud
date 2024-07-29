// Fill out your copyright notice in the Description page of Project Settings.


#include "CLHeroCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/Controller.h"
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
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::Up, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::Down, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::Gamepad_LeftY, 1.f));

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveRight", EKeys::A, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveRight", EKeys::D, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveRight", EKeys::Gamepad_LeftX, 1.f));

		// HACK: Android controller bindings in ini files seem to not work
		//  Direct overrides here some to work
#if !PLATFORM_ANDROID
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_LeftThumbstick, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_RightThumbstick, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_FaceButton_Bottom, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::LeftControl, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::SpaceBar, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::C, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::E, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Q, -1.f));
#else
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_LeftTriggerAxis, -0.5f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Gamepad_RightTriggerAxis, 0.5f));
#endif

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_TurnRate", EKeys::Gamepad_RightX, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_TurnRate", EKeys::Left, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_TurnRate", EKeys::Right, 1.f));

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_LookUpRate", EKeys::Gamepad_RightY, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_Turn", EKeys::MouseX, 1.f));
		//UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_LookUp", EKeys::MouseY, -1.f));
	}
}

void ACLHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	if (bAddDefaultMovementBindings)
	{
		InitializeDefaultPawnInputBindings();

		if (bDebugMove)
		{
			PlayerInputComponent->BindAxis("DefaultPawn_MoveForward", this, &ACLHeroCharacter::MoveForward);
			PlayerInputComponent->BindAxis("DefaultPawn_MoveRight", this, &ACLHeroCharacter::MoveRight);
			PlayerInputComponent->BindAxis("DefaultPawn_MoveUp", this, &ACLHeroCharacter::MoveUp_World);
			PlayerInputComponent->BindAxis("DefaultPawn_TurnRate", this, &ACLHeroCharacter::RotateAttackPoint);
			PlayerInputComponent->BindAxis("DefaultPawn_Turn", this, &ACLHeroCharacter::RotateAttackPoint);
		}

		//if (bFreeCamera)
		//{
		//	PlayerInputComponent->BindAxis("DefaultPawn_LookUp", this, &ACLHeroCharacter::AddControllerPitchInput);
		//	PlayerInputComponent->BindAxis("DefaultPawn_LookUpRate", this, &ACLHeroCharacter::LookUpAtRate);
		//}
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

void ACLHeroCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds() * CustomTimeDilation);
}

void ACLHeroCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds() * CustomTimeDilation);
}

void ACLHeroCharacter::RotateAttackPoint(float Val)
{	
	if (AttackerComponent && Val != 0.f)
	{
		AttackerComponent->AddRotation(Val);
	}
}
