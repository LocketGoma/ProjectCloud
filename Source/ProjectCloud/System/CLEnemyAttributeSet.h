// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectCloud/System/CLBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CLEnemyAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTCLOUD_API UCLEnemyAttributeSet : public UCLBaseAttributeSet
{
	GENERATED_BODY()


private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Damage;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	friend class UCLDamageCalculation;
	friend struct FPlayerDamageStatics;

public:
	ATTRIBUTE_ACCESSORS(UCLEnemyAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UCLEnemyAttributeSet, Damage)



};
