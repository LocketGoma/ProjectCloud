// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "ProjectCloud/AttributeSet/CLCharacterAttributeSet.h"
#include "CLHittedDamageCalculation.generated.h"

/// <summary>
/// 몬스터 -> 플레이어
/// </summary>
USTRUCT()
struct PROJECTCLOUD_API FEnemyDamageStatics
{
	GENERATED_BODY();


	FEnemyDamageStatics()
	{
		DamageDef = FGameplayEffectAttributeCaptureDefinition(UCLCharacterAttributeSet::GetDamageAttribute(), EGameplayEffectAttributeCaptureSource::Source, true);
	}
	FGameplayEffectAttributeCaptureDefinition DamageDef;

	static const FEnemyDamageStatics& Get()
	{
		static FEnemyDamageStatics Instance;
		return Instance;
	}
};

UCLASS()
class PROJECTCLOUD_API UCLHittedDamageCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	UCLHittedDamageCalculation();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

};
