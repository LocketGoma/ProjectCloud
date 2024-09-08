// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CLProjectileActor.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class UCapsuleComponent;

UCLASS()
class PROJECTCLOUD_API ACLProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACLProjectileActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UNiagaraSystem> MainVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UNiagaraSystem> SubVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UNiagaraSystem> TrailVFX;

private:
	UPROPERTY()
	TObjectPtr<UNiagaraComponent> NiagaraComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

};
