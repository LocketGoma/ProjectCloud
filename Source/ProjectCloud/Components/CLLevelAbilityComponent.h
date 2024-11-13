// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PlayerStateComponent.h"
#include "CLLevelAbilityComponent.generated.h"

//캐릭터 레벨업 발생시 "이벤트 카드"를 가지고 관리하는 클래스
//경험치 컴포넌트와 ASC와 연관있음

//To do : 전용 Struct 만들고, 해당 Struct를 Array로(혹은 Map) 만들어서 관리하기.

class UCLExperienceComponent;
class ACLPlayerState;

UCLASS()
class PROJECTCLOUD_API UCLLevelAbilityComponent : public UPlayerStateComponent
{
	GENERATED_BODY()
	

public:
	UCLLevelAbilityComponent(const FObjectInitializer& ObjectInitializer);

public:
	// Called when the game starts
	virtual void BeginPlay() override;	
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;

	void InitializeDelegates();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const int GetPlayerLevel();

private:
	TWeakObjectPtr<ACLPlayerState> PS;

private:
	friend UCLExperienceComponent;
};
