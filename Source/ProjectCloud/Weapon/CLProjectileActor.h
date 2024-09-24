// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CLProjectileActor.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class UCapsuleComponent;
class UCLWeaponAttributeSet;
class UGameplayEffect;

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
	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DamageGE;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UNiagaraSystem> MainVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UNiagaraSystem> SubVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UNiagaraSystem> TrailVFX;

	//나아가는 방향
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
	FVector LaunchVector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (UIMin = 0, ClampMin = 0))
	float LaunchSpeed;

private:
	UPROPERTY()
	TObjectPtr<UNiagaraComponent> NiagaraComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY()
	UCLWeaponAttributeSet* AttributeSet;

};
