// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbility_Passive.generated.h"

class UGameplayEffect;

/**
 * 패시브 어빌리티용 어빌리티 클래스
 */
UCLASS()
class PROJECTCLOUD_API UGameplayAbility_Passive : public UGameplayAbility
{
	GENERATED_BODY()

public:
	//어빌리티 등록
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec);

	//어빌리티 실행조건 검사
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;

	//어빌리티 실행
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);

	//어빌리티 종료
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled);

private:
	FTimerHandle PassiveEventHandle;

	//패시브 어빌리티 메인 기능 (여기다가 회복기능 넣고 패시브 간격별로 돌려도되고..)
	UPROPERTY(EditDefaultsOnly, category="Passive", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayEffect> PassiveEffect;

	//패시브가 특정 시간마다 발동되는 기능을 가졌다면 해당 간격
	UPROPERTY(EditDefaultsOnly, category="Passive|Option", meta = (AllowPrivateAccess = "true", UIMin = "0", UiMax = "100", ClampMin = "0", ClampMax = "100"))
	float PassiveInterval = 0;

	//패시브가 특정 시간마다 발동되는 기능을 가졌는지
	UPROPERTY(EditDefaultsOnly, category="Passive|Option", meta = (AllowPrivateAccess = "true"))
	bool bIntervalPassive = true;
	
	
};
