// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CLBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CLExperiencePointAttributeSet.generated.h"


DECLARE_MULTICAST_DELEGATE_SixParams(FOnExprienceAttributeValueChanged, AActor* /*EffectInstigator*/, AActor* /*EffectCauser*/, const FGameplayEffectSpec* /*EffectSpec*/, float /*EffectMagnitude*/, float /*OldValue*/, float /*NewValue*/);

/**
 * 
 */
UCLASS()
class PROJECTCLOUD_API UCLExperiencePointAttributeSet : public UCLBaseAttributeSet
{
	GENERATED_BODY()

public:
	UCLExperiencePointAttributeSet();

	ATTRIBUTE_ACCESSORS(UCLExperiencePointAttributeSet, EXP);
	ATTRIBUTE_ACCESSORS(UCLExperiencePointAttributeSet, MaxEXP);
	ATTRIBUTE_ACCESSORS(UCLExperiencePointAttributeSet, ExpAdding);

	mutable FOnExprienceAttributeValueChanged OnEXPChanged;
	mutable FOnExprienceAttributeValueChanged OnMaxEXPChanged;

protected:
	virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

private:
	// Store the EXP before any changes 
	float MaxEXPBeforeAttributeChange;
	float EXPBeforeAttributeChange;

	bool bMaxExperienceEarned;
	

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes|EXP", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData EXP;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes|EXP", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData MaxEXP;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|UpdateAttribute", Meta = (HideFromModifiers, AllowPrivateAccess = true))
	FGameplayAttributeData ExpAdding;
};
