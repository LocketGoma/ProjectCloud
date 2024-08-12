// CopyLight : LocketGoma


#include "CLBaseCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/CollisionProfile.h"
#include "Components/CapsuleComponent.h"


ACLBaseCharacter::ACLBaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetCanBeDamaged(true);

	SetRemoteRoleForBackwardsCompat(ROLE_SimulatedProxy);
	bReplicates = true;
	NetPriority = 3.0f;

	BaseEyeHeight = 0.0f;
	bCollideWhenPlacing = false;
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetCapsuleComponent()->SetCapsuleHalfHeight(8.f);
	GetCapsuleComponent()->SetCapsuleRadius(16.f);

	GetMovementComponent()->UpdatedComponent = RootComponent;
}

void ACLBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACLBaseCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}