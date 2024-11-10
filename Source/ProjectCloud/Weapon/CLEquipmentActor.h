// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLEquipmentActor.generated.h"

class UPaperFlipbookComponent;
class ACLProjectileActor;
class USphereComponent;
class UCLWeaponInstance;
class UCLAbilitySystemComponent;

//Weapon과 SupEquipment를 통용하는 클래스.

UCLASS()
class PROJECTCLOUD_API ACLEquipmentActor : public AActor
{
	GENERATED_BODY()
	
	// Name of the Sprite component
	static FName SpriteComponentName;

public:	
	// Sets default values for this actor's properties
	ACLEquipmentActor(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetEquipmentFromInstance();

	virtual void ActiveEquipment();
	virtual bool CanActiveEquipment();
	
	virtual void Reload();
	virtual bool CanReload();

//Getter
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	AController* GetOwnerController();
	UCLAbilitySystemComponent* GetOwnerAbilitySystemComponent() const;

protected:
	UPROPERTY(Category = "Config", EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	EEquipmentType EquipmentType;

private:
	UPROPERTY(Category = "Config", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbookComponent> Sprite;

	UPROPERTY()
	USphereComponent* CoreComponent;

public:
	/** Returns Sprite subobject **/
	FORCEINLINE class UPaperFlipbookComponent* GetSprite() const { return Sprite; }

};
