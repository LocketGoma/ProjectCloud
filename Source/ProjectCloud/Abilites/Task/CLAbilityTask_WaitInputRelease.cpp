// Fill out your copyright notice in the Description page of Project Settings.


#include "CLAbilityTask_WaitInputRelease.h"
#include "AbilitySystemComponent.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"

void UCLAbilityTask_WaitInputRelease::Activate()
{
	ENetMode NetMode = GEngine->GetNetMode(GetWorld());
	if (NetMode == ENetMode::NM_Standalone)
	{
		StartTime = GetWorld()->GetTimeSeconds();

		UCLAbilitySystemComponent* ASC = Cast<UCLAbilitySystemComponent>(AbilitySystemComponent.Get());
		if (ASC && Ability)
		{
			if (bTestInitialState && IsLocallyControlled())
			{
				FGameplayAbilitySpec* Spec = Ability->GetCurrentAbilitySpec();
				if (Spec && !Spec->InputPressed)
				{
					OnReleaseCallback();
					return;
				}
			}		

			DelegateHandle = ASC->OnInputReleased.AddUObject(this, &UCLAbilityTask_WaitInputRelease::OnReleaseCallbackHandle);
		}		
	}
	else
	{
		Super::Activate();
	}
}

void UCLAbilityTask_WaitInputRelease::OnReleaseCallbackHandle()
{
	OnReleaseCallback();
	DelegateHandle.Reset();
}

UCLAbilityTask_WaitInputRelease* UCLAbilityTask_WaitInputRelease::CloudWaitInputRelease(UGameplayAbility* OwningAbility, bool bTestAlreadyReleased)
{
	UCLAbilityTask_WaitInputRelease* Task = NewAbilityTask<UCLAbilityTask_WaitInputRelease>(OwningAbility);
	Task->bTestInitialState = bTestAlreadyReleased;
	return Task;
}
