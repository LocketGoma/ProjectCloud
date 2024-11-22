// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PlayerStateComponent.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLPlayerSpellManagerComponent.generated.h"

class ACLPlayerState;
class UCLSpellInstance;
class UCLManaAttributeSet;

/**
 * 
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

private:
	TSubclassOf<UCLSpellInstance> GetSpellFromType(EActiveSpellType SpellType);

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
	TWeakObjectPtr<ACLPlayerState> PS;

	TObjectPtr<UCLManaAttributeSet> ManaAttributeSet;

};
