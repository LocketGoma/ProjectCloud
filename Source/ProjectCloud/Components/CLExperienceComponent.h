// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PlayerStateComponent.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLExperienceComponent.generated.h"

class ACLBaseCharacter;
class ACLPlayerState;
class UDataTable;

//캐릭터 레벨업 및 경험치 정보를 가지고 있는 컴포넌트
//레벨은 PlayerState에 있습니다.

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEarnEXPEventDelegate, int64, OldExp, int64, NewExp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnExprienceValueUpdated, int32, Level, float, NowValue, float, RequireValue);

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent) )
class PROJECTCLOUD_API UCLExperienceComponent : public UPlayerStateComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCLExperienceComponent(const FObjectInitializer& ObjectInitializer);
	
public:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;

	void InitializeDelegates();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const int GetPlayerLevel();	

	int64 GetRequiredExpForLevelUp(int32 NowLevel);

	void UpdateRequireExperience(int32 NowLevel);

public:
	UPROPERTY(BlueprintAssignable)
	FEarnEXPEventDelegate OnEarnExpEvent;

	UPROPERTY(BlueprintAssignable)
	FOnExprienceValueUpdated OnExpUpdated;
	
private:
	UFUNCTION()
	void HandleExphChanged(AActor* Instigator, float Magnitude, float OldValue, float NewValue);

private:
	TWeakObjectPtr<ACLPlayerState> PS;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta =  (AllowPrivateAccess = "true"))
	TObjectPtr<UDataTable> ExperienceTable;
	
	friend class UCLLevelAbilityComponent;
};
