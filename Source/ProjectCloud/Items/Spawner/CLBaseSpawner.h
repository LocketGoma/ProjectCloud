// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLBaseSpawner.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class USphereComponent;
class UCapsuleComponent;
class UGameplayEffect;
class ACLBaseCharacter;

//구역안으로 오버랩되면 아이템을 획득하게 해주는 클래스

UCLASS()
class PROJECTCLOUD_API ACLBaseSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACLBaseSpawner();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnComponentBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	TSubclassOf<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VisualSettings")
	TObjectPtr<UNiagaraSystem> MainVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VisualSettings")
	TObjectPtr<UNiagaraSystem> SubVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VisualSettings")
	TObjectPtr<UNiagaraSystem> TrailVFX;

	static FName SpriteComponentName;

private:
	void SetNiagaraEffect();

private:
	UPROPERTY()
	TObjectPtr<UNiagaraComponent> NiagaraComponent;

	//범위내로 들어오면 반응하는 목적
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USphereComponent> SphereComponent;

	//단순히 서 있게 하는 목적
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VisualSettings", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbookComponent> Sprite;

};
