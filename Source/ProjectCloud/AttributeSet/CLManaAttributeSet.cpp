// Fill out your copyright notice in the Description page of Project Settings.


#include "CLManaAttributeSet.h"

UCLManaAttributeSet::UCLManaAttributeSet()
{
}

bool UCLManaAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	return false;
}

void UCLManaAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
}
