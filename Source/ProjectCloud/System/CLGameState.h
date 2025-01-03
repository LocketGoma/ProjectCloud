// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CLGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameplayEventDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(FTimeEventDelegate, int /*Now Time (second)*/);

class UCLSpawnManagerComponent;

/**
 * 
 */
UCLASS()
class PROJECTCLOUD_API ACLGameState : public AGameStateBase
{
	GENERATED_BODY()

	
public:
	ACLGameState(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	//SpawnManagerComponent 호출 : 외부에서 직접 내부 변수 수정 X 함수 호출만 O
	UFUNCTION(BlueprintCallable, BlueprintPure)
	const UCLSpawnManagerComponent* GetSpawnManagerComponent() const;

	//1마리만 스폰
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SpawnMonsterOnce();

	//임의의 숫자 스폰
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SpawnMonstersAtCount(int32 Count);

//이벤트 핸들링
public:
	//게임 클리어 이벤트
	UPROPERTY(BlueprintAssignable)
	FGameplayEventDelegate OnGameClearEvent;

	//스테이지 클리어 이벤트
	UPROPERTY(BlueprintAssignable)
	FGameplayEventDelegate OnStageClearEvent;

	//게임 오버 이벤트
	UPROPERTY(BlueprintAssignable)
	FGameplayEventDelegate OnGameOverEvent;
		
	FTimeEventDelegate OnPlayTimeUpdateEvent;

	UFUNCTION()
	void HandleGameOverEvent();

	void HandleStartLevelupEvent();
	void HandleFinishLevelupEvent();

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLSpawnManagerComponent> SpawnManagerComponentClass;

	TObjectPtr<UCLSpawnManagerComponent> SpawnManagerComponent;

	FTimerHandle PlayTimeCountHandle;

	int32 PlayTimeSecond;

};
