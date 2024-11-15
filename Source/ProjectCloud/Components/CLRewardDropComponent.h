// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CLRewardDropComponent.generated.h"

struct FDropActorData;
class UCLRewardActorData;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTCLOUD_API UCLRewardDropComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCLRewardDropComponent();

	// Called when the game starts
	virtual void BeginPlay() override;



public:
	//외부에서 이거 호출하면 필수 드랍템 드랍하고 랜덤으로 임의드랍 하기
	UFUNCTION()
	void TryDropItem();


private:
	void DropItem(UCLRewardActorData* TargetItemData);
	void DropItems(int Amount, UCLRewardActorData* TargetItemData);

public:
	//우선 두개만... 나중에 랜덤으로 무언가 추가 하긴 해야됨.
	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	TObjectPtr<UCLRewardActorData> DropGold_RewardDataAsset;
		
	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	TObjectPtr<UCLRewardActorData> DropExperience_RewardDataAsset;

	FDropActorData GetDropDataFromDataAsset(UCLRewardActorData* TargetItemData);

};
