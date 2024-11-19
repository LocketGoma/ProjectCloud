// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueNotify_BurstLatent.h"
#include "CLGameplayCue_HitEffect.generated.h"

class ACLBaseCharacter;
class UCLHitEffectComponent;

UCLASS()
class PROJECTCLOUD_API ACLGameplayCue_HitEffect : public AGameplayCueNotify_BurstLatent
{
	GENERATED_BODY()

public:
	ACLGameplayCue_HitEffect();

	virtual bool Recycle() override;

	virtual bool OnExecute_Implementation(AActor* Target, const FGameplayCueParameters& Parameters) override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UCLHitEffectComponent* GetHitEffectComponent();

private:
	UPROPERTY(BlueprintReadOnly, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	TWeakObjectPtr<ACLBaseCharacter> OwnerCharacter;

	UPROPERTY(BlueprintReadOnly, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	TWeakObjectPtr<UCLHitEffectComponent> HitEffectComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects", meta = (AllowPrivateAccess = "true", UIMIn = "1", UIMax = "100", ClampMin = "0"))
	int EffectCount;

	UPROPERTY(BlueprintReadWrite, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	int RemainEffectCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects", meta = (AllowPrivateAccess = "true", UIMIn = "0", UIMax = "10", ClampMin = "0"))
	float EffectPlayInterval;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects", meta = (AllowPrivateAccess = "true", UIMIn = "0", UIMax = "10", ClampMin = "0"))
	float OriginalPlayInterval;
};
