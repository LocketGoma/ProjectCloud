// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "ProjectCloud/System/CLAbilityInputConfig.h"
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

private:
	//인풋 액션 리스트
	TMap<TObjectPtr<const UInputAction>, FGameplayTag> InputactionList;
};
