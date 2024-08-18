// Fill out your copyright notice in the Description page of Project Settings.


#include "CLGameState.h"
#include "ProjectCloud/System/CLSpawnManagerComponent.h"

ACLGameState::ACLGameState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{	
}

void ACLGameState::BeginPlay()
{
	SpawnManagerComponent = SpawnManagerComponentClass.GetDefaultObject();
	SpawnManagerComponent;
}

const UCLSpawnManagerComponent* ACLGameState::GetSpawnManagerComponent() const
{
	if (!ensure(SpawnManagerComponent))
	{
		UE_LOG(LogTemp, Log, TEXT("ACLGameState::UCLSpawnManagerComponent is NULL!!!"));

		return nullptr;
	}

	return SpawnManagerComponent;
}

void ACLGameState::SpawnMonsterOnce()
{
	if (ensure(SpawnManagerComponent))
	{
		SpawnManagerComponent->SpawnMonsters(1);
	}

}

void ACLGameState::SpawnMonstersAtCount(int32 Count)
{
	SpawnManagerComponent->SpawnMonsters(10);
}
