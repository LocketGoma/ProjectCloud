// Fill out your copyright notice in the Description page of Project Settings.

#include "CLPlayerController.h"
#include "ProjectCloud/Character/CLPlayerState.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"

ACLPlayerController::ACLPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

ACLPlayerState* ACLPlayerController::GetCLPlayerState() const
{
	return CastChecked<ACLPlayerState>(PlayerState, ECastCheckedType::NullAllowed);
}

UCLAbilitySystemComponent* ACLPlayerController::GetCLAbilitySystemComponent() const
{
	const ACLPlayerState* PS = GetCLPlayerState();

	return (PS? PS->GetAbilitySystemComponent() : nullptr);
}

void ACLPlayerController::ReceivedPlayer()
{
	Super::ReceivedPlayer();
}

void ACLPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ACLPlayerController::SetPlayer(UPlayer* InPlayer)
{
	Super::SetPlayer(InPlayer);
}

void ACLPlayerController::AddCheats(bool bForce)
{
	Super::AddCheats(bForce);
}

void ACLPlayerController::UpdateForceFeedback(IInputInterface* InputInterface, const int32 ControllerId)
{
	Super::UpdateForceFeedback(InputInterface, ControllerId);
}

void ACLPlayerController::UpdateHiddenComponents(const FVector& ViewLocation, TSet<FPrimitiveComponentId>& OutHiddenComponents)
{
	Super::UpdateHiddenComponents(ViewLocation, OutHiddenComponents);
}

void ACLPlayerController::PreProcessInput(const float DeltaTime, const bool bGamePaused)
{
	Super::PreProcessInput(DeltaTime, bGamePaused);
}

void ACLPlayerController::PostProcessInput(const float DeltaTime, const bool bGamePaused)
{	
	if (UCLAbilitySystemComponent* ASC = GetCLAbilitySystemComponent())
	{
		ASC->ProcessAbilityInput(DeltaTime, bGamePaused);
	}

	Super::PostProcessInput(DeltaTime, bGamePaused);
}
