// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CLPlayerState.generated.h"

/**
 * 
 */
class UCLAbilitySystemComponent;
class UGameplayAbilitySet;

UCLASS()
class PROJECTCLOUD_API ACLPlayerState : public APlayerState
{
	GENERATED_BODY()

	ACLPlayerState(const FObjectInitializer& ObjectInitializer);

public:
	UCLAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilityComponent; }
	void SetAbilitiesFromActionSet(UGameplayAbilitySet* AbilitySet);

private:
	void CopyAbilitesToPawn();

private:
	TObjectPtr<UCLAbilitySystemComponent> AbilityComponent;

	bool bAbilitySet;


	
};
