// Fill out your copyright notice in the Description page of Project Settings.

#include "CLCommonUtilityFunction.h"
#include "ProjectCloud/System/ActorStateManagerSubsystem.h"
#include "ProjectCloud/Character/CLPlayerState.h"
#include "ProjectCloud/Character/CLHeroCharacter.h"
#include "ProjectCloud/Character/CLPlayerController.h"

ACLPlayerController* CLCommonUtilites::GetPlayerControllerFromActor(AActor* Actor)
{
	ACLPlayerController* CLPlayerController = nullptr;
	if (Actor)
	{
		//1. Actor가 PS인 경우
		if (ACLPlayerState* PS = Cast<ACLPlayerState>(Actor))
		{
			CLPlayerController = Cast<ACLPlayerController>(PS->GetPlayerController());

		}

		//2. Actor가 Hero Character인 경우
		else if (ACLHeroCharacter* PlayerPawn = Cast<ACLHeroCharacter>(Actor))
		{
			CLPlayerController = Cast<ACLPlayerController>(PlayerPawn->GetController());
		}
	}
	return CLPlayerController;
}

TArray<TObjectPtr<AActor>> CLCommonUtilites::GetSpawnedEnemies(UObject* WorldContext, bool bCheckValidation, bool bForceUpdate)
{
	if (!WorldContext)
		return TArray<TObjectPtr<AActor>>();
	
	UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContext);

	if (World)
	{
		UActorStateManagerSubsystem* ASMSubSystem =	World->GetSubsystem<UActorStateManagerSubsystem>();

		return ASMSubSystem->GetSpawnedEnemies(bCheckValidation, bForceUpdate);
	}

	return TArray<TObjectPtr<AActor>>();
}

TArray<TObjectPtr<AActor>> CLCommonUtilites::GetSpawnedProjectiles(UObject* WorldContext, bool bCheckValidation, bool bForceUpdate)
{
	return TArray<TObjectPtr<AActor>>();
}

TArray<TObjectPtr<AActor>> CLCommonUtilites::GetSpawnedItems(UObject* WorldContext, bool bCheckValidation, bool bForceUpdate)
{
	return TArray<TObjectPtr<AActor>>();
}
