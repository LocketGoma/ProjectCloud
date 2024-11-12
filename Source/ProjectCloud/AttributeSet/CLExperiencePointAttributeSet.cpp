// Fill out your copyright notice in the Description page of Project Settings.


#include "CLExperiencePointAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"

UCLExperiencePointAttributeSet::UCLExperiencePointAttributeSet()
{
}

bool UCLExperiencePointAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	// Save the current health
	EXPBeforeAttributeChange = GetEXP();
	MaxEXPBeforeAttributeChange = GetMaxEXP();

	return true;
}

void UCLExperiencePointAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	const FGameplayEffectContextHandle& EffectContext = Data.EffectSpec.GetEffectContext();
	AActor* Instigator = EffectContext.GetOriginalInstigator();




	OnEXPChanged.Broadcast(Instigator, &Data.EffectSpec, Data.EvaluatedData.Magnitude, EXPBeforeAttributeChange, GetEXP());
	OnMaxEXPChanged.Broadcast(Instigator, &Data.EffectSpec, Data.EvaluatedData.Magnitude, MaxEXPBeforeAttributeChange, GetMaxEXP());

	if (GetEXP()>=GetMaxEXP())
		OnEXPCharged.Broadcast(Instigator, &Data.EffectSpec, Data.EvaluatedData.Magnitude, EXPBeforeAttributeChange, GetEXP());

}
