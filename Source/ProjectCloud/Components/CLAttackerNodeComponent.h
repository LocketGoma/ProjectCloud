// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLAttackerNodeComponent.generated.h"

class ACLWeapon;
class USphereComponent;

//구조
//어태커 노드에서 무기를 가지고 있음
//무기 정보는 캐릭터 -> 어태커 노드를 통해 획득 (플레이어가 직접 무기 정보를 가지고 있진 않음)

//무기를 소지하는 노드 컴포넌트
UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class PROJECTCLOUD_API UCAttackerNodeComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCAttackerNodeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
	void UpdateAttactPointLength(float NewLenght);

	UFUNCTION(BlueprintCallable)
	void UpdateRotation(float Val);

	UFUNCTION()
	void AddRotation(float Val);

	UFUNCTION(BlueprintImplementableEvent)
	void K2_UpdateRotation(FRotator newRotation);

	UFUNCTION(BlueprintImplementableEvent)
	void K2_UpdateAttactPointLength(float NewLength);

//유틸함수 리스트
public:
	UFUNCTION(BlueprintCallable)
	const USceneComponent* GetAttackPoint();

	UFUNCTION(BlueprintCallable)
	const FTransform GetAttackPointTransform();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ACLWeapon* GetWeaponActor();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const EWeaponType GetWeaponType() const;

public:
	//중심에서 공격지점까지 거리
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(UIMin="0", UIMax="200", ClampMin = "0"))
	float AttactPointLength = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ACLWeapon> WeaponActorClass;

	//무기가 바라보는 방향을 그대로 볼지
	UPROPERTY(EditDefaultsOnly)
	bool bWeaponRelativeSpin;

private:
	//공격 지점
	UPROPERTY()
	USphereComponent* AttackPoint;

	//캐릭터 중심 지점
	UPROPERTY()
	USphereComponent* CorePoint;

	UPROPERTY()
	ACLWeapon* WeaponActor;

		
};
