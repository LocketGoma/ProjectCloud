// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CLRewardActorData.generated.h"

class UPaperSprite;
class UGameplayEffect;

USTRUCT(BlueprintType)
struct PROJECTCLOUD_API FDropActorData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (UIMin = 0, ClampMin = 0))
	float SpawnWeight = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UPaperSprite> ActorSprite;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> GameplayEffect;

};

//스폰할때 여기 있는것 중 하나 스폰
UCLASS()
class PROJECTCLOUD_API UCLRewardActorData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FDropActorData> DropActorData;
	
};
