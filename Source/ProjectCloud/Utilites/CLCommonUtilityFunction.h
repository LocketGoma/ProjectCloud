// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CLCommonUtilityFunction.generated.h"

class ACLPlayerController;

namespace CLCommonUtilites
{	
	ACLPlayerController* GetPlayerControllerFromActor(AActor* Actor);
	TArray<TObjectPtr<AActor>> GetSpawnedEnemies(UObject* WorldContext, bool bCheckValidation = false, bool bForceUpdate = true);
	TArray<TObjectPtr<AActor>> GetSpawnedProjectiles(UObject* WorldContext, bool bCheckValidation = false, bool bForceUpdate = true);
	TArray<TObjectPtr<AActor>> GetSpawnedItems(UObject* WorldContext, bool bCheckValidation = false, bool bForceUpdate = true);
}

UCLASS()
class PROJECTCLOUD_API UCLBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static ACLPlayerController* GetPlayerControllerFromActor(AActor* Actor) { return CLCommonUtilites::GetPlayerControllerFromActor(Actor); }

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static TArray<AActor *> GetSpawnedEnemies(UObject * WorldContext, bool bCheckValidation = true, bool bForceUpdate = true) { return CLCommonUtilites::GetSpawnedEnemies(WorldContext, bCheckValidation, bForceUpdate); }

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static TArray<AActor *> GetSpawnedProjectiles(UObject * WorldContext, bool bCheckValidation = true, bool bForceUpdate = true) { return CLCommonUtilites::GetSpawnedProjectiles(WorldContext, bCheckValidation, bForceUpdate); }

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static TArray<AActor *> GetSpawnedItems(UObject * WorldContext, bool bCheckValidation = true, bool bForceUpdate = true) { return CLCommonUtilites::GetSpawnedItems(WorldContext, bCheckValidation, bForceUpdate); }
};