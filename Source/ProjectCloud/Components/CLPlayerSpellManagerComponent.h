// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PlayerStateComponent.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLPlayerSpellManagerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCLSpellCommandDelegate);

class ACLPlayerState;
class UCLSpellInstance;
class UCLManaAttributeSet;

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

public:
	void ActivateSpell(EActiveSpellType SpellType);

	const TSubclassOf<UCLSpellInstance> GetSpellFromType(EActiveSpellType SpellType);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const TArray<EArrowInputHandleType> GetSpellCommandFromType(EActiveSpellType SpellType);

	void SetSpellFromInstance(TSubclassOf<UCLSpellInstance> NewInstance);


public:
	UPROPERTY(BlueprintAssignable)
	FCLSpellCommandDelegate OnSpelICommandInput;

	UPROPERTY(BlueprintAssignable)
	FCLSpellCommandDelegate OnFullSpellCommandChanged;

private:
	void UpdateSpellCommands(EActiveSpellType UpdatedSpellType);

private:
	//1차 마법
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLSpellInstance> LowSpell;

	//2차 마법
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLSpellInstance> MidSpell;

	//3차 마법
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLSpellInstance> HighSpell;

private:
	TArray<EArrowInputHandleType> LowSpellCommands;
	TArray<EArrowInputHandleType> MiddleSpellCommands;
	TArray<EArrowInputHandleType> HighSpellCommands; //High = Full

private:
	TWeakObjectPtr<ACLPlayerState> PS;

	TObjectPtr<UCLManaAttributeSet> ManaAttributeSet;

};
