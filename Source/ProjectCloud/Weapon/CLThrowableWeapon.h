// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CLWeapon.h"
#include "CLThrowableWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTCLOUD_API ACLThrowableWeapon : public ACLWeapon
{
	GENERATED_BODY()


public:
	//던질 타겟 위치
	UFUNCTION(BlueprintCallable)
	void SetTargetLocation();

	
	//던질때 호출하는 함수
	UFUNCTION(BlueprintCallable)
	void ThrowWeapon();

	//던지는 궤적 함수 (스플라인 이용)
	UFUNCTION(BlueprintImplementableEvent)
	void SetThrowtrajectory();

	//던지는 함수 (타임라인 이용할거임..)
	UFUNCTION(BlueprintImplementableEvent)
	void MoveThrowWeapon();

	//터질때 호출하는 함수 (근데 터지는 조건을 어떻게 하지..?)
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ImpactWeapon();

	//던진 뒤 호출되는 이벤트 함수
	UFUNCTION(BlueprintNativeEvent)
	void K2_ThrowWeapon();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector TargetLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector StartLocation;
		
	//던져질때 최대 높이
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (UIMin = "0", UIMax = "100", ClampMin = "0"))
	float ThrowMaximumHeight = 50;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<class USplineComponent> SplineComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bLaunch;
	
};
