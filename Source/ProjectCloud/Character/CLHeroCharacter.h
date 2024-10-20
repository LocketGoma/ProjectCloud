// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CLBaseCharacter.h"
#include "CLHeroCharacter.generated.h"

/**
 * 
 */
//컨트롤 모드 처리용 enum
UENUM()
enum class EControlMode : uint8
{
	Keyboard,
	Gamepad,
	Touch			//or Mouse
};

class UCAttackerNodeComponent;
class UInputMappingContext;
class UInputAction;
class UCLAbilityInputConfig;
class UCLCharacterAttributeSet;
class ACLWeapon;
struct FInputActionValue;

//구조
//어태커 노드에서 무기를 가지고 있음
//무기 정보는 캐릭터 -> 어태커 노드를 통해 획득 (플레이어가 직접 무기 정보를 가지고 있진 않음)

UCLASS()
class PROJECTCLOUD_API ACLHeroCharacter : public ACLBaseCharacter
{
	GENERATED_BODY()

public:
	ACLHeroCharacter(const FObjectInitializer& ObjectInitializer);


	//--Actor Override
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//--End Actor Override

	// Begin Pawn overrides
	virtual void SetupPlayerInputComponent(UInputComponent* InInputComponent) override;
	virtual void UpdateNavigationRelevance() override;
	// End Pawn overrides

	//--Copy From DefaultPawn
	UFUNCTION(BlueprintCallable, Category = "Character")
	virtual void MoveForward(float Val);

	/**
	 * Input callback to strafe right in local space (or left if Val is negative).
	 * @param Val Amount of movement in the right direction (or left if negative).
	 * @see APawn::AddMovementInput()
	 */
	UFUNCTION(BlueprintCallable, Category = "Character")
	virtual void MoveRight(float Val);

	/**
	 * Input callback to move up in world space (or down if Val is negative).
	 * @param Val Amount of movement in the world up direction (or down if negative).
	 * @see APawn::AddMovementInput()
	 */
	UFUNCTION(BlueprintCallable, Category = "Character")
	virtual void MoveUp_World(float Val);

//--Get/Set

	UFUNCTION(BlueprintCallable)
	class APlayerController* GetPlayerController() const;

	virtual void SetAbilitySystemComponent() override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Weapon")
	UCAttackerNodeComponent* GetAttackerNode();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Weapon")
	ACLWeapon* GetWeaponActor();

	virtual float GetHealth() override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	//디버그용
	void BaseAttack(const FInputActionValue& Value);

private:
	void RotateAttackPoint(float Val);

	void TrackingMousePosition(FVector Position);

public:

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	float BaseTurnRate;

	/** Base lookup rate, in deg/sec. Other scaling may affect final lookup rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	float BaseLookUpRate;


public:
	/** If true, adds default input bindings for movement and camera look. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	uint32 bAddDefaultMovementBindings : 1;
	//--End of Copy

private:
	/** MappingContext */
	UPROPERTY(EditDefaultsOnly, Category = "Character|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> InputContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character|Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character|Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character|Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character|Input", meta = (AllowPrivateAccess = "true"))
	UCLAbilityInputConfig* InputConfig;

	UPROPERTY()
	UCLCharacterAttributeSet* AttributeSet;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Character")
	TObjectPtr<UCAttackerNodeComponent> AttackerComponent;


private:
	//nothappa : 디버그 모드
	UPROPERTY(EditDefaultsOnly, Category = "Debug", meta=(AllowPrivateAccess = true))
	bool bDebugMove = false;


};
