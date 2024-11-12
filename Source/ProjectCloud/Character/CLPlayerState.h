// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CLPlayerState.generated.h"

class UCLAbilitySystemComponent;
class UCLAbilitySet;

//델리게이트 추가


UCLASS()
class PROJECTCLOUD_API ACLPlayerState : public APlayerState
{
	GENERATED_BODY()

	ACLPlayerState(const FObjectInitializer& ObjectInitializer);

public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	UCLAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilityComponent; }
	void SetAbilitiesFromActionSet(UCLAbilitySet* AbilitySet);
	void InitializePlayerState(UCLAbilitySet* AbilitySet = nullptr);

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PlayerOutOfHealthEvent();

private:
	void InitializeDelegates();
	void UnInitializeDelegates();

	UFUNCTION()
	void HandlePlayerOutOfHealth();


private:
	TObjectPtr<UCLAbilitySystemComponent> AbilityComponent;

	bool bAbilitySet;	
};
