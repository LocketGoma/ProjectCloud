// Fill out your copyright notice in the Description page of Project Settings.
#include "CLEnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "AIController.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Components/CLRewardDropComponent.h"
#include "ProjectCloud/AttributeSet/CLCharacterAttributeSet.h"
#include "ProjectCloud/AttributeSet/CLCombatAttributeSet.h"
#include "ProjectCloud/Character/CLHeroCharacter.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"
#include "GameplayAbilitySet.h"


ACLEnemyCharacter::ACLEnemyCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AbilityComponent = CreateDefaultSubobject<UCLAbilitySystemComponent>("AbilitySystemComponent");	
	AbilityComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);	

	RewardDropComponent = CreateDefaultSubobject<UCLRewardDropComponent>("RewardDropComponent");

	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ACLEnemyCharacter::OnHit);
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACLEnemyCharacter::OnComponentBeginOverlap);
}

void ACLEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (bManualTargetSettings && !TargetPlayer.IsValid())
		TargetPlayer = GetWorld()->GetFirstPlayerController()->GetPawn();

	SetAbilitySystemComponent();

	if (GetController())
	{
		SetAI();
	}
}

void ACLEnemyCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

float ACLEnemyCharacter::GetHealth()
{
	if (HealthAttributeSet)
		return HealthAttributeSet->GetHealth();

	return 0.0f;
}

void ACLEnemyCharacter::SetTargetPlayer(APawn* NewTarget)
{
	if (IsValid(NewTarget))
	{
		UE_LOG(LogCloud, Error, TEXT("Player Character is Dead!"));
	}

	TargetPlayer = NewTarget;
}

void ACLEnemyCharacter::SetAI()
{
	AAIController* AIController = Cast<AAIController>(GetController());
	if (ensure(AIController))
	{
		UBlackboardComponent* Blackboard;
		AIController->UseBlackboard(BTAsset->BlackboardAsset, Blackboard);
		AIController->GetBlackboardComponent()->SetValueAsObject(FName(*TargetPlayerValueName), TargetPlayer.Get());
		AIController->RunBehaviorTree(BTAsset);
	}
}

void ACLEnemyCharacter::SetAbilitySystemComponent()
{
	if (!ensure(AbilityComponent))
	{
		UE_LOG(LogCloud, Error, TEXT("Some EnmeyCharacter's ASC is not Set! Must be Check this Error. Name : [%s]"), *GetName());
		return;
	}
	AbilityComponent->InitAbilityActorInfo(this, this);

	if (IsValid(AttributeGameplayEffect))
	{
		FGameplayEffectContextHandle EffectContext = GetAbilitySystemComponent()->MakeEffectContext();
		FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(AttributeGameplayEffect, 1.0f, EffectContext);

		if (SpecHandle.IsValid())
		{
			FGameplayEffectSpec* Spec = SpecHandle.Data.Get();

			//어트리뷰트셋 추가
			//Lyra의 ALyraPlayerState에 보면 AbilitySystemComponent::InitializeComponent 호출될때 자동으로 추가된다는 코멘트가 있긴한데..
			UCLCombatAttributeSet* NewCombatAttributeSet = NewObject<UCLCombatAttributeSet>(this);
			UCLCharacterAttributeSet* NewCharacterAttributeSet = NewObject<UCLCharacterAttributeSet>(this);
			GetAbilitySystemComponent()->AddAttributeSetSubobject(NewCombatAttributeSet);
			GetAbilitySystemComponent()->AddAttributeSetSubobject(NewCharacterAttributeSet);

			GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*Spec);			
		}
	}

	InitializeAbilitySystemComponent(AbilityComponent);

}

void ACLEnemyCharacter::HandleHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue)
{
	Super::HandleHealthChanged(DamageInstigator, DamageCauser, DamageEffectSpec, DamageMagnitude, OldValue, NewValue);
}

void ACLEnemyCharacter::HandleMaxHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue)
{
	Super::HandleMaxHealthChanged(DamageInstigator, DamageCauser, DamageEffectSpec, DamageMagnitude, OldValue, NewValue);
}

void ACLEnemyCharacter::HandleOutOfHealth(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue)
{
	Super::HandleOutOfHealth(DamageInstigator, DamageCauser, DamageEffectSpec, DamageMagnitude, OldValue, NewValue);

	//뭐 죽는 효과를 넣던지...
	if (RewardDropComponent)
	{
		RewardDropComponent->TryDropItem();
	}

	DeathEvent();
}

void ACLEnemyCharacter::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != this && OtherComp)
	{
		ACLHeroCharacter* TargetCharacter = Cast<ACLHeroCharacter>(OtherActor);
		if (TargetCharacter)
		{
			UAbilitySystemComponent* ASC = TargetCharacter->GetAbilitySystemComponent();

			if (ASC)
			{
				FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
				EffectContext.AddSourceObject(this);

				FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(DamageGE, 1, EffectContext);
				if (SpecHandle.IsValid())
				{
					ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
				}
			}
		}
	}
}

void ACLEnemyCharacter::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && OtherComp)
	{
		ACLHeroCharacter* TargetCharacter = Cast<ACLHeroCharacter>(OtherActor);
		if (TargetCharacter)
		{
			UAbilitySystemComponent* ASC = TargetCharacter->GetAbilitySystemComponent();

			if (ASC)
			{
				FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
				EffectContext.AddSourceObject(this);

				FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(DamageGE, 1, EffectContext);
				if (SpecHandle.IsValid())
				{
					ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
				}
			}
		}
	}
}
