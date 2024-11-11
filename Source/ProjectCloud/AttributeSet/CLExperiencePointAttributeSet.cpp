// Fill out your copyright notice in the Description page of Project Settings.


#include "CLExperiencePointAttributeSet.h"

UCLExperiencePointAttributeSet::UCLExperiencePointAttributeSet()
{
}

bool UCLExperiencePointAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	return false;
}

void UCLExperiencePointAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
}
