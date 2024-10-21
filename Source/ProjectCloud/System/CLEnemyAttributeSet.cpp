// Fill out your copyright notice in the Description page of Project Settings.

#include "CLEnemyAttributeSet.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "GameplayEffectExtension.h"

void UCLEnemyAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);


    if (Data.EvaluatedData.Attribute == GetDamageAttribute())
    {
        Health.SetCurrentValue(Health.GetCurrentValue() - Damage.GetCurrentValue());
    }

    //체력 직접 업데이트
    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        //Do Something..
    }

    ACLBaseCharacter* Character = Cast<ACLBaseCharacter>(GetOwningActor());
    if (Character && Health.GetCurrentValue() <= 0.0f)
    {
        Character->DeathEvent(); // 캐릭터의 죽음 처리 함수 호출
    }
}
