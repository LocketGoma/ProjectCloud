// Copyright @Locketgoma. All Rights Reserved.

#pragma once

#include "GameplayEffectExecutionCalculation.h"
#include "ProjectCloud/AttributeSet/CLManaAttributeSet.h"
#include "CLManaChangeExecutionCalculation.generated.h"

/**
 * 마나 획득 처리 계산 이벤트
 */

USTRUCT()
struct PROJECTCLOUD_API FPlayerManaEarning
{
	GENERATED_BODY();

	FPlayerManaEarning()
	{
		ManaDef = FGameplayEffectAttributeCaptureDefinition(UCLManaAttributeSet::GetChangeManaAmountAttribute(), EGameplayEffectAttributeCaptureSource::Source, true);
	}
	FGameplayEffectAttributeCaptureDefinition ManaDef;

	static const FPlayerManaEarning& Get()
	{
		static FPlayerManaEarning Instance;
		return Instance;
	}
};

UCLASS()
class PROJECTCLOUD_API UCLManaChangeExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	UCLManaChangeExecutionCalculation();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

};
