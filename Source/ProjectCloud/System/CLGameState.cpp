// Fill out your copyright notice in the Description page of Project Settings.


#include "CLGameState.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectCloud/System/CLSpawnManagerComponent.h"

ACLGameState::ACLGameState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{	

}

void ACLGameState::BeginPlay()
{
	if (SpawnManagerComponentClass)
	{
		SpawnManagerComponent = Cast<UCLSpawnManagerComponent>(AddComponentByClass(SpawnManagerComponentClass, false, FTransform::Identity, false));
	}

	check(SpawnManagerComponent);
	//UE_LOG(LogTemp, Error, TEXT("Not set SpawnManaget in GameState. Please Set SapwnManagerClass in GameState."));

	Super::BeginPlay();
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

void ACLGameState::HandleStartLevelupEvent()
{
	UGameplayStatics::SetGamePaused(this, true);
}

void ACLGameState::HandleFinishLevelupEvent()
{
	UGameplayStatics::SetGamePaused(this, false);
}

void ACLGameState::HandleGameOverEvent_Implementation()
{
	
}

void ACLGameState::HandleGameClearEvent_Implementation()
{
}
