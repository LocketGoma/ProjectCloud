// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "ProjectCloud/System/CLEnemyAttributeSet.h"
#include "ProjectCloud/System/CLWeaponAttributeSet.h"
#include "CLDamageCalculation.generated.h"

//여기는 플레이어 -> 몬스터 상대인것만 제작하기

USTRUCT()
struct PROJECTCLOUD_API FPlayerDamageStatics
{
	GENERATED_BODY();


	FPlayerDamageStatics()
	{
		DamageDef = FGameplayEffectAttributeCaptureDefinition(UCLEnemyAttributeSet::GetDamageAttribute(), EGameplayEffectAttributeCaptureSource::Source, true);
	}
	FGameplayEffectAttributeCaptureDefinition DamageDef;

	static const FPlayerDamageStatics& Get()
	{
		static FPlayerDamageStatics Instance;
		return Instance;
	}
};

UCLASS()
class PROJECTCLOUD_API UCLDamageCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UCLDamageCalculation();
	
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
