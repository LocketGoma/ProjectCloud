// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CLBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CLManaAttributeSet.generated.h"

DECLARE_MULTICAST_DELEGATE_FourParams(FOnManaAttributeValueChanged, AActor* /*EffectInstigator*/, float /*EffectMagnitude*/, float /*OldValue*/, float /*NewValue*/);

UCLASS()
class PROJECTCLOUD_API UCLManaAttributeSet : public UCLBaseAttributeSet
{
	GENERATED_BODY()

public:
	UCLManaAttributeSet();

	ATTRIBUTE_ACCESSORS(UCLManaAttributeSet, Mana);
	ATTRIBUTE_ACCESSORS(UCLManaAttributeSet, MaxMana);
	ATTRIBUTE_ACCESSORS(UCLManaAttributeSet, ChangeManaAmount);

	mutable FOnManaAttributeValueChanged OnManaChanged;
	mutable FOnManaAttributeValueChanged OnManaAdded;
	mutable FOnManaAttributeValueChanged OnMaxManaChanged;
	mutable FOnManaAttributeValueChanged OnOutOfMana;

protected:
	virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

private:
	// Store the Mana before any changes 
	float MaxManaBeforeAttributeChange;
	float ManaBeforeAttributeChange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes|Mana", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Mana;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes|Mana", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData MaxMana;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|UpdateAttribute", Meta = (HideFromModifiers, AllowPrivateAccess = true))
	FGameplayAttributeData ChangeManaAmount;
};
