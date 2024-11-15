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
	virtual void SetEquipmentFromInstance();

	virtual void ActiveEquipment();
	virtual bool CanActiveEquipment();
	
	virtual void Reload();
	virtual bool CanReload();	
	virtual void UpdateEquipmentEvent();

//Getter
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	AController* GetOwnerController();
	UCLAbilitySystemComponent* GetOwnerAbilitySystemComponent() const;
	
	//탄창 크기
	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual const int GetMagazineSize() const;

	//잔탄량
	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual const int GetMagazineAmmo() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual const int GetSpareAmmo() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual const bool GetIsInfinite() const;

	//대미지가 되었던, 회복량이 되었던 수치 리턴해주는 함수.
	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual const float GetBaseEquipmentValue() const;


public:
	//데이터테이블에서 키로 사용되는 값 (현지화 무관하게 영어로, 데이터테이블 키값과 동일하게 작성할것)
	UPROPERTY(Category = "Config", EditAnywhere, BlueprintReadOnly)
	FName ActorName;

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
