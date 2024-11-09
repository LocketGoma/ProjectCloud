// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLWeapon.generated.h"

class UPaperFlipbookComponent;
class ACLProjectileActor;
class USphereComponent;
class UCLWeaponInstance;
class UCLAbilitySystemComponent;

UCLASS()
class PROJECTCLOUD_API ACLWeapon : public AActor
{	
	GENERATED_UCLASS_BODY()
	
	// Name of the Sprite component
	static FName SpriteComponentName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetWeaponFromInstance();


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Attack();
	bool CanAttack();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Reload();
	bool CanReload();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ReloadEvent();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void UpdateAmmoEvent();


//Getter
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	AController* GetOwnerController();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const EWeaponType GetWeaponType() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const EWeaponEventType GetWeaponEventType() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const int GetMagazineSize();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const int GetMagazineAmmo();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const int GetSpareAmmo();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const bool GetIsInfinite();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const float GetBaseWeaponDamage();

public:
	UFUNCTION(BlueprintCallable)
	void UpdateWeaponEventType(EWeaponEventType NewEvent);

	UPROPERTY(Category = "Weapon", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	EWeaponEventType WeaponEventType;

private:	
	UPROPERTY(Category = "Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", UIMin = "0.1", UIMax="10", ClampMin = "0.1"))
	float ReloadTime;

	UPROPERTY(Category = "Weapon", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbookComponent> Sprite;

	UPROPERTY(Category = "Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ACLProjectileActor> ProjectileClass;

	UPROPERTY(Category = "Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLWeaponInstance> WeaponInstance;

	UPROPERTY(Category = "Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	EWeaponType WeaponType;

	UPROPERTY()
	USphereComponent* CoreComponent;

	UCLAbilitySystemComponent* GetOwnerAbilitySystemComponent() const;

public:
	/** Returns Sprite subobject **/
	FORCEINLINE class UPaperFlipbookComponent* GetSprite() const { return Sprite; }

};
