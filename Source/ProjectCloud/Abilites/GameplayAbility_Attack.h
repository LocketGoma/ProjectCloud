// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Abilities/GameplayAbility.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "GameplayAbility_Attack.generated.h"

UCLASS()
class PROJECTCLOUD_API UGameplayAbility_Attack : public UGameplayAbility
{
	GENERATED_BODY()

public:
	//어빌리티 실행조건 검사
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;

	//어빌리티 실행
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);
	

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config")
	EEquipmentType EquipmentType;
};
