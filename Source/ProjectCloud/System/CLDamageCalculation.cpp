// Fill out your copyright notice in the Description page of Project Settings.


#include "CLDamageCalculation.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"

UCLDamageCalculation::UCLDamageCalculation()
{
	RelevantAttributesToCapture.Add(FPlayerDamageStatics::Get().HealthDef);
	RelevantAttributesToCapture.Add(FPlayerDamageStatics::Get().DamageDef);
}

void UCLDamageCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
    float Health = 0.0f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(FPlayerDamageStatics::Get().HealthDef, FAggregatorEvaluateParameters(), Health);

    float AttackPower = 0.0f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(FPlayerDamageStatics::Get().DamageDef, FAggregatorEvaluateParameters(), AttackPower);


    //대미지 계산
    //float Damage = AttackPower - Health;
    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(FPlayerDamageStatics::Get().HealthDef.AttributeToCapture, EGameplayModOp::Additive, -AttackPower));
}
