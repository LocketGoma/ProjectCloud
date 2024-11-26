// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_WaitInputRelease.h"
#include "CLAbilityTask_WaitInputRelease.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTCLOUD_API UCLAbilityTask_WaitInputRelease : public UAbilityTask_WaitInputRelease
{
	GENERATED_BODY()

	virtual void Activate() override;
	
	void OnReleaseCallbackHandle();

public:
	UFUNCTION(BlueprintCallable, Category = "Cloud|Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UCLAbilityTask_WaitInputRelease* CloudWaitInputRelease(UGameplayAbility* OwningAbility, bool bTestAlreadyReleased = false);


};
