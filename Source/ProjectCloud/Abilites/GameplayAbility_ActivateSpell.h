// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbility_ActivateSpell.generated.h"

class ACLProjectileActor;

/**
 * 발동될 스펠 자체 어빌리티
 * 스펠 유틸리티 함수도 추가
 */
UCLASS()
class PROJECTCLOUD_API UGameplayAbility_ActivateSpell : public UGameplayAbility
{
	GENERATED_BODY()

	//마법 시전 어빌리티 관련 유틸함수들 (탄환 생성 등)
public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool ShootMagicProjectiles(int32 count, TSubclassOf<ACLProjectileActor> ProjectileToSpawn);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void ShootProjectilesByPattons();

private:
	bool ShootProjectile(TSubclassOf<ACLProjectileActor> ProjectileToSpawn, FTransform Transform);

	//마법 시전 관련 어빌리티 관련 유틸 변수 (기본 대미지 등)
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spell|Config", meta = (AllowPrivateAccess = "true", UIMin = "0", ClampMin = "0"))
	float BaseDamage = 10;
	
	
};
