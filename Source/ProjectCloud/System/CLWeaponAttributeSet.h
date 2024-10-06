// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectCloud/System/CLBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CLWeaponAttributeSet.generated.h"

/**
 * 
 */

UCLASS()
class PROJECTCLOUD_API UCLWeaponAttributeSet : public UCLBaseAttributeSet
{
	GENERATED_BODY()
	
public:
	UCLWeaponAttributeSet();

	FGameplayAttribute ManaCostAttribute();
	FGameplayAttribute DamageAttribute();
	FGameplayAttribute AmmoAttribute();

	float GetManaCost() const;
	void SetManaCost(float NewCost);

	float GetDamage() const;
	void SetDamage(float NewDamage);

	float GetAmmo() const;
	void SetAmmo(float NewAmmo);

	float GetMaxAmmo() const;
	void SetMaxAmmo(float NewMaxAmmo);


private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData ManaCost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Ammo;

	
	//쿨다운 자동 추가 설정시
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	//FGameplayAttributeData Cooldown;

	friend class UCLDamageCalculation;
	friend struct FPlayerDamageStatics;
};
