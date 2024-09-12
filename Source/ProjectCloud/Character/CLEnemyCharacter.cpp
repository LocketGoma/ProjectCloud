// Fill out your copyright notice in the Description page of Project Settings.
#include "CLEnemyCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "AIController.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/System/CLEnemyAttributeSet.h"
#include "GameplayAbilitySet.h"


ACLEnemyCharacter::ACLEnemyCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AbilityComponent = CreateDefaultSubobject<UCLAbilitySystemComponent>("AbilitySystemComponent");	
	AbilityComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UCLEnemyAttributeSet>(TEXT("AttributeSet"));
}

void ACLEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (bManualTargetSettings && !TargetPlayer.IsValid())
		TargetPlayer = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (GetController())
	{
		SetAI();
	}
}

void ACLEnemyCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ACLEnemyCharacter::SetTargetPlayer(APawn* NewTarget)
{
	check(NewTarget);

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
		UE_LOG(LogTemp, Error, TEXT("Some EnmeyCharacter's ASC is not Set! Must be Check this Error. Name : [%s]"), *GetName());
		return;
	}
	AbilityComponent->InitAbilityActorInfo(this, this);

	if (IsValid(HealthGE))
	{
		FGameplayEffectContextHandle EffectContext = GetAbilitySystemComponent()->MakeEffectContext();
		FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(HealthGE, 1.0f, EffectContext);

		if (SpecHandle.IsValid())
		{
			FGameplayEffectSpec* Spec = SpecHandle.Data.Get();

			float HealthAmount = Spec->GetModifierMagnitude(0, false);
			AttributeSet->SetHealth(HealthAmount);

			GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*Spec);
		}
	}

}
