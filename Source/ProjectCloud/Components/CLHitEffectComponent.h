// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "CLHitEffectComponent.generated.h"


//BaseCharacter에 HitDelegate 정보를 받아서 (대미지 정보) 해당 델리게이트 발동시 머리 위에 대미지 수치 띄워주는 컴포넌트
UCLASS()
class PROJECTCLOUD_API UCLHitEffectComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCLHitEffectComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	void PlayNiagaraEffect(float Value);

	void DestroyNiagaraComponent(UNiagaraComponent* NiagaraComp);

private:
	// 나이아가라 시스템 레퍼런스
	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	UNiagaraSystem* NiagaraSystem;

	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	float NiagaraExistTime;
		
};
