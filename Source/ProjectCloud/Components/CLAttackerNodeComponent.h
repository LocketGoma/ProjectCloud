// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLAttackerNodeComponent.generated.h"

class ACLWeapon;
class ACLSubActionEquipment;
class USphereComponent;

//무기 교체 이벤트 델리게이트
DECLARE_MULTICAST_DELEGATE_OneParam(FCLMainWeaponChanged, TObjectPtr<ACLWeapon>);
DECLARE_MULTICAST_DELEGATE_OneParam(FCLSubWeaponChanged, TObjectPtr<ACLSubActionEquipment>);


//구조
//어태커 노드에서 무기를 가지고 있음
//무기 정보는 캐릭터 -> 어태커 노드를 통해 획득 (플레이어가 직접 무기 정보를 가지고 있진 않음)

//무기를 소지하는 노드 컴포넌트
UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class PROJECTCLOUD_API UCLAttackerNodeComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCLAttackerNodeComponent();

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

	//아이템획득으로 장착시킬때를 위해
	UFUNCTION(BlueprintCallable)
	void EquipSubEquipmentActor(TSubclassOf<ACLSubActionEquipment> EquipmentActorClass);

	void HandleEquipMainWeaponActor(TObjectPtr<ACLWeapon> NewWeaponActor);
	void HandleEquipSubEquipmentActor(TObjectPtr<ACLSubActionEquipment> NewEquipActor);

	
//유틸함수 리스트
public:	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	const USceneComponent* GetAttackPoint();

	UFUNCTION(BlueprintCallable)
	const FTransform GetAttackPointTransform();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ACLWeapon* GetWeaponActor();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ACLSubActionEquipment* GetSubEquipmentActor();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const EWeaponType GetWeaponType() const;

public:
	FCLMainWeaponChanged OnMainWeaponChanged;
	FCLSubWeaponChanged OnSubWeaponChanged;

	//중심에서 공격지점까지 거리
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(UIMin="0", UIMax="200", ClampMin = "0"))
	float AttactPointLength = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ACLWeapon> WeaponActorClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ACLSubActionEquipment> SubEquipmentActorClass;

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
	TObjectPtr<ACLWeapon> WeaponActor;

	UPROPERTY()
	TObjectPtr<ACLSubActionEquipment> SubEquipmentActor;		
};
