// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
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
	int Value;
};


UCLASS(BlueprintType, Blueprintable)
class PROJECTCLOUD_API UCLWeaponInstance : public UObject
{
	GENERATED_BODY()

public:
	UCLWeaponInstance(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY(EditDefaultsOnly, meta=(UIMin="0",ClampMin = "0"))
	float BaseDamage;

	//탄창 용량
	UPROPERTY(EditDefaultsOnly)
	FWeaponInstance MagazineSize;

	//즉응탄 (탄창에 남은 탄)
	UPROPERTY(EditDefaultsOnly)
	FWeaponInstance MagazineAmmo;

	//예비탄
	UPROPERTY(EditDefaultsOnly)
	FWeaponInstance SpareAmmo;

	//예비탄 개념을 가지고 있을지 여부
	UPROPERTY(EditDefaultsOnly)
	bool bInfinity = false;
};
