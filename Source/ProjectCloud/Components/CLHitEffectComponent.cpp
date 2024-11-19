// Fill out your copyright notice in the Description page of Project Settings.


#include "CLHitEffectComponent.h"
#include "NiagaraComponent.h" 
#include "NiagaraDataInterfaceArrayFunctionLibrary.h"
#include "Materials/Material.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"
#include "PaperFlipbookComponent.h"


// Sets default values for this component's properties
UCLHitEffectComponent::UCLHitEffectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	NiagaraExistTime = 2.5f;
}


// Called when the game starts
void UCLHitEffectComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwnerCharacter())
	{
		OriginaleMaterial = GetOwnerCharacter()->GetSprite()->GetMaterial(0);
	}
}

void UCLHitEffectComponent::PlayHitEffect(float Value)
{
	PlayNiagaraEffect(Value);

	FGameplayCueParameters CueParameters; // 필요에 따라 인수 설정
	CueParameters.Instigator = GetOwner();	
	GetOwnerCharacter()->GetAbilitySystemComponent()->ExecuteGameplayCue(TAG_Cue_HitEffect, CueParameters);
}

void UCLHitEffectComponent::PlayNiagaraEffect(float Value)
{
	if (NiagaraSystem)
	{
		UNiagaraComponent* TempNiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, NiagaraSystem, GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation());

		if (TempNiagaraComponent)
		{
			//TempNiagaraComponent->SetVariableFloat(FName("PlayValue"), Value);
			//TempNiagaraComponent->SetVariableFloat(FName("PlayValue"), Value);
			FVector NSLocation = GetOwner()->GetActorLocation();


			TArray<FVector4> DamageList = UNiagaraDataInterfaceArrayFunctionLibrary::GetNiagaraArrayVector4(TempNiagaraComponent, FName("DamageInfo"));
			DamageList.Add(FVector4(NSLocation.X, NSLocation.Y, 0, Value));
			UNiagaraDataInterfaceArrayFunctionLibrary::SetNiagaraArrayVector4(TempNiagaraComponent, FName("DamageInfo"), DamageList);

			TempNiagaraComponent->Activate(true);

			// 일정 시간 후 나이아가라 컴포넌트 제거
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateUObject(this, &UCLHitEffectComponent::DestroyNiagaraComponent, TempNiagaraComponent), NiagaraExistTime, false);
		}
	}
}

void UCLHitEffectComponent::DestroyNiagaraComponent(UNiagaraComponent* TargetComponent)
{
	if (TargetComponent)
	{
		TargetComponent->DestroyComponent();
	}
}

ACLBaseCharacter* UCLHitEffectComponent::GetOwnerCharacter()
{
	if (GetOwner())
		return Cast<ACLBaseCharacter>(GetOwner());

	return nullptr;
}

void UCLHitEffectComponent::ChangeToEffectMaterial()
{
	if (GetOwnerCharacter() && IsValid(HitEffectOverrideMaterial))
		GetOwnerCharacter()->GetSprite()->SetMaterial(0, HitEffectOverrideMaterial);
}

void UCLHitEffectComponent::ChangeToOriginalMaterial()
{
	if (GetOwnerCharacter() && IsValid(OriginaleMaterial))
		GetOwnerCharacter()->GetSprite()->SetMaterial(0, OriginaleMaterial);
}

const UMaterialInterface* UCLHitEffectComponent::GetEffectMaterial()
{
	return HitEffectOverrideMaterial;
}

const UMaterialInterface* UCLHitEffectComponent::GetOriginalMaterial()
{
	return OriginaleMaterial;
}
