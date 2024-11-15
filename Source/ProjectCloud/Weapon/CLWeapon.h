// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectCloud/Weapon/CLEquipmentActor.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLWeapon.generated.h"

class UPaperFlipbookComponent;
class ACLProjectileActor;
class USphereComponent;
class UCLWeaponInstance;
class UCLAbilitySystemComponent;

UCLASS()
class PROJECTCLOUD_API ACLWeapon : public ACLEquipmentActor
{	
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	ACLWeapon(const FObjectInitializer& ObjectInitializer);

	virtual void SetEquipmentFromInstance() override;

	virtual void ActiveEquipment() override;
	virtual bool CanActiveEquipment() override;

	virtual void Reload() override;
	virtual bool CanReload() override;	
	virtual void UpdateEquipmentEvent() override;

//Getter
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	const EWeaponType GetWeaponType() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const EWeaponEventType GetWeaponEventType() const;
			
	virtual const int GetMagazineSize() const override;
	virtual const int GetMagazineAmmo() const override;
	virtual const int GetSpareAmmo() const override;
	virtual const bool GetIsInfinite() const override;
	virtual const float GetBaseEquipmentValue() const override;

private:
	void FinishReload();

public:
	UFUNCTION(BlueprintCallable)
	void UpdateWeaponEventType(EWeaponEventType NewEvent);

	UPROPERTY(Category = "Config|Equipment|Weapon", VisibleAnywhere, BlueprintReadOnly)
	EWeaponEventType WeaponEventType;

private:	
	UPROPERTY(Category = "Config|Equipment|Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", UIMin = "0.1", UIMax="10", ClampMin = "0.1"))
	float ReloadTime;

	UPROPERTY(Category = "Config|Equipment|Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	EWeaponType WeaponType;

	UPROPERTY(Category = "Config|Equipment|Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ACLProjectileActor> ProjectileClass;

	UPROPERTY(Category = "Config|Equipment|Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLWeaponInstance> WeaponInstance;

};
