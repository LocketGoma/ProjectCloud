// Fill out your copyright notice in the Description page of Project Settings.


#include "CLHittedDamageCalculation.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/System/CLCharacterAttributeSet.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "GameplayEffect.h"

UCLHittedDamageCalculation::UCLHittedDamageCalculation()
{
	RelevantAttributesToCapture.Add(FEnemyDamageStatics::Get().DamageDef);
}

void UCLHittedDamageCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
    float Damage = 0.0f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(FEnemyDamageStatics::Get().DamageDef, FAggregatorEvaluateParameters(), Damage);

    UCLAbilitySystemComponent* SourceASC = Cast<UCLAbilitySystemComponent>(ExecutionParams.GetSourceAbilitySystemComponent());
    UCLAbilitySystemComponent* TargetASC = Cast<UCLAbilitySystemComponent>(ExecutionParams.GetTargetAbilitySystemComponent());



    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UCLCharacterAttributeSet::GetDamageAttribute(), EGameplayModOp::Override, Damage));

    //캡쳐된 어트리뷰트에 바로 수치넣을때 ->
    //OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(FEnemyDamageStatics::Get().DamageDef.AttributeToCapture, EGameplayModOp::Override, Damage));
}
