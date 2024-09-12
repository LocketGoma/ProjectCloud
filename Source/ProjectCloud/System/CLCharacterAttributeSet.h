// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectCloud/System/CLBaseAttributeSet.h"
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
	
	FGameplayAttribute HealthAttribute();
	FGameplayAttribute ManaAttribute();

	float GetHealth() const;
	void SetHealth(float NewHealth);

	float GetMana() const;
	void SetMana(float NewMana);


private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Mana;
};
