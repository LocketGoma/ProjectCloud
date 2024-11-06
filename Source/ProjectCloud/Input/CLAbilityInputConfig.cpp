// Fill out your copyright notice in the Description page of Project Settings.

#include "CLAbilityInputConfig.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CLAbilityInputConfig)

UCLAbilityInputConfig::UCLAbilityInputConfig(const FObjectInitializer& ObjectInitializer)
{
}

const UInputAction* UCLAbilityInputConfig::FindNativeInputActionFromTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FCloudInputAction& Action : NativeInputActions)
	{
		if ((Action.InputAction) && (Action.InputTag == InputTag))
		{
			return Action.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find NativeInputAction from InputTag [%s] on InputConfig [%s]."), *InputTag.ToString(), *GetNameSafe(this));
	}


	return nullptr;
}

const UInputAction* UCLAbilityInputConfig::FindAbilityInputActionFromTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FCloudInputAction& Action : AbilityInputActions)
	{
		if ((Action.InputAction) && (Action.InputTag == InputTag))
		{
			return Action.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find AbilityInputAction from InputTag [%s] on InputConfig [%s]."), *InputTag.ToString(), *GetNameSafe(this));
	}

	return nullptr;
}
