// Fill out your copyright notice in the Description page of Project Settings.


#include "CLWeaponAttributeSet.h"
#include "UObject/UObjectGlobals.h"


UCLWeaponAttributeSet::UCLWeaponAttributeSet()
{
	Damage = 10.f;
	ManaCost = 0.f;
	Ammo = 0.f;
}

FGameplayAttribute UCLWeaponAttributeSet::ManaCostAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UCLWeaponAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UCLWeaponAttributeSet, ManaCost));

	return FGameplayAttribute(Property);
}

FGameplayAttribute UCLWeaponAttributeSet::DamageAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UCLWeaponAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UCLWeaponAttributeSet, Damage));

	return FGameplayAttribute(Property);
}

FGameplayAttribute UCLWeaponAttributeSet::AmmoAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UCLWeaponAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UCLWeaponAttributeSet, Ammo));

	return FGameplayAttribute(Property);
}

float UCLWeaponAttributeSet::GetManaCost() const
{
	return ManaCost.GetCurrentValue();
}

void UCLWeaponAttributeSet::SetManaCost(float NewCost)
{
	ManaCost.SetCurrentValue(NewCost);
}

float UCLWeaponAttributeSet::GetDamage() const
{
	return Damage.GetCurrentValue();
}

void UCLWeaponAttributeSet::SetDamage(float NewDamage)
{
	Damage.SetCurrentValue(NewDamage);
}

float UCLWeaponAttributeSet::GetMaxAmmo() const
{
	return Ammo.GetBaseValue();
}

void UCLWeaponAttributeSet::SetMaxAmmo(float NewAmmo)
{
	Ammo.SetBaseValue(NewAmmo);
}

