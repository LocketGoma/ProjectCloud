// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CLBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CLCharacterAttributeSet.generated.h"

/**
 * 
 */
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGameplayAttributeValueChanged, const FGameplayAttribute&, Attribute, float, OldValue, float, NewValue);

DECLARE_MULTICAST_DELEGATE_SixParams(FOnHealthAttributeValueChanged, AActor* /*EffectInstigator*/, AActor* /*EffectCauser*/, const FGameplayEffectSpec* /*EffectSpec*/, float /*EffectMagnitude*/, float /*OldValue*/, float /*NewValue*/);

UCLASS()
class PROJECTCLOUD_API UCLCharacterAttributeSet : public UCLBaseAttributeSet
{
	GENERATED_BODY()	

public:
	UCLCharacterAttributeSet();

	//Lyra에서는 Healing도 추가해놨음.
	ATTRIBUTE_ACCESSORS(UCLCharacterAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UCLCharacterAttributeSet, MaxHealth);

	ATTRIBUTE_ACCESSORS(UCLCharacterAttributeSet, Healing);	
	ATTRIBUTE_ACCESSORS(UCLCharacterAttributeSet, Damage);

	mutable FOnHealthAttributeValueChanged OnHealthChanged;
	mutable FOnHealthAttributeValueChanged OnMaxHealthChanged;
	mutable FOnHealthAttributeValueChanged OnOutOfHealth;
		
protected:
	virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

private:
	// Store the health before any changes 
	float MaxHealthBeforeAttributeChange;
	float HealthBeforeAttributeChange;

	bool bOutOfHealth;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes|Health", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes|Health", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData MaxHealth;
		

	//회복 처리용 변수. 에디터상에서 수정 X
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|UpdateAttribute", Meta = (HideFromModifiers, AllowPrivateAccess = true))
	FGameplayAttributeData Healing;
	
	//피격 대미지 처리용 변수. 에디터상에서 수정 X
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|UpdateAttribute", Meta = (HideFromModifiers, AllowPrivateAccess = true))
	FGameplayAttributeData Damage;	
};
