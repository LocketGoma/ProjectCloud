// Copyright @Locketgoma. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "PaperCharacter.h"
#include "CLBaseCharacter.generated.h"

class UInputComponent;
class UPawnMovementComponent;
class UCLAbilitySystemComponent;
class UCLAbilitySet;
class UGameplayEffect;

UCLASS(config = Game, Blueprintable, BlueprintType)
class PROJECTCLOUD_API ACLBaseCharacter : public APaperCharacter
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

	//Health Update 발생시 호출되는 Event
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void UpdateHealthEvent(float ChangedHealth);

//--Getters
	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual float GetHealth() { return 0; }
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsImmunity() { return bImmune; }

	UFUNCTION(BlueprintCallable)
	void SetImmunity(bool NewImmunity);

	UFUNCTION()
	virtual void DeathEvent();

private:
	void ClearImmunityState();

protected:
	//적용시킬 AbilitySet
	UPROPERTY(EditDefaultsOnly, meta = (Category = "Character|Settings"))
	TObjectPtr<UCLAbilitySet> AbilitySet;

	UPROPERTY(EditDefaultsOnly, Category = "Character|Attributes")
	TSubclassOf<UGameplayEffect> AttributeGameplayEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Debug")
	bool bDebug;


private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character|Config", meta = (AllowPrivateAccess = "true", UIMin = "0", ClampMin = "0"))
	float ImmmuneTime;

	FTimerHandle ImmuneTimerHandle;

	bool bImmune;

};
