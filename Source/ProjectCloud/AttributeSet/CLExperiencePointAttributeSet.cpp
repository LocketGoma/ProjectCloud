// Fill out your copyright notice in the Description page of Project Settings.


#include "CLExperiencePointAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"

static const float MinimumValue = 0.f;

UCLExperiencePointAttributeSet::UCLExperiencePointAttributeSet()
{
}

bool UCLExperiencePointAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	// Save the current Experience
	EXPBeforeAttributeChange = GetEXP();
	//MaxEXPBeforeAttributeChange = GetMaxEXP();

	return true;
}

void UCLExperiencePointAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	const FGameplayEffectContextHandle& EffectContext = Data.EffectSpec.GetEffectContext();
	AActor* Instigator = EffectContext.GetOriginalInstigator();

	if (Data.EvaluatedData.Attribute == GetEarnEXPAttribute())
	{
		if (GetEarnEXP() >= 0)
		{
			SetEXPCurrentValue(GetEXP() + GetEarnEXP());
		}
		else
		{
			//(아직은) 경험치가 음수면 안됨...
			checkNoEntry();
		}
	}

	OnEXPChanged.Broadcast(Instigator, Data.EvaluatedData.Magnitude, EXPBeforeAttributeChange, GetEXP());

	SetEarnEXPCurrentValue(0);
}
