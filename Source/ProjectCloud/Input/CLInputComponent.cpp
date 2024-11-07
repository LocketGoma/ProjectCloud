// Fill out your copyright notice in the Description page of Project Settings.


#include "CLInputComponent.h"

UCLInputComponent::UCLInputComponent(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void UCLInputComponent::AddInputMappings(const UCLAbilityInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const
{
	//추가적인 인풋 컨피그 처리 필요시 추가
}

void UCLInputComponent::RemoveInputMappings(const UCLAbilityInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const
{
	//추가적인 인풋 컨피그 처리 필요시 추가
}

void UCLInputComponent::RemoveBinds(TArray<uint32>& BindHandles)
{
	for (uint32 Handle : BindHandles)
	{
		RemoveBindingByHandle(Handle);
	}
	BindHandles.Reset();
}
