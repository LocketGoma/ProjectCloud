// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CLGameState.generated.h"

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

	//SpawnManagerComponent 호출 : 외부에서 직접 내부 변수 수정 X 함수 호출만 O
	UFUNCTION(BlueprintCallable, BlueprintPure)
	const UCLSpawnManagerComponent* GetSpawnManagerComponent() const;

	//1마리만 스폰
	UFUNCTION(BlueprintCallable)
	void SpawnMonsterOnce();

	//임의의 숫자 스폰
	UFUNCTION(BlueprintCallable)
	void SpawnMonstersAtCount(int32 Count);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLSpawnManagerComponent> SpawnManagerComponentClass;

	TObjectPtr<UCLSpawnManagerComponent> SpawnManagerComponent;

};
