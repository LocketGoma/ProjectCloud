// Fill out your copyright notice in the Description page of Project Settings.


#include "CLEarnEXPtExecutionCalculation.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"


UCLEarnEXPtExecutionCalculation::UCLEarnEXPtExecutionCalculation()
{
	RelevantAttributesToCapture.Add(FPlayerExperienceEarning::Get().ExpDef);
}

void UCLEarnEXPtExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	FGameplayEffectContext* TypedContext = ExecutionParams.GetOwningSpec().GetContext().Get();

	float EarnExperience = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(FPlayerExperienceEarning::Get().ExpDef, FAggregatorEvaluateParameters(), EarnExperience);

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UCLExperiencePointAttributeSet::GetEarnEXPAttribute(), EGameplayModOp::Override, EarnExperience));
}
