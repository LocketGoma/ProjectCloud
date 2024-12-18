// Copyright @Locketgoma. All Rights Reserved.

#include "CLAbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "ProjectCloud/Input/CLAbilityInputConfig.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"

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
				InputHeldSpecHandles.AddUnique(AbilitySpec.Handle);
				InputPressedSpecHandles.AddUnique(AbilitySpec.Handle);

				OnInputPressed.Broadcast();
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

				//AbilitySpec.Ability.Get()->CancelAbility(AbilitySpec.Handle, AbilitySpec.Ability.Get()->GetCurrentActorInfo(), AbilitySpec.ActivationInfo, true);

				OnInputReleased.Broadcast();
			}
		}
	}
}

void UCLAbilitySystemComponent::ProcessAbilityInput(float DeltaTime, bool bGamePaused)
{
	if (HasMatchingGameplayTag(TAG_Gameplay_AbilityInputBlocked))
	{
		ClearAbilityInput();
		return;
	}

	static TArray<FGameplayAbilitySpecHandle> AbilitiesToActivate;
	AbilitiesToActivate.Reset();	

	//
	// Process all abilities that activate when the input is held.
	//
	
	//for (const FGameplayAbilitySpecHandle& SpecHandle : InputHeldSpecHandles)
	//{
	//	if (const FGameplayAbilitySpec* AbilitySpec = FindAbilitySpecFromHandle(SpecHandle))
	//	{
	//		if (AbilitySpec->Ability && !AbilitySpec->IsActive())
	//		{
	//			const ULyraGameplayAbility* LyraAbilityCDO = CastChecked<ULyraGameplayAbility>(AbilitySpec->Ability);
	//			if (LyraAbilityCDO->GetActivationPolicy() == ELyraAbilityActivationPolicy::WhileInputActive)
	//			{
	//				AbilitiesToActivate.AddUnique(AbilitySpec->Handle);
	//			}
	//		}
	//	}
	//}

	//
	// Process all abilities that had their input pressed this frame.
	//
	for (const FGameplayAbilitySpecHandle& SpecHandle : InputPressedSpecHandles)
	{
		if (FGameplayAbilitySpec* AbilitySpec = FindAbilitySpecFromHandle(SpecHandle))
		{
			if (AbilitySpec->Ability)
			{
				AbilitySpec->InputPressed = true;

				if (AbilitySpec->IsActive())
				{
					// Ability is active so pass along the input event.
					AbilitySpecInputPressed(*AbilitySpec);
				}
				//else
				//{		
				//	const ULyraGameplayAbility* LyraAbilityCDO = CastChecked<ULyraGameplayAbility>(AbilitySpec->Ability);
				//	if (LyraAbilityCDO->GetActivationPolicy() == ELyraAbilityActivationPolicy::OnInputTriggered)
				//	{
				//		AbilitiesToActivate.AddUnique(AbilitySpec->Handle);
				//	}
				//}
			}
		}
	}

	//
	// Try to activate all the abilities that are from presses and holds.
	// We do it all at once so that held inputs don't activate the ability
	// and then also send a input event to the ability because of the press.
	//
	for (const FGameplayAbilitySpecHandle& AbilitySpecHandle : AbilitiesToActivate)
	{
		TryActivateAbility(AbilitySpecHandle);
	}

	//
	// Process all abilities that had their input released this frame.
	//
	for (const FGameplayAbilitySpecHandle& SpecHandle : InputReleasedSpecHandles)
	{
		if (FGameplayAbilitySpec* AbilitySpec = FindAbilitySpecFromHandle(SpecHandle))
		{
			if (AbilitySpec->Ability)
			{
				AbilitySpec->InputPressed = false;

				if (AbilitySpec->IsActive())
				{
					// Ability is active so pass along the input event.
					AbilitySpecInputReleased(*AbilitySpec);
				}
			}
		}
	}

	//
	// Clear the cached ability handles.
	//
	InputPressedSpecHandles.Reset();
	InputReleasedSpecHandles.Reset();
}

void UCLAbilitySystemComponent::ClearAbilityInput()
{
	InputPressedSpecHandles.Reset();
	InputReleasedSpecHandles.Reset();
	InputHeldSpecHandles.Reset();
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
		FGameplayEffectContext Context;
		FGameplayEffectContextHandle EffectContext = MakeEffectContext();		
		FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(GameplayEffect, 1.0f, EffectContext);

		if (SpecHandle.IsValid())
		{
			FGameplayEffectSpec* Spec = SpecHandle.Data.Get();

			FActiveGameplayEffectHandle EffectHandle = ApplyGameplayEffectSpecToSelf(*Spec);

			//즉발성 Policy면 저장안함 (애초에 핸들도 유효하지 않음) 
			if (GameplayEffect.GetDefaultObject()->DurationPolicy != EGameplayEffectDurationType::Instant)
			{
				if (!EffectHandle.IsValid())
				{
					UE_LOG(LogCloudAbilitySystem, Warning, TEXT("Try AddGameplayEffect But Adding %s Effect has failure in %s."), *(GameplayEffect.Get()->GetName(), *GetOwnerActor()->GetName()));
					return false;
				}
				ActiveGameplayEffectHandle.Add(EffectHandle);
			}
		}

		return true;		
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
