// Fill out your copyright notice in the Description page of Project Settings.

#include "CLCharacterAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "ProjectCloud/Character/CLPlayerState.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"

UCLCharacterAttributeSet::UCLCharacterAttributeSet()
    : Health(0.f)
    , MaxHealth(0.f)
{
    bOutOfHealth = false;
    MaxHealthBeforeAttributeChange = 0.0f;
    HealthBeforeAttributeChange = 0.0f;
}

bool UCLCharacterAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
    if (!Super::PreGameplayEffectExecute(Data))
        return false;

    ACLBaseCharacter* Character = nullptr;
    //1. 플레이어인 경우 (플레이어는 PS에 정보 있음)
    if (ACLPlayerState* PS = Cast<ACLPlayerState>(GetOwningActor()))
    {
        Character = Cast<ACLBaseCharacter>(PS->GetPawn());
    }
    //2. 그 외 캐릭터인 경우 (캐릭터에 ASC 있음)
    else
    {
        Character = Cast<ACLBaseCharacter>(GetOwningActor());
    }
    
    //여기는 터트리는게 맞음
    if (!ensure(Character))
    {
        return false;
    }

    //무적 상태면 피격 X
    if ((Data.EvaluatedData.Attribute == GetDamageAttribute()) && (Character->IsImmunity() || Data.Target.HasMatchingGameplayTag(TAG_Event_Status_DamageImmunity)))
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

    ACLBaseCharacter* Character = nullptr;
    //1. 플레이어인 경우 (플레이어는 PS에 정보 있음)
    if (ACLPlayerState* PS = Cast<ACLPlayerState>(GetOwningActor()))
    {
        Character = Cast<ACLBaseCharacter>(PS->GetPawn());
    }
    //2. 그 외 캐릭터인 경우 (캐릭터에 ASC 있음)
    else
    {
        Character = Cast<ACLBaseCharacter>(GetOwningActor());
    }

    if (!ensure(Character))
    {
        return;
    }    

    //체력 관련

    //대미지 입을때
    if (Data.EvaluatedData.Attribute == GetDamageAttribute())
    {
        float NowDamage = GetDamage();
        float ChangeValue = FMath::Clamp(GetHealth() - GetDamage(), ATTRIBUTE_MINVALUE, GetMaxHealth());

        SetHealthCurrentValue(FMath::Clamp(GetHealth() - GetDamage(), ATTRIBUTE_MINVALUE, GetMaxHealth()));
        SetDamageToTarget(0.0f, Character);
    }
    //체력 직접 업데이트
    else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {   
        if (GetHealth() > GetMaxHealth())
        {
            SetMaxHealth(GetHealth());
        }

        SetHealthCurrentValue(FMath::Clamp(GetHealth(), ATTRIBUTE_MINVALUE, GetMaxHealth()));
    }
    //체력 회복 업데이트
    else if (Data.EvaluatedData.Attribute == GetHealingAttribute())
    {
        SetHealthCurrentValue(FMath::Clamp(GetHealth() + GetHealing(), ATTRIBUTE_MINVALUE, GetMaxHealth()));
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

    if (GetHealth() <= 0.f)
    {
        OnOutOfHealth.Broadcast(Instigator, Causer, &Data.EffectSpec, Data.EvaluatedData.Magnitude, HealthBeforeAttributeChange, GetHealth());
    }
}