// Fill out your copyright notice in the Description page of Project Settings.


#include "CLCharacterAttributeSet.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "GameplayEffectExtension.h"

UCLCharacterAttributeSet::UCLCharacterAttributeSet()
{
	Health = 100.f;
	Mana = 100.f;
}

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

void UCLCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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
    if (Character)
    {
        Character->UpdateHealthEvent();

        if(Health.GetCurrentValue() <= 0.0f)
            Character->DeathEvent(); // 캐릭터의 죽음 처리 함수 호출
    }
}
