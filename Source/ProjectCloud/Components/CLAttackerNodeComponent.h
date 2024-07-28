// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CLAttackerNodeComponent.generated.h"

class USphereComponent;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent) )
class PROJECTCLOUD_API UCAttackerNodeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCAttackerNodeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	//공격 지점
	UPROPERTY()
	USphereComponent* AttackPoint;

	//캐릭터 중심 지점
	UPROPERTY()
	USphereComponent* CorePoint;

		
};
