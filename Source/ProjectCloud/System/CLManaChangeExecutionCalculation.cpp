// Fill out your copyright notice in the Description page of Project Settings.

#include "CLManaChangeExecutionCalculation.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/AttributeSet/CLManaAttributeSet.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"

UCLManaChangeExecutionCalculation::UCLManaChangeExecutionCalculation()
{
	RelevantAttributesToCapture.Add(FPlayerManaEarning::Get().ManaDef);
}

void UCLManaChangeExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	FGameplayEffectContext* TypedContext = ExecutionParams.GetOwningSpec().GetContext().Get();

	float EarnManaAmount = ATTRIBUTE_MINVALUE;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(FPlayerManaEarning::Get().ManaDef, FAggregatorEvaluateParameters(), EarnManaAmount);
	
	if (!ensure(!FMath::IsNearlyEqual(ATTRIBUTE_FAILUREVALUE, EarnManaAmount)))
	{
		UE_LOG(LogCloudAbilitySystem, Warning, TEXT("Mana Value must not [ ATTRIBUTE_FAILUREVALUE(0xFFFF) ], if you must use this value, call Engineers. this execution is now check failure."));
		return;
	}

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UCLManaAttributeSet::GetChangeManaAmountAttribute(), EGameplayModOp::Override, EarnManaAmount));
}
