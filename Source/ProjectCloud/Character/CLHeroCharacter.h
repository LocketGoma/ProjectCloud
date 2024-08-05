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
	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadOnly)
	uint32 bAddDefaultMovementBindings : 1;
	//--End of Copy

protected:
	UPROPERTY(VisibleAnywhere, Category = "Character")
	TObjectPtr<UCAttackerNodeComponent> AttackerComponent;

private:
	//nothappa : 디버그 모드
	UPROPERTY(EditDefaultsOnly, Category = "Debug", meta=(AllowPrivateAccess = true))
	bool bDebugMove = false;

};
