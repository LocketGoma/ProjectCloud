// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CLEquipmentActor.h"
#include "CLSubActionEquipment.generated.h"

class UCLAbilitySystemComponent;

/**
 * 서브장비 클래스.
 * 나중에 필요하면 타입별로 분리할것.
 */
UCLASS()
class PROJECTCLOUD_API ACLSubActionEquipment : public ACLEquipmentActor
{
	GENERATED_BODY()
	
public:	
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	ACLSubActionEquipment(const FObjectInitializer& ObjectInitializer);

	virtual void SetEquipmentFromInstance() override;

	virtual void ActiveEquipment() override;
	virtual bool CanActiveEquipment() override;

	virtual void Reload() override;
	virtual bool CanReload() override;

	//대미지가 되었던, 회복량이 되었던 수치 리턴해주는 함수.
	float GetEquipmentDurationValue();

	ESubEquipmentType GetSubEquipmentType() { return SubEquipmentType; }

private:
	void SetEquipmentFromWeaponInstance(UCLAbilitySystemComponent* ASC);
	void RemoveEquipmentFromWeaponInstance(UCLAbilitySystemComponent* ASC);

	void ActiveWeaponEquipment();
	bool CanActiveWeaponEquipment();

private:
	UPROPERTY(Category = "Config|Equipment", EditDefaultsOnly, meta=(AllowPrivateAccess = "true"))
	ESubEquipmentType SubEquipmentType;

	//무기 타입인 경우
	UPROPERTY(Category = "Config|Equipment|Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLWeaponInstance> WeaponInstance;

	UPROPERTY(Category = "Config|Equipment|Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ACLProjectileActor> ProjectileClass;

	//기타 타입인 경우 (To do)
};
