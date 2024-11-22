// Fill out your copyright notice in the Description page of Project Settings.


#include "CLSpellInstance.h"

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

const FGameplayTag UCLSpellInstance::GetSpellTag(UCLSpellInstance& Instance)
{
	return Instance.SpellTag;
}

const FGameplayTag UCLSpellInstance::GetSpellTag(TSubclassOf<UCLSpellInstance> Instance)
{
	if (IsValid(Instance))
	{
		return GetSpellTag(*(Instance.GetDefaultObject()));
	}

	return FGameplayTag();
}
