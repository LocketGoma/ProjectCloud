// Fill out your copyright notice in the Description page of Project Settings.

#include "CLProjectileActor.h"
#include "Components/CapsuleComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
ACLProjectileActor::ACLProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));

	CapsuleComponent->InitCapsuleSize(10.0f, 20.0f);
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CapsuleComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	RootComponent = Cast<USceneComponent>(CapsuleComponent);
	NiagaraComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACLProjectileActor::BeginPlay()
{
	Super::BeginPlay();

	if (!ensure(MainVFX))
	{
		UE_LOG(LogTemp, Error, TEXT("Some of ACLProjectileActor(%s) are Not Have MainVFX. That Actor must have MainVFX. Fix It."), *GetName());
		return;
	}
	UNiagaraFunctionLibrary::SpawnSystemAttached(MainVFX, NiagaraComponent, FName(), FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::SnapToTarget, true, true);

	if (SubVFX)
	{
		UNiagaraFunctionLibrary::SpawnSystemAttached(SubVFX, NiagaraComponent, FName(), FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::SnapToTarget, true, true);
	}

	if (TrailVFX)
	{
		UNiagaraFunctionLibrary::SpawnSystemAttached(TrailVFX, NiagaraComponent, FName(), FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::SnapToTarget, true, true);
	}

	
}
