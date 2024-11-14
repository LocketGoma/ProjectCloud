// Fill out your copyright notice in the Description page of Project Settings.


#include "CLCharacterAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"

UCLCharacterAttributeSet::UCLCharacterAttributeSet()
    : Health(100.f)
    , MaxHealth(100.f)
{
    bOutOfHealth = false;
    MaxHealthBeforeAttributeChange = 0.0f;
    HealthBeforeAttributeChange = 0.0f;
}

bool UCLCharacterAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
    if (!Super::PreGameplayEffectExecute(Data))
        return false;

    ACLBaseCharacter* Character = Cast<ACLBaseCharacter>(GetOwningActor());
    if (!ensure(Character))
    {
        return false;
    }

    //무적 상태면 피격 X
    if (Character->IsImmunity() || Data.Target.HasMatchingGameplayTag(TAG_Event_Status_DamageImmunity))
    {
        Data.EvaluatedData.Magnitude = 0.0f;
        Damage.SetCurrentValue(0.f);

        return false;
    }

    // Save the current health
    HealthBeforeAttributeChange = GetHealth();
    MaxHealthBeforeAttributeChange = GetMaxHealth();

    return true;
}

void UCLCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);
    const FGameplayEffectContextHandle& EffectContext = Data.EffectSpec.GetEffectContext();
    AActor* Instigator = EffectContext.GetOriginalInstigator();
    AActor* Causer = EffectContext.GetEffectCauser();


    ACLBaseCharacter* Character = Cast<ACLBaseCharacter>(GetOwningActor());

    if (!ensure(Character))
    {
        return;
    }    

    //체력 관련

    //대미지 입을때
    if (Data.EvaluatedData.Attribute == GetDamageAttribute())
    {        
        SetHealthCurrentValue(FMath::Clamp(GetHealth()- GetDamage(), ATTRIBUTE_MINVALUE, GetMaxHealth()));
        SetDamageToTarget(0.0f, Character);
    }
    //체력 직접 업데이트
    else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {   
        SetHealthCurrentValue(FMath::Clamp(GetHealth(), ATTRIBUTE_MINVALUE, GetMaxHealth()));
    }
    //체력 회복 업데이트
    else if (Data.EvaluatedData.Attribute == GetHealingAttribute())
    {
        SetHealthCurrentValue(FMath::Clamp(GetHealth()+GetHealing(), ATTRIBUTE_MINVALUE, GetMaxHealth()));
        SetHealingToTarget(0.f, Character);
    }
    //최대 체력 업데이트
    else if (Data.EvaluatedData.Attribute == GetMaxHealthAttribute())
    {
        OnMaxHealthChanged.Broadcast(Instigator, Causer, &Data.EffectSpec, Data.EvaluatedData.Magnitude, MaxHealthBeforeAttributeChange, GetMaxHealth());
    }

    if (GetHealth() != HealthBeforeAttributeChange)
    {
        OnHealthChanged.Broadcast(Instigator, Causer, &Data.EffectSpec, Data.EvaluatedData.Magnitude, HealthBeforeAttributeChange, GetHealth());
    }

    if (GetHealth() <= 0.0f)
    {
        OnOutOfHealth.Broadcast(Instigator, Causer, &Data.EffectSpec, Data.EvaluatedData.Magnitude, HealthBeforeAttributeChange, GetHealth());
    }
}