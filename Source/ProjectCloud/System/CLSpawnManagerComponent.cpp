#include "CLSpawnManagerComponent.h"

UCLSpawnManagerComponent::UCLSpawnManagerComponent(const FObjectInitializer& ObjectInitializer)
	: Super (ObjectInitializer)
{
	TotalFrequency = 0.f;
}

void UCLSpawnManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	for (TPair< TSubclassOf<APawn>, float> Monster : MonsterAndFrequencies)
	{
		TotalFrequency += Monster.Value;
	}

}

const TMap<TSubclassOf<APawn>, float> UCLSpawnManagerComponent::GetMonsterListAndFrequency() const
{
	if (MonsterAndFrequencies.IsEmpty())
	{
		UE_LOG(LogTemp, Log, TEXT("Monster List For Spawn is Empty. Wrong Setting! Check UCLSpawnManagerComponent for More."))
	}
	
	return MonsterAndFrequencies;
}

const TArray<TSubclassOf<APawn>> UCLSpawnManagerComponent::GetMonsterList() const
{
	TArray<TSubclassOf<APawn>> MonsterList;

	for (TPair< TSubclassOf<APawn>, float> Monster : MonsterAndFrequencies)
	{
		MonsterList.AddUnique(Monster.Key);
	}

	return MonsterList;
}

const int32 UCLSpawnManagerComponent::GetMonsterCount()
{
	return GetMonsterListAndFrequency().Num();
}

APawn* UCLSpawnManagerComponent::SapwnMonster(TSubclassOf<APawn> MonsterType)
{
	if (!ensure(IsValid(MonsterType)))
	{
		return nullptr;
	}
	APawn* SpawnedPawn = GetWorld()->SpawnActor<APawn>(MonsterType.Get());

	return SpawnedPawn;
}

bool UCLSpawnManagerComponent::SpawnMonsters(int32 count)
{
	return SpawnMonstersInternal(0, count);
}

bool UCLSpawnManagerComponent::SpawnMonsterAtSingleGroup()
{
	return false;
}

TSubclassOf<APawn> UCLSpawnManagerComponent::GetSapwnMonsterType()
{
	float RandResult = FMath::RandRange(0.f, TotalFrequency);

	float ZeroToRand = 0.f;

	for (TPair< TSubclassOf<APawn>, float> Monster : MonsterAndFrequencies)
	{
		ZeroToRand += Monster.Value;
		if (RandResult <= ZeroToRand)
		{
			return Monster.Key;
		}
	}

	return nullptr;
}

bool UCLSpawnManagerComponent::SpawnMonstersInternal(int32 NowCount, int32 TargetCount)
{
	//1 숫자 체크
	if (NowCount >= TargetCount)
	{
		GetWorldTimerManager().ClearTimer(SpawnTimeHandle);
		SpawnTimeHandle.Invalidate();
		
		return true;
	}
	
	//2 Spawn 시도
	SapwnMonster(GetSapwnMonsterType());



	GetWorldTimerManager().SetTimer(SpawnTimeHandle, FTimerDelegate::CreateLambda([this, NowCount, TargetCount]
		{
			this->SpawnMonstersInternal(NowCount + 1, TargetCount);
		}), SpawnIntervalAtSingleSpawnGroup, true);

	return true;
}
