// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "CLSpawnManagerComponent.generated.h"

/**
 * 
 */
class ACLGameState;
class ACLBaseCharacter;

UCLASS(Blueprintable)
class PROJECTCLOUD_API UCLSpawnManagerComponent : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UCLSpawnManagerComponent(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;


	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Spawn")
	const TMap<TSubclassOf<ACLBaseCharacter>, float> GetMonsterListAndFrequency() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Spawn")
	const TArray<TSubclassOf<ACLBaseCharacter>> GetMonsterList() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Spawn")
	const int32 GetMonsterCount();

	
	UFUNCTION(BlueprintCallable, Category = "Spawn")
	APawn* SapwnMonster(TSubclassOf<APawn> MonsterType);

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	bool SpawnMonsters(int32 count);
	
	UFUNCTION(BlueprintCallable, Category = "Spawn")
	bool SpawnMonsterAtSingleGroup();

private:
	TSubclassOf<APawn> GetSapwnMonsterType();

	bool SpawnMonstersInternal(int32 NowCount, int32 TargetCount);

private:
	FTimerHandle SpawnTimeHandle;

	//몬스터 종류 (
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn|SpawnType|Base", meta = (AllowPrivateAccess = "true"))
	TMap<TSubclassOf<ACLBaseCharacter>, float> MonsterAndFrequencies;
	
	//한번에 스폰하는 몬스터 수
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn|Config", meta = (UIMin = "0", UIMax = "100", ClampMin = "0", AllowPrivateAccess = "true"))
	int32 SpawnCountForSingleSpawnGroup = 10;

	//스폰 그룹에서 1마리 스폰 간격
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn|Config", meta = (UIMin = "0", UIMax = "10", ClampMin = "0", AllowPrivateAccess = "true"))
	float SpawnIntervalAtSingleSpawnGroup = 0.5f;

	float TotalFrequency;
};
