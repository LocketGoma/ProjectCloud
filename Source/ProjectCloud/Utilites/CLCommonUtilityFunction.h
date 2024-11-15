// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CLCommonUtilityFunction.generated.h"

class ACLPlayerController;

namespace CLCommonUtilites
{	
	ACLPlayerController* GetPlayerControllerFromActor(AActor* Actor);
}

UCLASS()
class PROJECTCLOUD_API UCLBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static ACLPlayerController* GetPlayerControllerFromActor(AActor* Actor) { return CLCommonUtilites::GetPlayerControllerFromActor(Actor); }
};