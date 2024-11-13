// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayEffectExecutionCalculation.h"
#include "ProjectCloud/AttributeSet/CLExperiencePointAttributeSet.h"
#include "CLEarnEXPtExecutionCalculation.generated.h"

/**
 * 경험치 획득 처리 계산 이벤트
 */

USTRUCT()
struct PROJECTCLOUD_API FPlayerExperienceEarning
{
	GENERATED_BODY();


	FPlayerExperienceEarning()
	{
		ExpDef = FGameplayEffectAttributeCaptureDefinition(UCLExperiencePointAttributeSet::GetEarnEXPAttribute(), EGameplayEffectAttributeCaptureSource::Source, true);
	}
	FGameplayEffectAttributeCaptureDefinition ExpDef;

	static const FPlayerExperienceEarning& Get()
	{
		static FPlayerExperienceEarning Instance;
		return Instance;
	}
};

UCLASS()
class PROJECTCLOUD_API UCLEarnEXPtExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UCLEarnEXPtExecutionCalculation();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
