// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CLPlayerState.generated.h"

class UCLAbilitySystemComponent;
class UCLLevelAbilityComponent;
class UCLExperienceComponent;
class UCLAbilitySet;

//델리게이트 추가

DECLARE_MULTICAST_DELEGATE_OneParam(FTryLevelUpDelegate, int64 /*NowExp*/);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLevelUpEventDelegate, int, Level);

UCLASS()
class PROJECTCLOUD_API ACLPlayerState : public APlayerState
{
	GENERATED_BODY()

	ACLPlayerState(const FObjectInitializer& ObjectInitializer);

public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	void InitializePlayerState(UCLAbilitySet* AbilitySet = nullptr);
	UCLExperienceComponent* GetExperienceComponent() const { return ExperienceComponent; }
	UCLAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilityComponent; }
	UCLLevelAbilityComponent* GetLevelAbilityComponent() const { return LevelAbilityComponent; }

//유틸 함수들
public:
	//델리게이트로 바꾸기
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PlayerOutOfHealthEvent();

	UFUNCTION(BlueprintCallable)
	void StartLevelupEvent();

	UFUNCTION(BlueprintCallable)
	void FinishLevelupEvent();

//Getter/Setter
	UFUNCTION(BlueprintCallable, BlueprintPure)
	const int GetPlayerLevel();

	void SetAbilitiesFromActionSet(UCLAbilitySet* AbilitySet);
	
//Delegates
public:
	FTryLevelUpDelegate OnTryLevelUpEvent;

	UPROPERTY(BlueprintAssignable)
	FLevelUpEventDelegate OnLevelUpEvent;

private:
	void InitializeDelegates();
	void UnInitializeDelegates();

	UFUNCTION()
	void HandlePlayerOutOfHealth();

	UFUNCTION()
	void HandleLevelUpEvent(int64 NowExp);

private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", ClampMin = "0"))
	int PlayerLevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCLAbilitySystemComponent> AbilityComponent;	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCLExperienceComponent> ExperienceComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCLLevelAbilityComponent> LevelAbilityComponent;

	bool bAbilitySet;	
};
