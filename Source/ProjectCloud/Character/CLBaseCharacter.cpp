// CopyLight : LocketGoma


#include "CLBaseCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/CollisionProfile.h"
#include "GameplayAbilitySet.h"
#include "Components/CapsuleComponent.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"
#include "ProjectCloud/System/CLCharacterAttributeSet.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"

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

	bImmune = false;
}

void ACLBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACLBaseCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

//반드시 오버라이드 할것
UCLAbilitySystemComponent* ACLBaseCharacter::GetAbilitySystemComponent()
{
	return nullptr;
}

void ACLBaseCharacter::UpdateHealthEvent_Implementation(float ChangedHealth)
{
	if (!ImmuneTimerHandle.IsValid())
	{
		GetWorld()->GetTimerManager().SetTimer(ImmuneTimerHandle, this, &ACLBaseCharacter::ClearImmunityState, ImmmuneTime, false);
		SetImmunity(true);
	}
}

void ACLBaseCharacter::SetImmunity(bool NewImmunity)
{
	if (NewImmunity == true)
	{
		GetAbilitySystemComponent()->AddLooseGameplayTag(TAG_Event_Status_DamageImmunity);
	}
	else
	{
		GetAbilitySystemComponent()->SetLooseGameplayTagCount(TAG_Event_Status_DamageImmunity, 0);
	}

	bImmune = NewImmunity;

}

void ACLBaseCharacter::DeathEvent()
{
	//Do Something

	Destroy();
}

void ACLBaseCharacter::ClearImmunityState()
{
	GetWorld()->GetTimerManager().ClearTimer(ImmuneTimerHandle);
	ImmuneTimerHandle.Invalidate();

	SetImmunity(false);
}

