// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLWeaponInstance.generated.h"

//Weaponinstance 클래스 / 구조체
//연산을 따로 하지는 않음..

USTRUCT(BlueprintType)
struct PROJECTCLOUD_API FWeaponInstance
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly)
	FGameplayTag KeyTag;

	UPROPERTY(EditDefaultsOnly)
	int Value = 0;
};


UCLASS(BlueprintType, Blueprintable)
class PROJECTCLOUD_API UCLWeaponInstance : public UObject
{
	GENERATED_BODY()

public:
	UCLWeaponInstance(const FObjectInitializer& ObjectInitializer);

	static const bool CanAutoReload(UCLWeaponInstance& Instance);
	static const bool CanAutoReload(TSubclassOf<UCLWeaponInstance> Instance);
	static const bool HasInfinityAmmo(UCLWeaponInstance& Instance);
	static const bool HasInfinityAmmo(TSubclassOf<UCLWeaponInstance> Instance);
	static const float GetBaseDamage(UCLWeaponInstance& Instance);
	static const float GetBaseDamage(TSubclassOf<UCLWeaponInstance> Instance);
	static const FWeaponInstance GetMagazineSizeData(UCLWeaponInstance& Instance);
	static const FWeaponInstance GetMagazineSizeData(TSubclassOf<UCLWeaponInstance> Instance);
	static const FWeaponInstance GetMagazineAmmoData(UCLWeaponInstance& Instance);
	static const FWeaponInstance GetMagazineAmmoData(TSubclassOf<UCLWeaponInstance> Instance);
	static const FWeaponInstance GetSpareAmmoData(UCLWeaponInstance& Instance);
	static const FWeaponInstance GetSpareAmmoData(TSubclassOf<UCLWeaponInstance> Instance);


	UFUNCTION() 
	void OnEquipmentTypeChanged();
#if WITH_EDITOR

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

#endif

public:
	UPROPERTY(EditDefaultsOnly)
	EEquipmentType EquipmentType;


	UPROPERTY(EditDefaultsOnly, meta=(UIMin="0",ClampMin = "0"))
	float BaseDamage = 0.f;

	//탄창 용량
	UPROPERTY(EditDefaultsOnly)
	FWeaponInstance MagazineSize;

	//즉응탄 (탄창에 남은 탄)
	UPROPERTY(EditDefaultsOnly)
	FWeaponInstance MagazineAmmo;

	//예비탄
	UPROPERTY(EditDefaultsOnly)
	FWeaponInstance SpareAmmo;

	//자동 재장전 가능 여부
	UPROPERTY(EditDefaultsOnly)
	bool bAutoReload = true;

	//예비탄 개념을 가지고 있을지 여부
	UPROPERTY(EditDefaultsOnly)
	bool bInfinity = false;
};
