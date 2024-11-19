// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "CLHitEffectComponent.generated.h"

class ACLBaseCharacter;
class UMaterialInterface;

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

	void PlayHitEffect(float Value);

	void PlayNiagaraEffect(float Value);

	void DestroyNiagaraComponent(UNiagaraComponent* NiagaraComp);

	ACLBaseCharacter* GetOwnerCharacter();

	UFUNCTION(BlueprintCallable)
	void ChangeToEffectMaterial();

	UFUNCTION(BlueprintCallable)
	void ChangeToOriginalMaterial();

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	const UMaterialInterface* GetEffectMaterial();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const UMaterialInterface* GetOriginalMaterial();

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInterface> OriginaleMaterial;

	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInterface> HitEffectOverrideMaterial;

	// 나이아가라 시스템 레퍼런스
	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	UNiagaraSystem* NiagaraSystem;

	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	float NiagaraExistTime;
		
};
