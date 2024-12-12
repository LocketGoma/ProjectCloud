// Fill out your copyright notice in the Description page of Project Settings.


#include "CLManaChangeExecutionCalculation.h"

UCLManaChangeExecutionCalculation::UCLManaChangeExecutionCalculation()
{
	RelevantAttributesToCapture.Add(FPlayerManaEarning::Get().ManaDef);
}

void UCLManaChangeExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	FGameplayEffectContext* TypedContext = ExecutionParams.GetOwningSpec().GetContext().Get();

	float EarnManaAmount = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(FPlayerManaEarning::Get().ManaDef, FAggregatorEvaluateParameters(), EarnManaAmount);

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UCLManaAttributeSet::GetChangeManaAmountAttribute(), EGameplayModOp::Override, EarnManaAmount));
}
