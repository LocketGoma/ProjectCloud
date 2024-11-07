// Fill out your copyright notice in the Description page of Project Settings.

#include "CLProjectileActor.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemGlobals.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"

// Sets default values
ACLProjectileActor::ACLProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));

	CapsuleComponent->InitCapsuleSize(10.0f, 20.0f);
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CapsuleComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	RootComponent = CapsuleComponent;
	NiagaraComponent->SetupAttachment(RootComponent);

	if (MovementComponent)
	{
		//MovementComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		MovementComponent->UpdatedComponent = RootComponent;
		MovementComponent->InitialSpeed = 75.0f;
		MovementComponent->MaxSpeed = 1000.0f;
		MovementComponent->bRotationFollowsVelocity = true;
		MovementComponent->bShouldBounce = false;
		MovementComponent->ProjectileGravityScale = 0.0f; // No gravity effect

		//XY평면에서만 움직이게 처리
		MovementComponent->bConstrainToPlane = true;
		MovementComponent->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Z);
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
	MaximimLifetime = 30.f;
	LaunchSpeed = MovementComponent->InitialSpeed;

	CapsuleComponent->OnComponentHit.AddDynamic(this, &ACLProjectileActor::OnHit);
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
		
	GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &ACLProjectileActor::ActiveDestroyEvent, MaximimLifetime, false);
}

void ACLProjectileActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearTimer(DestroyTimerHandle);
	DestroyTimerHandle.Invalidate();
}

void ACLProjectileActor::Tick(float DeltaTime)
{
	if (NiagaraComponent)
	{
		NiagaraComponent->SetWorldLocation(GetActorLocation());
	}
}

void ACLProjectileActor::LaunchProjectile()
{
	SetNiagaraEffect();
	LaunchVector = FVector(GetActorForwardVector().X, -GetActorForwardVector().Y, GetActorForwardVector().Z);
	MovementComponent->Velocity = LaunchVector * LaunchSpeed;
}

void ACLProjectileActor::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor && (OtherActor != this) && OtherComp) && GetOwner())
	{
		ACLBaseCharacter* SourceOwner = Cast<ACLBaseCharacter>(GetOwner());

		UCLAbilitySystemComponent* SourceASC = SourceOwner->GetAbilitySystemComponent();
		UCLAbilitySystemComponent* TargetASC = OtherActor->FindComponentByClass<UCLAbilitySystemComponent>();
		if (SourceASC && TargetASC)
		{
			//인스티게이터 = Source / 타겟 = Target
			FGameplayEffectContextHandle EffectContext = FGameplayEffectContextHandle(UAbilitySystemGlobals::Get().AllocGameplayEffectContext());
			//FGameplayEffectContextHandle EffectContext = TargetASC->MakeEffectContext();
			EffectContext.AddSourceObject(this);
			EffectContext.AddHitResult(Hit);
			EffectContext.AddInstigator(TargetASC->GetOwnerActor(), SourceASC->GetOwnerActor());

			FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(DamageGE, 1, EffectContext);

			if (SpecHandle.IsValid())
			{
				SourceASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), TargetASC);
			}
		}
		Destroy();
	}
}

void ACLProjectileActor::ActiveDestroyEvent()
{
	Destroy();
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
	NiagaraComponent->SetFloatParameter("SpriteRotation", -1 * UKismetMathLibrary::MakeRotFromX(GetActorRightVector()).Yaw);
	NiagaraComponent->SetFloatParameter("SpriteSize", EffectSize);

	NiagaraComponent->Activate();	
}
