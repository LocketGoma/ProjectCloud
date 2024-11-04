// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CLBaseCharacter.h"
#include "CLEnemyCharacter.generated.h"

class UBehaviorTree;
class AAIController;
class UCLAbilitySystemComponent;
class UCLEnemyAttributeSet;

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

	//--Get/Set
	
	virtual float GetHealth() override;

	void SetTargetPlayer(APawn* NewTarget);

	void SetAI();

	virtual void SetAbilitySystemComponent() override;

	UCLAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilityComponent; }

	TWeakObjectPtr<APawn> GetTargetPlayer() { return TargetPlayer; }

public:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	//충돌시 대미지를 입히는 GameplayEffect
	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DamageGE;

private:	
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBehaviorTree> BTAsset;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	FString TargetPlayerValueName;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	bool bManualTargetSettings = false;

	UPROPERTY()
	TWeakObjectPtr<APawn> TargetPlayer;

	TObjectPtr<UCLAbilitySystemComponent> AbilityComponent;
};
