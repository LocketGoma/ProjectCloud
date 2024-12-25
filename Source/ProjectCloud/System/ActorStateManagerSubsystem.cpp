// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorStateManagerSubsystem.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Character/CLEnemyCharacter.h"
#include "ProjectCloud/Weapon/CLProjectileActor.h"

UActorStateManagerSubsystem::UActorStateManagerSubsystem()
	: Super()
{

}

void UActorStateManagerSubsystem::PostInitialize()
{
	Super::PostInitialize();
}

void UActorStateManagerSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	GetSpawnedEnemies();
}

TArray<TObjectPtr<AActor>> UActorStateManagerSubsystem::GetSpawnedEnemies(bool bCheckValidation, bool bForceUpdate)
{
	//ForcedUpdate 켜져있으면 ValidCheck 의미없음.
	if (bCheckValidation && !bForceUpdate)
	{
		for (AActor* Actor : SpawnedEnemies)
		{
			if (!IsValid(Actor))
			{
				bForceUpdate = true;
				break;
			}
		}
	}

	if (bForceUpdate || SpawnedEnemies.IsEmpty())
	{
		//이랬는데 다 날아가고 그러진 않겠지?
		SpawnedEnemies.Empty();
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACLEnemyCharacter::StaticClass(), SpawnedEnemies);
	}
	
	return SpawnedEnemies;
}
//쓸거면 고치기
TArray<TObjectPtr<AActor>> UActorStateManagerSubsystem::GetSpawnedProjectiles(bool bCheckValidation, bool bForceUpdate)
{
	checkNoEntry();

	return SpawnedProjectiles;
}

//쓸거면 고치기
TArray<TObjectPtr<AActor>> UActorStateManagerSubsystem::GetSpawnedItems(bool bCheckValidation, bool bForceUpdate)
{
	checkNoEntry();

	return SpawnedItems;
}
