// Fill out your copyright notice in the Description page of Project Settings.


#include "CLGameState.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectCloud/System/CLSpawnManagerComponent.h"

ACLGameState::ACLGameState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, PlayTimeSecond(0)
{
	OnGameOverEvent.AddDynamic(this, &ThisClass::HandleGameOverEvent);
}

void ACLGameState::BeginPlay()
{
	if (SpawnManagerComponentClass)
	{
		SpawnManagerComponent = Cast<UCLSpawnManagerComponent>(AddComponentByClass(SpawnManagerComponentClass, false, FTransform::Identity, false));
	}

	check(SpawnManagerComponent);
	//UE_LOG(LogTemp, Error, TEXT("Not set SpawnManaget in GameState. Please Set SapwnManagerClass in GameState."));

	//GetWorld()->GetTimerManager().SetTimer(PlayTimeCountHandle, FTimerDelegate::CreateLambda([this]() {
	//	++PlayTimeSecond;
	//	OnPlayTimeUpdateEvent.Broadcast(PlayTimeSecond);
	//	}), 1.0f, true, -1.0f);


	Super::BeginPlay();
}

void ACLGameState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	//if (PlayTimeCountHandle.IsValid())
	//{
	//	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	//	PlayTimeCountHandle.Invalidate();
	//}
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
	SpawnManagerComponent->SpawnMonsters(Count);
}

void ACLGameState::HandleGameOverEvent()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void ACLGameState::HandleStartLevelupEvent()
{
	UGameplayStatics::SetGamePaused(this, true);
}

void ACLGameState::HandleFinishLevelupEvent()
{
	UGameplayStatics::SetGamePaused(this, false);
}
