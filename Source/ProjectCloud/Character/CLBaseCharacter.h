// Copyright @Locketgoma. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "PaperZDCharacter.h"
#include "CLBaseCharacter.generated.h"

struct FGameplayEffectSpec;
class UInputComponent;
class UPawnMovementComponent;
class UCLAbilitySystemComponent;
class UCLAbilitySet;
class UGameplayEffect;

UCLASS(config = Game, Blueprintable, BlueprintType)
class PROJECTCLOUD_API ACLBaseCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	ACLBaseCharacter(const FObjectInitializer& ObjectInitializer);	

//--Actor Override
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

//--End Actor Override
	virtual void SetAbilitySystemComponent() PURE_VIRTUAL(ACLBaseCharacter::SetAbilitySystemComponent, );

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual UCLAbilitySystemComponent* GetAbilitySystemComponent();

	virtual void InitializeAbilitySystemComponent(UCLAbilitySystemComponent* ASC);
	virtual void UnInitializeAbilitySystemComponent();

	virtual void HandleHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue);
	virtual void HandleMaxHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue);
	virtual void HandleOutOfHealth(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue);

//--Getters
	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual float GetHealth() { return 0; }
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsImmunity() { return bImmune; }
		

	UFUNCTION()
	virtual void DeathEvent();

private:
	void ClearImmunityState();
	void SetImmunity(bool NewImmunity);

protected:
	//적용시킬 AbilitySet
	UPROPERTY(EditDefaultsOnly, meta = (Category = "Character|Settings"))
	TObjectPtr<UCLAbilitySet> AbilitySet;

	UPROPERTY(EditDefaultsOnly, Category = "Character|Attributes")
	TSubclassOf<UGameplayEffect> AttributeGameplayEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Debug")
	bool bDebug;

	TObjectPtr<const class UCLCharacterAttributeSet> AttributeSet;

//무적 처리 관련
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character|Config", meta = (AllowPrivateAccess = "true", UIMin = "0", ClampMin = "0"))
	float ImmmuneTime;
	bool bImmune;
	FTimerHandle ImmuneTimerHandle;

};
