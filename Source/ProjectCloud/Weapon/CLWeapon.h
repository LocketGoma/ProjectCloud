// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLWeapon.generated.h"

class UPaperFlipbookComponent;
class USphereComponent;

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

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const AActor* GetProjectile() const { return Projectile; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const EWeaponType GetWeaponType() const;



private:	
	UPROPERTY(Category = "Weapon", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbookComponent> Sprite;

	UPROPERTY(Category = "Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AActor> Projectile;

	UPROPERTY(Category = "Weapon", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	EWeaponType WeaponType;

	UPROPERTY()
	USphereComponent* CoreComponent;

public:

	/** Returns Sprite subobject **/
	FORCEINLINE class UPaperFlipbookComponent* GetSprite() const { return Sprite; }

};
