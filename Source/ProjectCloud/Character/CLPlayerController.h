// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CLPlayerController.generated.h"

class ACLEquipmentActor;
class ACLPlayerState;
class UCLAbilitySystemComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FCLAmmoStatusUIChanged, int32, MagAmmo, int32, MagSize, int32, SpareAmmo, bool, bInfinite);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCLWeaponReloadUITriggered, float, ReloadTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCEquipmentChanged, ACLEquipmentActor*, EquipmentActor);

/**
 * 
 */
UCLASS()
class PROJECTCLOUD_API ACLPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACLPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "PlayerController")
	ACLPlayerState* GetCLPlayerState() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerController")
	UCLAbilitySystemComponent* GetCLAbilitySystemComponent() const;

	//~APlayerController interface
public:
	virtual void ReceivedPlayer() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetPlayer(UPlayer* InPlayer) override;
	virtual void AddCheats(bool bForce) override;
	virtual void UpdateForceFeedback(IInputInterface* InputInterface, const int32 ControllerId) override;
	virtual void UpdateHiddenComponents(const FVector& ViewLocation, TSet<FPrimitiveComponentId>& OutHiddenComponents) override;
	virtual void PreProcessInput(const float DeltaTime, const bool bGamePaused) override;
	virtual void PostProcessInput(const float DeltaTime, const bool bGamePaused) override;
	//~End of APlayerController interface

//UI 관련 Delegate
public:
	//주무기 탄 수 변경
	UPROPERTY(BlueprintAssignable)
	FCLAmmoStatusUIChanged OnWeaponAmmoStatusUIChanged;

	//보조장비 탄 수 변경. 이 경우 유효는 1번 파라미터
	UPROPERTY(BlueprintAssignable)
	FCLAmmoStatusUIChanged OnSubEquipmentStatusUIChanged;

	//주무기 재장전
	UPROPERTY(BlueprintAssignable)
	FCLWeaponReloadUITriggered OnWeaponReloadTriggered;

	//주무기 변경
	UPROPERTY(BlueprintAssignable)
	FCEquipmentChanged OnWeaponChanged;

	//보조장비 변경
	UPROPERTY(BlueprintAssignable)
	FCEquipmentChanged OnSubEquipmentChanged;
};
