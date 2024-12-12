// Copyright @Locketgoma. All Rights Reserved.


#include "CLEarnEXPExecutionCalculation.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"


UCLEarnEXPExecutionCalculation::UCLEarnEXPExecutionCalculation()
{
	RelevantAttributesToCapture.Add(FPlayerExperienceEarning::Get().ExpDef);
}

void UCLEarnEXPExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	FGameplayEffectContext* TypedContext = ExecutionParams.GetOwningSpec().GetContext().Get();

	float EarnExperience = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(FPlayerExperienceEarning::Get().ExpDef, FAggregatorEvaluateParameters(), EarnExperience);

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UCLExperiencePointAttributeSet::GetEarnEXPAttribute(), EGameplayModOp::Override, EarnExperience));
}
