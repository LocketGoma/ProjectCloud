// Copyright @Locketgoma. All Rights Reserved.

#include "CLAbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "ProjectCloud/Input/CLAbilityInputConfig.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"

bool UCLAbilitySystemComponent::BindInputActions(const UCLAbilityInputConfig* InputConfig, UEnhancedInputComponent* EnhancedInputComponent)
{
	if (!ensure(EnhancedInputComponent))
	{
		UE_LOG(LogCloudAbilitySystem, Error, TEXT("UCLAbilitySystemComponent :: EnhancedInputComponent is Null."));
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

bool UCLAbilitySystemComponent::AddGameplayTag(const FGameplayTag& InputTag, int Count)
{
	if (!GetOwner() || GetOwner()->IsActorBeingDestroyed())
	{
		return false;
	}

	AddLooseGameplayTag(InputTag, Count);

	return true;
}

bool UCLAbilitySystemComponent::RemoveGameplayTag(const FGameplayTag& InputTag, int Count)
{
	if (!GetOwner() || GetOwner()->IsActorBeingDestroyed())
	{
		return false;
	}

	RemoveLooseGameplayTag(InputTag, Count);

	return true;
}

bool UCLAbilitySystemComponent::ClearGameplayTag(const FGameplayTag& InputTag)
{
	if (!GetOwner() || GetOwner()->IsActorBeingDestroyed())
	{
		return false;
	}

	RemoveLooseGameplayTag(InputTag,GetGameplayTagCount(InputTag));

	return true;
}

bool UCLAbilitySystemComponent::UpdateGameplayTag(const FGameplayTag& InputTag, int Count)
{
	if (!GetOwner() || GetOwner()->IsActorBeingDestroyed())
	{
		return false;
	}

	UpdateGameplayTag(InputTag, Count);

	return true;
}

bool UCLAbilitySystemComponent::AddGameplayEffect(const TSubclassOf<UGameplayEffect> GameplayEffect)
{
	//특정 GameplayEffect에서 데이터 가져오는 방법
	if (IsValid(GameplayEffect))
	{
		FGameplayEffectContextHandle EffectContext = MakeEffectContext();
		FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(GameplayEffect, 1.0f, EffectContext);

		if (SpecHandle.IsValid())
		{
			FGameplayEffectSpec* Spec = SpecHandle.Data.Get();

			FActiveGameplayEffectHandle EffectHandle = ApplyGameplayEffectSpecToSelf(*Spec);			

			if (!EffectHandle.IsValid())
			{
				UE_LOG(LogCloudAbilitySystem, Warning, TEXT("Try AddGameplayEffect But Adding %s Effect has failure in %s."), *(GameplayEffect.Get()->GetName(), *GetOwnerActor()->GetName()));
				return false;
			}

			//즉발성 Policy면 저장안함.
			if (GameplayEffect.GetDefaultObject()->DurationPolicy != EGameplayEffectDurationType::Instant)
			{
				ActiveGameplayEffectHandle.Add(EffectHandle);
			}

			return true;
		}
	}

	return false;
}

bool UCLAbilitySystemComponent::RemoveGameplayEffect(const TSubclassOf<UGameplayEffect> GameplayEffect)
{
	if (IsValid(GameplayEffect))
	{
		for (FActiveGameplayEffectHandle EffectHandle : ActiveGameplayEffectHandle)
		{
			if (GetGameplayEffectDefForHandle(EffectHandle) == GameplayEffect.GetDefaultObject())
			{
				RemoveActiveGameplayEffect(EffectHandle);
				return true;
			}
		}
		UE_LOG(LogCloudAbilitySystem, Warning, TEXT("Try RemoveGameplayEffect But %s has not %s Effect."), *GetOwnerActor()->GetName(), *(GameplayEffect.Get()->GetName()));
	}
	return false;
}
