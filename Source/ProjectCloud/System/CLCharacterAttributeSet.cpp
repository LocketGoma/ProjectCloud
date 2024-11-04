// Fill out your copyright notice in the Description page of Project Settings.


#include "CLCharacterAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"


FGameplayAttribute UCLCharacterAttributeSet::GetHealthAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UCLCharacterAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UCLCharacterAttributeSet, Health));

	return FGameplayAttribute(Property);
}

FGameplayAttribute UCLCharacterAttributeSet::GetManaAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UCLCharacterAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UCLCharacterAttributeSet, Mana));

	return FGameplayAttribute(Property);
}

float UCLCharacterAttributeSet::GetHealth() const
{
	return Health.GetCurrentValue();
}

void UCLCharacterAttributeSet::SetHealth(float NewHealth)
{
	Health.SetCurrentValue(NewHealth);
}

float UCLCharacterAttributeSet::GetMana() const
{
	return Mana.GetCurrentValue();
}

void UCLCharacterAttributeSet::SetMana(float NewMana)
{
	Mana.SetCurrentValue(NewMana);
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
    Character->SetImmunity(true);
    return true;
}

void UCLCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);
    ACLBaseCharacter* Character = Cast<ACLBaseCharacter>(GetOwningActor());
    if (!ensure(Character))
    {
        return;
    }

    float ChangedHealth = 0.f;
    //대미지 입을때
    if (Data.EvaluatedData.Attribute == GetDamageAttribute())
    {
        ChangedHealth = -Damage.GetCurrentValue();
        Damage.SetCurrentValue(0.f);
    }

    //체력 직접 업데이트 (체력 회복시)
    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        //Do Something..
    }

    Health.SetCurrentValue(Health.GetCurrentValue() + ChangedHealth);
    Character->UpdateHealthEvent(ChangedHealth);

    //if(Health.GetCurrentValue() <= 0.0f)
    //    Character->DeathEvent(); // 캐릭터의 죽음 처리 함수 호출


}