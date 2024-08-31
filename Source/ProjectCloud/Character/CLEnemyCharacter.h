// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CLBaseCharacter.h"
#include "CLEnemyCharacter.generated.h"

class UBehaviorTree;

/**
 * 
 */
UCLASS()
class PROJECTCLOUD_API ACLEnemyCharacter : public ACLBaseCharacter
{
	GENERATED_BODY()

public:
	ACLEnemyCharacter(const FObjectInitializer& ObjectInitializer);


	//--Actor Override
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//--End Actor Override	

	
	void SetTargetPlayer(APawn* NewTarget);

	TWeakObjectPtr<APawn> GetTargetPlayer() { return TargetPlayer; }


private:	
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBehaviorTree> BTAsset;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	FString TargetPlayerValueName;

	UPROPERTY()
	TWeakObjectPtr<APawn> TargetPlayer;
};
