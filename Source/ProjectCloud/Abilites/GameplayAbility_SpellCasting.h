// Copyright @Locketgoma. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "GameplayAbility_SpellCasting.generated.h"

struct FCloudInputAction;
struct FInputActionValue;
class ACLPlayerState;

/**
 * 스펠 시전을 시도하는 (키 입력) 부분
 */
UCLASS()
class PROJECTCLOUD_API UGameplayAbility_SpellCasting : public UGameplayAbility
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
	void CommandInputPressed(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void TriggerReleased(float TimeHeld);

	void SetSpellCommands();

	ACLPlayerState* GetPlayerState();

private:
	UPROPERTY(EditDefaultsOnly , meta = (AllowPrivateAccess = "true"))
	class UInputAction* Action;

	class UAbilityTask_WaitInputRelease* Task;

};
