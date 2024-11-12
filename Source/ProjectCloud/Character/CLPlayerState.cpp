// Fill out your copyright notice in the Description page of Project Settings.


#include "CLPlayerState.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/System/CLAbilitySet.h"
#include "ProjectCloud/System/CLGameState.h"
#include "CLBaseCharacter.h"

ACLPlayerState::ACLPlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bAbilitySet = false;
	AbilityComponent = CreateDefaultSubobject<UCLAbilitySystemComponent>("AbilitySystemComponent");	
	AbilityComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

void ACLPlayerState::BeginPlay()
{
	Super::BeginPlay();
}

void ACLPlayerState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UnInitializeDelegates();
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

	InitializeDelegates();

	//AbilityComponent->AddGameplayEventTagContainerDelegate()
}

void ACLPlayerState::InitializePlayerState(UCLAbilitySet* AbilitySet)
{
	SetAbilitiesFromActionSet(AbilitySet);
	InitializeDelegates();
}

void ACLPlayerState::InitializeDelegates()
{
	ACLBaseCharacter* PlayerPawn = Cast<ACLBaseCharacter>(GetPawn());
	
	if (ensure(PlayerPawn))
	{
		PlayerPawn->OnOutOfHealth.AddUObject(this, &ThisClass::HandlePlayerOutOfHealth);
	}
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
