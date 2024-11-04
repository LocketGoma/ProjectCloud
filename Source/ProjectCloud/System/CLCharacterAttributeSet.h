// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectCloud/System/CLBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CLCharacterAttributeSet.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGameplayAttributeValueChanged, const FGameplayAttribute&, Attribute, float, OldValue, float, NewValue);


UCLASS()
class PROJECTCLOUD_API UCLCharacterAttributeSet : public UCLBaseAttributeSet
{
	GENERATED_BODY()	

public:
	ATTRIBUTE_ACCESSORS(UCLCharacterAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UCLCharacterAttributeSet, Mana)
	ATTRIBUTE_ACCESSORS(UCLCharacterAttributeSet, Damage)

protected:
	virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Mana;

	//피격 대미지 처리용 변수. 에디터상에서 수정 X
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Damage;

	friend class UCLHittedDamageCalculation;
};
