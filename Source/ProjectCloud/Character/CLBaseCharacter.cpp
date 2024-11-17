// Copyright @Locketgoma. All Rights Reserved.

#include "CLBaseCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/CollisionProfile.h"
#include "ProjectCloud/System/CLAbilitySet.h"
#include "Components/CapsuleComponent.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"
#include "ProjectCloud/AttributeSet/CLCharacterAttributeSet.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Components/CLHitEffectComponent.h"

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

	HitEffectComponent = CreateDefaultSubobject<UCLHitEffectComponent>(TEXT("HitEffectComponent"));
	HitEffectComponent->SetupAttachment(RootComponent);

	GetCapsuleComponent()->InitCapsuleSize(12.0f, 8.f);

	GetMovementComponent()->UpdatedComponent = RootComponent;

	ImmmuneTime = 0.1f;
	bImmune = false;
}

void ACLBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACLBaseCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UnInitializeAbilitySystemComponent();
}

//반드시 오버라이드 할것
UCLAbilitySystemComponent* ACLBaseCharacter::GetAbilitySystemComponent()
{
	return nullptr;
}

void ACLBaseCharacter::InitializeAbilitySystemComponent(UCLAbilitySystemComponent* ASC)
{
	//체력 관련 델리게이트는 Character에 연결 (경험치는 PlayerState, 마나는...?)
	if (ASC)
	{
		HealthAttributeSet = ASC->GetSet<UCLCharacterAttributeSet>();
		HealthAttributeSet->OnHealthChanged.AddUObject(this, &ThisClass::HandleHealthChanged);
		HealthAttributeSet->OnMaxHealthChanged.AddUObject(this, &ThisClass::HandleMaxHealthChanged);
		HealthAttributeSet->OnOutOfHealth.AddUObject(this, &ThisClass::HandleOutOfHealth);
	}	
}

void ACLBaseCharacter::UnInitializeAbilitySystemComponent()
{
	//ClearGameplayTags();

	if (HealthAttributeSet)
	{
		HealthAttributeSet->OnHealthChanged.RemoveAll(this);
		HealthAttributeSet->OnMaxHealthChanged.RemoveAll(this);
		HealthAttributeSet->OnOutOfHealth.RemoveAll(this);
	}

	HealthAttributeSet = nullptr;	
}

void ACLBaseCharacter::HandleHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue)
{
	if (OldValue > NewValue)
	{
		if (!ImmuneTimerHandle.IsValid())
		{
			GetWorld()->GetTimerManager().SetTimer(ImmuneTimerHandle, this, &ACLBaseCharacter::ClearImmunityState, ImmmuneTime, false);
			SetImmunity(true);
		}
	}
	HitEffectComponent->PlayNiagaraEffect(NewValue - OldValue);

	OnHealthChanged.Broadcast(OldValue, NewValue);
}

void ACLBaseCharacter::HandleMaxHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue)
{
}

void ACLBaseCharacter::HandleOutOfHealth(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue)
{
	OnOutOfHealth.Broadcast();
}

void ACLBaseCharacter::SetImmunity(bool NewImmunity)
{
	if (IsValid(GetAbilitySystemComponent()))
	{
		if (NewImmunity == true)
		{
			GetAbilitySystemComponent()->AddLooseGameplayTag(TAG_Event_Status_DamageImmunity);
		}
		else
		{
			GetAbilitySystemComponent()->SetLooseGameplayTagCount(TAG_Event_Status_DamageImmunity, 0);
		}
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

