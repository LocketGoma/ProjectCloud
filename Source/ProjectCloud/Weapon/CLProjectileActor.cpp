// Fill out your copyright notice in the Description page of Project Settings.

#include "CLProjectileActor.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACLProjectileActor::ACLProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));
	MovementComponent = CreateDefaultSubobject<UCharacterMovementComponent>(TEXT("MovementComponent"));

	CapsuleComponent->InitCapsuleSize(4.0f, 20.0f);
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CapsuleComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	RootComponent = CapsuleComponent;
	NiagaraComponent->SetupAttachment(RootComponent);

	if (MovementComponent)
	{
		//MovementComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		MovementComponent->UpdatedComponent = RootComponent;
		MovementComponent->UpdateNavAgent(*CapsuleComponent);
		MovementComponent->SetDefaultMovementMode();
	}

#if WITH_EDITORONLY_DATA
	ArrowComponent = CreateEditorOnlyDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	if (ArrowComponent)
	{
		ArrowComponent->ArrowColor = FColor(150, 200, 255);
		ArrowComponent->bTreatAsASprite = true;
		ArrowComponent->SetupAttachment(CapsuleComponent);
		ArrowComponent->bIsScreenSizeScaled = true;
		ArrowComponent->SetSimulatePhysics(false);
	}
#endif // WITH_EDITORONLY_DATA


	//변수 초기화
	EffectSize = 100.f;
	LaunchVector = FVector::ZeroVector;
	LaunchSpeed = 100.f;
}

// Called when the game starts or when spawned
void ACLProjectileActor::BeginPlay()
{
	Super::BeginPlay();

#if WITH_EDITORONLY_DATA
	if (ArrowComponent)
	{
		ArrowComponent->SetSimulatePhysics(false);
	}
#endif // WITH_EDITORONLY_DATA

}

void ACLProjectileActor::LaunchProjectile()
{
	SetNiagaraEffect();

	MovementComponent->Launch(LaunchVector * LaunchSpeed);
}

void ACLProjectileActor::SetNiagaraEffect()
{
	if (!ensure(MainVFX))
	{
		UE_LOG(LogTemp, Error, TEXT("Some of ACLProjectileActor(%s) are Not Have MainVFX. That Actor must have MainVFX. Fix It."), *GetName());
		return;
	}
	NiagaraComponent->SetAsset(MainVFX);
	//그냥 나이아가라컴포넌트 여러개 만들래요
	//UNiagaraFunctionLibrary::SpawnSystemAttached(MainVFX, NiagaraComponent, FName(), FVector::ZeroVector, GetActorRotation(), EAttachLocation::SnapToTarget, true, true);

	//if (SubVFX)
	//{
	//	UNiagaraFunctionLibrary::SpawnSystemAttached(SubVFX, NiagaraComponent, FName(), FVector::ZeroVector, GetActorRotation(), EAttachLocation::SnapToTarget, true, true);
	//}

	//if (TrailVFX)
	//{
	//	UNiagaraFunctionLibrary::SpawnSystemAttached(TrailVFX, NiagaraComponent, FName(), FVector::ZeroVector, GetActorRotation(), EAttachLocation::SnapToTarget, true, true);
	//}
	NiagaraComponent->SetFloatParameter("SpriteRotation", -1 * UKismetMathLibrary::MakeRotFromX(GetActorRightVector()).Yaw);	NiagaraComponent->SetFloatParameter("SpriteSize", EffectSize);

	NiagaraComponent->Activate();	
}
