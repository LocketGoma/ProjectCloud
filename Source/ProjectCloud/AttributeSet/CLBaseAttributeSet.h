// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AttributeSet.h"
#include "CLBaseAttributeSet.generated.h"

#define CLGAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	FORCEINLINE void Set##PropertyName##CurrentValue(float NewVal) \
	{ \
		PropertyName.SetCurrentValue(NewVal); \
	}

#define CLGAMEPLAYATTRIBUTE_VALUE_SETTER_TO_TARGET(PropertyName) \
	FORCEINLINE void Set##PropertyName##ToTarget(float NewVal, AActor* Actor) \
	{ \
		UAbilitySystemComponent* AbilityComp = GetOwningCLAbilitySystemComponent(Actor); \
		if (ensure(AbilityComp)) \
		{ \
			AbilityComp->SetNumericAttributeBase(Get##PropertyName##Attribute(), NewVal); \
		}; \
	}

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
CLGAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
CLGAMEPLAYATTRIBUTE_VALUE_SETTER_TO_TARGET(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

class UAbilitySystemComponent;

#define ATTRIBUTE_MINVALUE 0

UCLASS()
class PROJECTCLOUD_API UCLBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAbilitySystemComponent* GetOwningCLAbilitySystemComponent(AActor* Actor);

};
