// Fill out your copyright notice in the Description page of Project Settings.
#include "CLEnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "AIController.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/System/CLEnemyAttributeSet.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "GameplayAbilitySet.h"


ACLEnemyCharacter::ACLEnemyCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AbilityComponent = CreateDefaultSubobject<UCLAbilitySystemComponent>("AbilitySystemComponent");	
	AbilityComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);	

	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ACLEnemyCharacter::OnHit);
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
	//const UCLEnemyAttributeSet* AttributeSet = Cast<UCLEnemyAttributeSet>(GetAbilitySystemComponent()->GetAttributeSet(UCLEnemyAttributeSet::StaticClass()));
	const UCLEnemyAttributeSet* AttributeSet = GetAbilitySystemComponent()->GetSet<UCLEnemyAttributeSet>();

	return AttributeSet->GetHealth();
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

	if (IsValid(AttributeGameplayEffect))
	{
		FGameplayEffectContextHandle EffectContext = GetAbilitySystemComponent()->MakeEffectContext();
		FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(AttributeGameplayEffect, 1.0f, EffectContext);

		if (SpecHandle.IsValid())
		{
			FGameplayEffectSpec* Spec = SpecHandle.Data.Get();

			UCLEnemyAttributeSet* NewAttributeSet = NewObject<UCLEnemyAttributeSet>(this);
			GetAbilitySystemComponent()->AddAttributeSetSubobject(NewAttributeSet);

			GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*Spec);			
		}
	}
}

void ACLEnemyCharacter::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != this && OtherComp)
	{
		ACLBaseCharacter* TargetCharacter = Cast<ACLBaseCharacter>(OtherActor);
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
