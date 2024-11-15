// Fill out your copyright notice in the Description page of Project Settings.


#include "CLRewardDropComponent.h"
#include "ProjectCloud/Items/CLInteractionActor.h"
#include "ProjectCloud/Items/CLRewardActorData.h"
#include "ProjectCloud/Items/CLInteractionActor.h"
#include "GameplayEffect.h"

// Sets default values for this component's properties
UCLRewardDropComponent::UCLRewardDropComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCLRewardDropComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UCLRewardDropComponent::TryDropItem()
{
	if (IsValid(DropGold_RewardDataAsset))
		DropItem(DropGold_RewardDataAsset);

	if (IsValid(DropExperience_RewardDataAsset))
		DropItem(DropExperience_RewardDataAsset);

	//To do : 추가 스폰 처리
}

void UCLRewardDropComponent::DropItem(UCLRewardActorData* TargetItemData)
{
	FDropActorData SpawnData = GetDropDataFromDataAsset(TargetItemData);

	FActorSpawnParameters SpawnParameter;
	SpawnParameter.Owner = GetOwner();
	FVector Location = GetOwner()->GetActorLocation();
	FRotator Rotation = GetOwner()->GetActorRotation();

	ACLInteractionActor* SpawnActor = GetWorld()->SpawnActor<ACLInteractionActor>(ACLInteractionActor::StaticClass(), Location, Rotation, SpawnParameter);

	if (SpawnActor)
	{
		SpawnActor->SetActorSprite(SpawnData.ActorSprite);
		SpawnActor->GameplayEffect = SpawnData.GameplayEffect;
	}

}

void UCLRewardDropComponent::DropItems(int Amount, UCLRewardActorData* TargetItemData)
{
}

FDropActorData UCLRewardDropComponent::GetDropDataFromDataAsset(UCLRewardActorData* TargetItemData)
{
	TArray<float> WeightData;
	float NowWeight = 0.f;
	WeightData.Add(NowWeight);

	for (FDropActorData DropData : TargetItemData->DropActorData)
	{
		NowWeight += DropData.SpawnWeight;

		WeightData.Add(NowWeight);
	}

	float Rand = FMath::RandRange(0.f, NowWeight);

	for (int i = 1 ; i < WeightData.Num() ; ++i)
	{
		//범위 안에 들어오면 리턴
		if ((Rand >= WeightData[i - 1]) && (WeightData[i] > Rand))
		{
			return TargetItemData->DropActorData[i-1];
		}
	}

	//여기 들어올일이 없어야됨...
	checkNoEntry();

	return FDropActorData();
}
