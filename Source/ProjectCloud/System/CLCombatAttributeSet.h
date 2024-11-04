// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectCloud/System/CLBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CLCombatAttributeSet.generated.h"

/**
 * 
 */

UCLASS()
class PROJECTCLOUD_API UCLCombatAttributeSet : public UCLBaseAttributeSet
{
	GENERATED_BODY()
	
public:
	ATTRIBUTE_ACCESSORS(UCLCombatAttributeSet, Mana)
	ATTRIBUTE_ACCESSORS(UCLCombatAttributeSet, Damage)
	ATTRIBUTE_ACCESSORS(UCLCombatAttributeSet, Health)

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Mana;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Health;


	friend class UCLDamageCalculation;
	friend struct FPlayerDamageStatics;
};
