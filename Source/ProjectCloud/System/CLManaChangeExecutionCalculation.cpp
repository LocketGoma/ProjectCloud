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

	float Chance = ExecutionParams.GetOwningSpec().GetChanceToApplyToTarget();	

	//항상 발동되는것이 아니라면 마나 량 체크 후 사용 여부 체크 (항상 발동 or 마나 충전량이 음수일때)
	if ((ATTRIBUTE_ONEVALUE > ExecutionParams.GetOwningSpec().GetChanceToApplyToTarget()) && (ATTRIBUTE_MINVALUE > EarnManaAmount))
	{
		UAbilitySystemComponent* ASC = TypedContext->GetInstigatorAbilitySystemComponent();
		if (!ASC)
			return;

		const UCLManaAttributeSet* AttributeSet = ASC->GetSet<UCLManaAttributeSet>();
		if (!AttributeSet)
			return;

		if (EarnManaAmount > (AttributeSet->GetMana()))
		{
			OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UCLManaAttributeSet::GetChangeManaAmountAttribute(), EGameplayModOp::Override, ATTRIBUTE_FAILUREVALUE));
			
			return;
		}
	}

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UCLManaAttributeSet::GetChangeManaAmountAttribute(), EGameplayModOp::Override, EarnManaAmount));
}
