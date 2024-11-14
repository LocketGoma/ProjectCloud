// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CLBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CLExperiencePointAttributeSet.generated.h"


DECLARE_MULTICAST_DELEGATE_FourParams(FOnExprienceAttributeValueChanged, AActor* /*EffectInstigator*/, float /*EffectMagnitude*/, float /*OldValue*/, float /*NewValue*/);

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
	ATTRIBUTE_ACCESSORS(UCLExperiencePointAttributeSet, EarnEXP);

	//XP를 얻은 경우
	mutable FOnExprienceAttributeValueChanged OnEXPChanged;



protected:
	virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

private:
	// Store the EXP before any changes 
	int64 EXPBeforeAttributeChange;		
	
/*
* Note : 만일 경험치 크기가 10억 이상이 되면 float 타입이 아닌 int32 혹은 int64로 값을 교체하는것을 권장함.
* ...근데 넘길일은 없을거같은데
* 
*/
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes|EXP", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData EXP;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|UpdateAttribute", Meta = (HideFromModifiers, AllowPrivateAccess = true))
	FGameplayAttributeData EarnEXP;
};
