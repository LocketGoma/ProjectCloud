// Fill out your copyright notice in the Description page of Project Settings.


#include "CLHittedDamageCalculation.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "GameplayEffect.h"

UCLHittedDamageCalculation::UCLHittedDamageCalculation()
{
	RelevantAttributesToCapture.Add(FEnemyDamageStatics::Get().DamageDef);
}

void UCLHittedDamageCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
    float Damage = 0.0f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(FEnemyDamageStatics::Get().DamageDef, FAggregatorEvaluateParameters(), Damage);

    //아래 함수만 사용하면 Base와 Current가 동시에 업데이트되는 문제가 있다고 함.
    //아니 Lyra놈들 Damage를 따로 받아서 이걸 AttributeSet에서 연산을 다시 시켰네??????
    
    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(FEnemyDamageStatics::Get().DamageDef.AttributeToCapture, EGameplayModOp::Override, Damage));

    


}
