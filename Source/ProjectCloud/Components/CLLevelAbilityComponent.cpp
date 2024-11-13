// Fill out your copyright notice in the Description page of Project Settings.


#include "CLLevelAbilityComponent.h"
#include "ProjectCloud/Character/CLPlayerState.h"

UCLLevelAbilityComponent::UCLLevelAbilityComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;

	PS = Cast<ACLPlayerState>(GetOwner());
}

void UCLLevelAbilityComponent::BeginPlay()
{
	Super::BeginPlay();	
}

void UCLLevelAbilityComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UCLLevelAbilityComponent::InitializeComponent()
{
	Super::InitializeComponent();
}

void UCLLevelAbilityComponent::UninitializeComponent()
{
	Super::UninitializeComponent();
}

void UCLLevelAbilityComponent::InitializeDelegates()
{
}

const int UCLLevelAbilityComponent::GetPlayerLevel()
{
	if (!ensure(PS.Get()))
	{
		return 0;
	}

	return PS->GetPlayerLevel();
}
