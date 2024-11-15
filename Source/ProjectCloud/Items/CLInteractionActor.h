// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLInteractionActor.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class USphereComponent;
class UCapsuleComponent;
class UGameplayEffect;
class ACLBaseCharacter;
class UPaperSprite;
class UPaperSpriteComponent;

//구역안으로 오버랩되면 아이템을 획득하게 해주는 클래스
//Reawrd Drop Component가 떨구는게 이 친구임.

UCLASS()
class PROJECTCLOUD_API ACLInteractionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACLInteractionActor();
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

	void SetActorSprite(UPaperSprite* NewSprite);

	static FName SpriteComponentName;

private:
	void SetNiagaraEffect();

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UNiagaraComponent> NiagaraComponent;

	//범위내로 들어오면 반응하는 목적
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereComponent;

	//단순히 서 있게 하는 목적
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(Category = Sprite, VisibleAnywhere, BlueprintReadOnly, meta = (ExposeFunctionCategories = "Sprite,Rendering,Physics,Components|Sprite", AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperSpriteComponent> RenderComponent;

};
