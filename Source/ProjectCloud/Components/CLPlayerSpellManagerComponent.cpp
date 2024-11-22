// Fill out your copyright notice in the Description page of Project Settings.

#include "CLPlayerSpellManagerComponent.h"
#include "Engine/DataTable.h"
#include "ProjectCloud/Spell/CLSpellInstance.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/AttributeSet/CLManaAttributeSet.h"
#include "ProjectCloud/Character/CLPlayerState.h"

UCLPlayerSpellManagerComponent::UCLPlayerSpellManagerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;

	PS = Cast<ACLPlayerState>(GetOwner());
}

void UCLPlayerSpellManagerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCLPlayerSpellManagerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UCLPlayerSpellManagerComponent::InitializeComponent()
{
	Super::InitializeComponent();

	UCLAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
}

void UCLPlayerSpellManagerComponent::UninitializeComponent()
{
	Super::UninitializeComponent();
}

void UCLPlayerSpellManagerComponent::InitializeDelegates()
{
	UCLAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
}

void UCLPlayerSpellManagerComponent::ActivateSpell(EActiveSpellType SpellType)
{
	TSubclassOf<UCLSpellInstance> TryActiveSpell = GetSpellFromType(SpellType);

	if (!TryActiveSpell)
	{
		//실패 판정
		return;
	}
}

TSubclassOf<UCLSpellInstance> UCLPlayerSpellManagerComponent::GetSpellFromType(EActiveSpellType SpellType)
{
	switch (SpellType)
	{
	case EActiveSpellType::Spell_Low:
		return LowSpell;		
	case EActiveSpellType::Spell_Mid:
		return MidSpell;		
	case EActiveSpellType::Spell_High:
		return HighSpell;		
	}

	return nullptr;
}
