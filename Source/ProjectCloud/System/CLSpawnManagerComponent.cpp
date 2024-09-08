#include "CLSpawnManagerComponent.h"
#include "ProjectCloud/System/CLGameState.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Character/CLEnemyCharacter.h"
#include "AIController.h"

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

const TMap<TSubclassOf<ACLBaseCharacter>, float> UCLSpawnManagerComponent::GetMonsterListAndFrequency() const
{
	if (MonsterAndFrequencies.IsEmpty())
	{
		UE_LOG(LogTemp, Log, TEXT("Monster List For Spawn is Empty. Wrong Setting! Check UCLSpawnManagerComponent for More."))
	}
	
	return MonsterAndFrequencies;
}

const TArray<TSubclassOf<ACLBaseCharacter>> UCLSpawnManagerComponent::GetMonsterList() const
{
	TArray<TSubclassOf<ACLBaseCharacter>> MonsterList;

	for (TPair< TSubclassOf<ACLBaseCharacter>, float> Monster : MonsterAndFrequencies)
	{
		MonsterList.AddUnique(Monster.Key);
	}

	return MonsterList;
}

const int32 UCLSpawnManagerComponent::GetMonsterCount()
{
	return GetMonsterListAndFrequency().Num();
}

APawn* UCLSpawnManagerComponent::SpawnMonster(TSubclassOf<APawn> MonsterType)
{
	if (!ensure(IsValid(MonsterType)))
	{
		return nullptr;
	}
	ACLEnemyCharacter* SpawnedPawn = GetWorld()->SpawnActor<ACLEnemyCharacter>(MonsterType.Get());
	AAIController* SpawnedEnemyController = GetWorld()->SpawnActor<AAIController>();

	SpawnedEnemyController->UnPossess();
	SpawnedEnemyController->Possess(SpawnedPawn);

	APawn* TargetPlayer = GEngine->GetFirstLocalPlayerController(GetWorld())->GetPawn();

	SpawnedPawn->SetTargetPlayer(TargetPlayer);
	SpawnedPawn->SetAI();

	return SpawnedPawn;
}


void UCLSpawnManagerComponent::SpawnMonsterAtSingleGroup()
{
	SpawnMonsters(SpawnCountForSingleSpawnGroup);
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

void UCLSpawnManagerComponent::SpawnMonsters(int32 count)
{
	bool Result = SpawnMonstersInternal(0, count);

	if (!Result)
	{
		UE_LOG(LogTemp, Log, TEXT("Something Wrong Event Checked in MonsterSpawn Logic. Please Check UCLSpawnManagerComponent Class or else"));
	}
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
	//+ 스폰된 모든 몬스터의 정보를 가지고 있어야 되는 경우 로직 추가
	APawn* SpawnedMonster = SpawnMonster(GetSapwnMonsterType());

	if (!IsValid(SpawnedMonster))
	{
		return false;
	}


	GetWorldTimerManager().SetTimer(SpawnTimeHandle, FTimerDelegate::CreateLambda([this, NowCount, TargetCount]
		{
			this->SpawnMonstersInternal(NowCount + 1, TargetCount);
		}), SpawnIntervalAtSingleSpawnGroup, true);

	return true;
}
