// Fill out your copyright notice in the Description page of Project Settings.


#include "CLDamageCalculation.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "GameplayEffect.h"

UCLDamageCalculation::UCLDamageCalculation()
{
	RelevantAttributesToCapture.Add(FPlayerDamageStatics::Get().HealthDef);
	RelevantAttributesToCapture.Add(FPlayerDamageStatics::Get().DamageDef);
}

void UCLDamageCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
    //float Health = 0.0f;
    float Damage = 0.0f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(FPlayerDamageStatics::Get().HealthDef, FAggregatorEvaluateParameters(), Damage);

    //float AttackPower = 0.0f;
    //ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(FPlayerDamageStatics::Get().DamageDef, FAggregatorEvaluateParameters(), AttackPower);


    ACLBaseCharacter* TargetCharacter = Cast<ACLBaseCharacter>(ExecutionParams.GetTargetAbilitySystemComponent()->GetOwnerActor());
    float CurrentHealth = TargetCharacter->GetHealth();

    //대미지 계산
    //float Damage = AttackPower - Health;

    //좀 이상한데...

    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(FPlayerDamageStatics::Get().HealthDef.AttributeToCapture, EGameplayModOp::Additive, CurrentHealth - Damage));
}
