// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PlayerStateComponent.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLPlayerSpellManagerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCLSpellEventDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCLSpellCommandDelegate, EArrowInputHandleType, inputCommand);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCLManaAmountDelegate, float, Amount);

class ACLPlayerState;
class UCLSpellInstance;
class UCLManaAttributeSet;
class UGameplayEffect;

/**
 * 스펠 정보 관리 + 스펠 발동 여부 검사하는 컴포넌트
 */
UCLASS()
class PROJECTCLOUD_API UCLPlayerSpellManagerComponent : public UPlayerStateComponent
{
	GENERATED_BODY()
public:	
	UCLPlayerSpellManagerComponent(const FObjectInitializer& ObjectInitializer);

public:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;

	void InitializeDelegates();
	void InitializeTimer();	

public:
	const TSubclassOf<UCLSpellInstance> GetSpellFromType(EActiveSpellType SpellType);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const TArray<EArrowInputHandleType> GetSpellCommandFromType(EActiveSpellType SpellType);

	void SetSpellFromInstance(TSubclassOf<UCLSpellInstance> NewInstance);

	UFUNCTION()
	void TryCommandInput(EArrowInputHandleType InputCommand);

public:
	UPROPERTY(BlueprintAssignable)
	FCLSpellCommandDelegate OnSpelICommandInput;

	UPROPERTY(BlueprintAssignable)
	FCLSpellEventDelegate OnFullSpellCommandChanged;
	//스펠 입력 액티브 체크
	UPROPERTY(BlueprintAssignable)
	FCLSpellEventDelegate OnTrySpellCommandInput;

	//스펠 액티브 체크
	UPROPERTY(BlueprintAssignable)
	FCLSpellEventDelegate OnTrySpellActivate;

	UPROPERTY(BlueprintAssignable)
	FCLManaAmountDelegate OnManaAdded;

	UPROPERTY(BlueprintAssignable)
	FCLManaAmountDelegate OnManaEdited;

private:
	UFUNCTION()
	void TryActivateSpell();

	void AddMana();

	void ApplyPenaltyManaAmount();

	void ActivateSpell(EActiveSpellType SpellType);

	void UpdateSpellCommands(EActiveSpellType UpdatedSpellType);	

	void ClearSpellCommand();

	bool CheckSpellCorrection(TArray<EArrowInputHandleType> InputCommands);

	EActiveSpellType CheckSpellCommandLevel(TArray<EArrowInputHandleType> InputCommands);

	//Handlers
private:	
	void HandleChangeMana(AActor* Instigator, float Magnitude, float OldValue, float NewValue);
	void HandleAddMana(AActor* Instigator, float Magnitude, float OldValue, float NewAddValue);

private:
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	float RestoreInterval = 0.1f;
	
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayEffect> RestoreManaGameplayEffect;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayEffect> PenaltyManaGameplayEffect;

	//1차 마법
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLSpellInstance> LowSpell;

	//2차 마법
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLSpellInstance> MidSpell;

	//3차 마법
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLSpellInstance> HighSpell;

	//커맨드 처리
private:
	//인풋 들어온 커맨드
	TArray<EArrowInputHandleType> InputSpellCommands;

	//예약 커맨드
	TArray<EArrowInputHandleType> LowSpellCommands;
	TArray<EArrowInputHandleType> MiddleSpellCommands;
	TArray<EArrowInputHandleType> HighSpellCommands; //High = Full

private:
	FTimerHandle ManaRestoreTimerHandle;
	TWeakObjectPtr<ACLPlayerState> PS;	
};
