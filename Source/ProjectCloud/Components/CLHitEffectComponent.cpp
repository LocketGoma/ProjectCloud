// Fill out your copyright notice in the Description page of Project Settings.


#include "CLHitEffectComponent.h"
#include "NiagaraComponent.h" 
#include "NiagaraDataInterfaceArrayFunctionLibrary.h"

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
