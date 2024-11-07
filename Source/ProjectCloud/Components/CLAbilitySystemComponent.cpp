// Copyright @Locketgoma. All Rights Reserved.

#include "CLAbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "ProjectCloud/Input/CLAbilityInputConfig.h"

bool UCLAbilitySystemComponent::BindInputActions(const UCLAbilityInputConfig* InputConfig, UEnhancedInputComponent* EnhancedInputComponent)
{
	if (!ensure(EnhancedInputComponent))
	{
		UE_LOG(LogTemp, Error, TEXT("UCLAbilitySystemComponent :: EnhancedInputComponent is Null."));
		return false;
	}

	for (const FCloudInputAction Action : InputConfig->AbilityInputActions)
	{
		InputactionList.Add(Action.InputAction, Action.InputTag);

		EnhancedInputComponent->BindAction(Action.InputAction, ETriggerEvent::Triggered, this, &UCLAbilitySystemComponent::TryActiveAbilityFromInputAction);
	}
	return true;
}

void UCLAbilitySystemComponent::TryActiveAbilityFromInputAction(const FInputActionInstance& Value)
{
	FGameplayTag* InputTag = InputactionList.Find(Value.GetSourceAction());
	
	if (InputTag != nullptr)
	{
		FGameplayEventData TempPayload;
		TempPayload.EventTag = *InputTag;
		TempPayload.Instigator = GetOwner();
		HandleGameplayEvent(TempPayload.EventTag, &TempPayload);
	}
}

void UCLAbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag& InputTag)
{
	if (InputTag.IsValid())
	{
		for (const FGameplayAbilitySpec& AbilitySpec : ActivatableAbilities.Items)
		{
			if (AbilitySpec.Ability && (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)))
			{
				InputPressedSpecHandles.AddUnique(AbilitySpec.Handle);
				InputHeldSpecHandles.AddUnique(AbilitySpec.Handle);
			}
		}
	}
}

void UCLAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (InputTag.IsValid())
	{
		for (const FGameplayAbilitySpec& AbilitySpec : ActivatableAbilities.Items)
		{
			if (AbilitySpec.Ability && (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)))
			{
				InputReleasedSpecHandles.AddUnique(AbilitySpec.Handle);
				InputHeldSpecHandles.Remove(AbilitySpec.Handle);
			}
		}
	}
}
