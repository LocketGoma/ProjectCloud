// Copyright @Locketgoma. All Rights Reserved.

#pragma once

#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "CLAbilitySystemComponent.generated.h"

class UInputAction;
class UCLAbilityInputConfig;
class UEnhancedInputComponent;
struct FInputActionInstance;

/**
 * 
 */
UCLASS()
class PROJECTCLOUD_API UCLAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	//const foo() - 리턴값 잠금
	//foo (const) - 파라미터 잠금
	//foo () const - 내부 변수변경 잠금

	//인풋 액션을 세팅하는 함수
	bool BindInputActions(const UCLAbilityInputConfig* InputConfig, UEnhancedInputComponent* EnhancedInputComponent);
	
	void TryActiveAbilityFromInputAction(const FInputActionInstance& Value);

public:
	//어빌리티 트리거 관련
	void AbilityInputTagPressed(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);

private:
	// Handles to abilities that had their input pressed this frame.
	TArray<FGameplayAbilitySpecHandle> InputPressedSpecHandles;

	// Handles to abilities that had their input released this frame.
	TArray<FGameplayAbilitySpecHandle> InputReleasedSpecHandles;

	// Handles to abilities that have their input held.
	TArray<FGameplayAbilitySpecHandle> InputHeldSpecHandles;

	//인풋 액션 리스트
	TMap<TObjectPtr<const UInputAction>, FGameplayTag> InputactionList;
};
