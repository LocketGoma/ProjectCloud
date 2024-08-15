// Fill out your copyright notice in the Description page of Project Settings.


#include "CLAbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "ProjectCloud/System/CLAbilityinputconfig.h"

bool UCLAbilitySystemComponent::BindInputActions(const UCLAbilityInputConfig* InputConfig, UEnhancedInputComponent* EnhancedInputComponent)
{
	if (!ensure(EnhancedInputComponent))
	{
		UE_LOG(LogTemp, Error, TEXT("UCLAbilitySystemComponent :: EnhancedInputComponent is Null."));
		return false;
	}

	for (const FCLInputAction Action : InputConfig->AbilityInputActions)
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
