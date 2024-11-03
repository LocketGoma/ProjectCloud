// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectCloud/System/CLBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CLCharacterAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTCLOUD_API UCLCharacterAttributeSet : public UCLBaseAttributeSet
{
	GENERATED_BODY()
	
public:
	UCLCharacterAttributeSet();
	
	FGameplayAttribute GetHealthAttribute();
	FGameplayAttribute GetManaAttribute();

	float GetHealth() const;
	void SetHealth(float NewHealth);

	float GetMana() const;
	void SetMana(float NewMana);

private:
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Mana;
	//피격 대미지 처리용
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Damage;

	friend class UCLHittedDamageCalculation;

public:
	ATTRIBUTE_ACCESSORS(UCLCharacterAttributeSet, Damage)
};
