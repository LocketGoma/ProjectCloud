// Fill out your copyright notice in the Description page of Project Settings.

#include "CLSpellInstance.h"
#include "Abilities/GameplayAbility.h"

const TArray<EArrowInputHandleType> UCLSpellInstance::GetSpellCommands(UCLSpellInstance& Instance)
{
	return Instance.SpellCommands;
}

const TArray<EArrowInputHandleType> UCLSpellInstance::GetSpellCommands(TSubclassOf<UCLSpellInstance> Instance)
{
	if (IsValid(Instance))
	{
		return GetSpellCommands(*(Instance.GetDefaultObject()));
	}

	return TArray<EArrowInputHandleType>();
}

const TSubclassOf<UGameplayAbility> UCLSpellInstance::GetSpellAbility(UCLSpellInstance& Instance)
{
	return Instance.SpellAbility;
}

const TSubclassOf<UGameplayAbility> UCLSpellInstance::GetSpellAbility(TSubclassOf<UCLSpellInstance> Instance)
{
	if (IsValid(Instance))
	{
		return GetSpellAbility(*(Instance.GetDefaultObject()));
	}

	return nullptr;
}

const EActiveSpellType UCLSpellInstance::GetSpellType(UCLSpellInstance& Instance)
{
	return Instance.SpellType;
}

const EActiveSpellType UCLSpellInstance::GetSpellType(TSubclassOf<UCLSpellInstance> Instance)
{
	if (IsValid(Instance))
	{
		return GetSpellType(*(Instance.GetDefaultObject()));
	}

	return EActiveSpellType();
}

const float UCLSpellInstance::GetSpellCost(UCLSpellInstance& Instance)
{
	return Instance.SpellCost;
}

const float UCLSpellInstance::GetSpellCost(TSubclassOf<UCLSpellInstance> Instance)
{
	if (IsValid(Instance))
	{
		return GetSpellCost(*(Instance.GetDefaultObject()));
	}

	return 0.0f;
}
