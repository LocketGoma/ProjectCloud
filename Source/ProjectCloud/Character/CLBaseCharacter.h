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

//다이나믹 델리게이트 - 런타임, BP에서 호출가능, AddDynamic으로 사용
//일반 델리게이트 - 컴파일, 성능상 이점, BP 호출 불가, AddUObject로 사용

DECLARE_MULTICAST_DELEGATE(FCLCharacterStateChangeEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCLCharacterInitializeEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCLCharacterAttributeChanged, float, OldValue, float, NewValue);

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

//이벤트 델리게이트
public:
	UPROPERTY(BlueprintAssignable, Category = "Character")
	FCLCharacterAttributeChanged OnHealthChanged;

	//각종 UI들 초기화할때 사용.
	UPROPERTY(BlueprintAssignable, Category = "Character")
	FCLCharacterInitializeEvent OnCharacterInitialized;
		
	FCLCharacterStateChangeEvent OnOutOfHealth;

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

	TObjectPtr<const class UCLCharacterAttributeSet> HealthAttributeSet;

//무적 처리 관련
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character|Config", meta = (AllowPrivateAccess = "true", UIMin = "0", ClampMin = "0"))
	float ImmmuneTime;

	bool bImmune;
	FTimerHandle ImmuneTimerHandle;
};
