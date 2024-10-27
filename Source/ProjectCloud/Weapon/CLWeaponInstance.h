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
	UPROPERTY(EditDefaultsOnly)
	FWeaponInstance MagazineSize;

	UPROPERTY(EditDefaultsOnly)
	FWeaponInstance MagazineAmmo;

	//Spare는 임시 처리, 나중에 "탄 수 제한"이 있는 무기가 생길 경우 제대로 쓸 예정.
	UPROPERTY(EditDefaultsOnly)
	FWeaponInstance SpareAmmo;

};
