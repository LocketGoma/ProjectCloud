// Copyright @Locketgoma. All Rights Reserved.

#pragma once

#include "GameplayEffectExecutionCalculation.h"
#include "ProjectCloud/AttributeSet/CLExperiencePointAttributeSet.h"
#include "CLEarnEXPExecutionCalculation.generated.h"

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
class PROJECTCLOUD_API UCLEarnEXPExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UCLEarnEXPExecutionCalculation();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
