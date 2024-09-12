// Fill out your copyright notice in the Description page of Project Settings.


#include "CLCharacterAttributeSet.h"

UCLCharacterAttributeSet::UCLCharacterAttributeSet()
{
	Health = 100.f;
	Mana = 100.f;
}

FGameplayAttribute UCLCharacterAttributeSet::HealthAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UCLCharacterAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UCLCharacterAttributeSet, Health));

	return FGameplayAttribute(Property);
}

FGameplayAttribute UCLCharacterAttributeSet::ManaAttribute()
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
