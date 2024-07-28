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

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	UFUNCTION(BlueprintCallable, Category = "Character")
	virtual void TurnAtRate(float Rate);

	/**
	* Called via input to look up at a given rate (or down if Rate is negative).
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	UFUNCTION(BlueprintCallable, Category = "Character")
	virtual void LookUpAtRate(float Rate);

private:	
	void RotateAttackPoint(float Val);

public:

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	float BaseTurnRate;

	/** Base lookup rate, in deg/sec. Other scaling may affect final lookup rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	float BaseLookUpRate;


public:
	/** If true, adds default input bindings for movement and camera look. */
	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadOnly)
	uint32 bAddDefaultMovementBindings : 1;
	//--End of Copy

protected:
	//nothappa : 공격 지점 컴포넌트 BP 원본
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character")
	TSubclassOf<UCAttackerNodeComponent> AttackerComponentBP;


private:
	//nothappa : 키보드 움직임 활성화여부 (기본 - 비활성)
	UPROPERTY(EditDefaultsOnly, Category = "Debug", meta=(AllowPrivateAccess = true))
	bool bDebugMove = false;

	//nothappa : 자유 카메라
	UPROPERTY(EditDefaultsOnly, Category = "Debug", meta=(AllowPrivateAccess = true))
	bool bFreeCamera = false;

	UPROPERTY(VisibleAnywhere, Category = "Character")
	TObjectPtr<UCAttackerNodeComponent> AttackerComponent;
};
