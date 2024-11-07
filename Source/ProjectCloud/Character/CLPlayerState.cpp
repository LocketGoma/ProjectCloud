// Fill out your copyright notice in the Description page of Project Settings.


#include "CLPlayerState.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/System/CLAbilitySet.h"
#include "CLHeroCharacter.h"

ACLPlayerState::ACLPlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bAbilitySet = false;
	AbilityComponent = CreateDefaultSubobject<UCLAbilitySystemComponent>("AbilitySystemComponent");	
	AbilityComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
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
}
