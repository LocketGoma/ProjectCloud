// Fill out your copyright notice in the Description page of Project Settings.


#include "CLPlayerState.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Components/CLLevelAbilityComponent.h"
#include "ProjectCloud/Components/CLExperienceComponent.h"
#include "ProjectCloud/System/CLAbilitySet.h"
#include "ProjectCloud/System/CLGameState.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"
#include "ProjectCloud/AttributeSet/CLManaAttributeSet.h"
#include "ProjectCloud/AttributeSet/CLCharacterAttributeSet.h"
#include "ProjectCloud/AttributeSet/CLExperiencePointAttributeSet.h"
#include "CLBaseCharacter.h"

ACLPlayerState::ACLPlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bAbilitySet = false;
	AbilityComponent = CreateDefaultSubobject<UCLAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	ExperienceComponent = CreateDefaultSubobject<UCLExperienceComponent>(TEXT("ExperienceComponent"));
	LevelAbilityComponent = CreateDefaultSubobject<UCLLevelAbilityComponent>(TEXT("LevelAbilityComponent"));
	AbilityComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	PlayerLevel = 1;
}

void ACLPlayerState::BeginPlay()
{
	Super::BeginPlay();

	OnTryLevelUpEvent.AddUObject(this, &ThisClass::HandleLevelUpEvent);
}

void ACLPlayerState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UnInitializeDelegates();
}

void ACLPlayerState::StartLevelupEvent()
{
	ACLGameState* GameState = Cast<ACLGameState>(GetWorld()->GetGameState());
	if (GameState)
	{
		GameState->HandleStartLevelupEvent();
	}
}

void ACLPlayerState::FinishLevelupEvent()
{
	ACLGameState* GameState = Cast<ACLGameState>(GetWorld()->GetGameState());
	if (GameState)
	{
		GameState->HandleFinishLevelupEvent();
	}	
}

const int ACLPlayerState::GetPlayerLevel()
{
	return PlayerLevel;
}

void ACLPlayerState::SetAbilitiesFromActionSet(UCLAbilitySet* AbilitySet)
{
	if (!ensure(AbilityComponent))
	{
		return;
	}	

	if ((AbilitySet) && (bAbilitySet == false))
	{
		AbilitySet->GiveToAbilitySystem(AbilityComponent, nullptr);

		bAbilitySet = true;;
	}

	//어차피 ASC가 PS에 있는데 그냥 PS에서 세팅하면 되는거 아님?
	UCLCharacterAttributeSet* NewCharacterAttributeSet = NewObject<UCLCharacterAttributeSet>(this);
	UCLExperiencePointAttributeSet* NewAExpttributeSet = NewObject<UCLExperiencePointAttributeSet>(this);
	UCLManaAttributeSet* NewManaAttributeSet = NewObject<UCLManaAttributeSet>(this);
	GetAbilitySystemComponent()->AddAttributeSetSubobject(NewCharacterAttributeSet);
	GetAbilitySystemComponent()->AddAttributeSetSubobject(NewAExpttributeSet);
	GetAbilitySystemComponent()->AddAttributeSetSubobject(NewManaAttributeSet);

	InitializeDelegates();

	//AbilityComponent->AddGameplayEventTagContainerDelegate()
}

void ACLPlayerState::InitializePlayerState(UCLAbilitySet* AbilitySet)
{
	SetAbilitiesFromActionSet(AbilitySet);	
}

void ACLPlayerState::InitializeDelegates()
{
	ACLBaseCharacter* PlayerPawn = Cast<ACLBaseCharacter>(GetPawn());
	
	if (ensure(PlayerPawn))
	{
		PlayerPawn->OnOutOfHealth.AddUObject(this, &ThisClass::HandlePlayerOutOfHealth);
	}

	ExperienceComponent->InitializeDelegates();
	LevelAbilityComponent->InitializeDelegates();
}

void ACLPlayerState::UnInitializeDelegates()
{
	ACLBaseCharacter* PlayerPawn = Cast<ACLBaseCharacter>(GetPawn());
	if (PlayerPawn)
	{
		PlayerPawn->OnOutOfHealth.RemoveAll(this);
	}
}

void ACLPlayerState::HandlePlayerOutOfHealth()
{
	PlayerOutOfHealthEvent();

	ACLGameState* GameState = Cast<ACLGameState>(GetWorld()->GetGameState());	
	if (GameState)
	{
		GameState->HandleGameOverEvent();		
	}
}

void ACLPlayerState::HandlePlayerCanLevelUp()
{
}

void ACLPlayerState::HandlePlayerEarnExp()
{
}

void ACLPlayerState::HandleLevelUpEvent(int64 NowExp)
{
	if (ExperienceComponent)
	{
		//컴포넌트에서도 검사했지만 한번 더 검사.
		if (NowExp >= ExperienceComponent->GetRequiredExpForLevelUp(PlayerLevel))
		{
			++PlayerLevel;

			ExperienceComponent->UpdateRequireExperience(PlayerLevel);

			OnLevelUpEvent.Broadcast(PlayerLevel);
			StartLevelupEvent();
		}
		else 
		{
			UE_LOG(LogCloud, Warning, TEXT("레벨업을 위한 충분한 경험치가 채워지지 않았습니다!"));
			checkNoEntry();
		}
	}
}
