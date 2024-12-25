// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ActorStateManagerSubsystem.generated.h"

/**
 * 월드에 배치된 액터들을 리스트업해서 관리하는 서브시스템 
 * (근데 액터에 직접 접근하는건 아님) <- 중요
 * 
 * 월드 배치 몬스터, 월드 배치 탄환, 월드 배치 아이템 등을 관리하고 획득
 */
UCLASS()
class PROJECTCLOUD_API UActorStateManagerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	UActorStateManagerSubsystem();
	virtual void PostInitialize() override;	
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	TArray<TObjectPtr<AActor>> GetSpawnedEnemies(bool bCheckValidation = false, bool bForceUpdate = true);
	TArray<TObjectPtr<AActor>> GetSpawnedProjectiles(bool bCheckValidation = false, bool bForceUpdate = true);
	TArray<TObjectPtr<AActor>> GetSpawnedItems(bool bCheckValidation = false, bool bForceUpdate = true);

private:
	TArray<TObjectPtr<AActor>> SpawnedEnemies;
	TArray<TObjectPtr<AActor>> SpawnedProjectiles;
	TArray<TObjectPtr<AActor>> SpawnedItems;
};
