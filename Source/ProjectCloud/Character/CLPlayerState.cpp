// Fill out your copyright notice in the Description page of Project Settings.


#include "CLPlayerState.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "GameplayAbilitySet.h"
#include "CLHeroCharacter.h"

ACLPlayerState::ACLPlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bAbilitySet = false;
	AbilityComponent = CreateDefaultSubobject<UCLAbilitySystemComponent>("AbilitySystemComponent");
	//AbilityComponent->SetIsReplicated(true);
	AbilityComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

}

void ACLPlayerState::SetAbilitiesFromActionSet(UGameplayAbilitySet* AbilitySet)
{
	if (!ensure(AbilityComponent))
	{
		return;
	}	

	if (!bAbilitySet)
	{
		for (FGameplayAbilityBindInfo Ability : AbilitySet->Abilities)
		{
			AbilityComponent->GiveAbility(Ability.GameplayAbilityClass);
		}
		bAbilitySet = true;;
	}
}
