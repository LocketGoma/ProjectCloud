// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CLBaseCharacter.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
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

class UCLAttackerNodeComponent;
class UCLExperienceComponent;
class UInputMappingContext;
class UInputAction;
class UCLAbilityInputConfig;
class UCLCharacterAttributeSet;
class ACLEquipmentActor;
class ACLWeapon;
class ACLSubActionEquipment;
struct FGameplayTag;
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

public:
	virtual void HandleHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue) override;
	virtual void HandleMaxHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue) override;
	virtual void HandleOutOfHealth(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue) override;

//--Get/Set

	virtual void SetAbilitySystemComponent() override;

	virtual UCLAbilitySystemComponent* GetAbilitySystemComponent() override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Equipment|Weapon")
	UCLAttackerNodeComponent* GetAttackerNode();


	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Equipment")
	ACLEquipmentActor* GetEquipmentActor(EEquipmentType EquipmentType);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Equipment")
	ACLWeapon* GetWeaponActor();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Equipment")
	ACLSubActionEquipment* GetSubEquipmentActor();

	virtual float GetHealth() override;

//Native Actions
protected:
	/** Called for movement input */
	void Input_Move(const FInputActionValue& Value);
	void Input_AbilityInputTagTriggered(FGameplayTag InputTag);
	void Input_AbilityInputTagPressed(FGameplayTag InputTag);
	void Input_AbilityInputTagReleased(FGameplayTag InputTag);
	void Input_LookMouse(const FInputActionValue& InputActionValue);

	void RotateAttackPoint(float Val);
	void TrackingMousePosition(FVector Position);
	void TrackingMousePosition(FVector2D Position);

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

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character|Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character|Input", meta = (AllowPrivateAccess = "true"))
	UCLAbilityInputConfig* InputConfig;
	
protected:
	UPROPERTY(VisibleAnywhere, Category = "Character")
	TObjectPtr<UCLAttackerNodeComponent> AttackerComponent;
};
