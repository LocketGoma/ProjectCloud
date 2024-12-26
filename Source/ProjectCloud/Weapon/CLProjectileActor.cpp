// Fill out your copyright notice in the Description page of Project Settings.

#include "CLProjectileActor.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Sound/SoundCue.h"
#include "Kismet/KismetMathLibrary.h"
#include "AbilitySystemGlobals.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "Curves/CurveVector.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectCloud/Utilites/CLCommonUtilityFunction.h"

FName ACLProjectileActor::SpriteComponentName(TEXT("MainSprite"));
// Sets default values
ACLProjectileActor::ACLProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));	
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));

	NiagaraComponents.Add(CreateDefaultSubobject<UNiagaraComponent>(TEXT("MainNiagaraComponent")));
	NiagaraComponents.Add(CreateDefaultSubobject<UNiagaraComponent>(TEXT("SubNiagaraComponent")));
	NiagaraComponents.Add(CreateDefaultSubobject<UNiagaraComponent>(TEXT("TrailNiagaraComponent")));
	NiagaraComponents[0]->SetupAttachment(RootComponent);
	NiagaraComponents[1]->SetupAttachment(RootComponent);
	NiagaraComponents[2]->SetupAttachment(RootComponent);

	CapsuleComponent->InitCapsuleSize(16.0f, 8.f);
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CapsuleComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	RootComponent = CapsuleComponent;	

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

	// Try to create the sprite component
	Sprite = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>(ACLProjectileActor::SpriteComponentName);
	if (Sprite)
	{
		Sprite->AlwaysLoadOnClient = true;
		Sprite->AlwaysLoadOnServer = true;
		Sprite->bOwnerNoSee = false;
		Sprite->bAffectDynamicIndirectLighting = true;
		Sprite->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Sprite->SetupAttachment(RootComponent);
		static FName CollisionProfileName(TEXT("ObjectMesh"));
		Sprite->SetCollisionProfileName(CollisionProfileName);
		Sprite->SetGenerateOverlapEvents(false);
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
	BaseDamageFromWeapon = 1.f;
	MainEffectSize = 100.f;	
	SubEffectSize = 200.f;
	MaximimLifetime = 30.f;
	bDestroyWhenHit = true;
	bStartLaunch = false;
	LaunchSpeed = MovementComponent->InitialSpeed;
	
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ACLProjectileActor::OnComponentBeginOverlap);
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

	if (ProjectileType == EProjectileType::Projectile_Chaser)
	{
		FindNextNearestTarget();
	}
}

void ACLProjectileActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	for (UNiagaraComponent* NiagaraComponent : NiagaraComponents)
	{
		if (NiagaraComponent)
		{
			NiagaraComponent->Deactivate();
			NiagaraComponent->DestroyComponent();
		}
	}
	NiagaraComponents.Empty();

	if (DestroyTimerHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DestroyTimerHandle);
		DestroyTimerHandle.Invalidate();
	}
}

void ACLProjectileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	

	//틱에 들어가기엔 좀 무거운데
	if (bStartLaunch && CurveData)
	{	
		double LaunchTime = (GetWorld()->GetTimeSeconds() - StartTime);

		AdditionalVector = Cast<UCurveVector>(CurveData)->GetVectorValue(LaunchTime);
		if (ProjectileType == EProjectileType::Projectile_Chaser)
		{
			if (TargetCharacter.IsValid())
			{
				FVector TargetCharacterLocation = TargetCharacter->GetActorLocation();

				double ToTargetRange = (TargetCharacterLocation - StartLocation).Size() + 1;
				SetActorLocation(FMath::Lerp(StartLocation, TargetCharacterLocation, (LaunchSpeed * LaunchTime) / ToTargetRange));
				SetActorRotation(UKismetMathLibrary::MakeRotFromX(TargetCharacterLocation - StartLocation));
			}
			UpdateNiagaraEffectTransform();

		}
		//이거 말고 다른 방법 없을까......... 계산된 최종 좌표는 유지한채 액터 위치만 바꾸고싶음
		AddActorWorldOffset(AdditionalVector);
	}
	else
	{
		UpdateNiagaraEffectLotation();
	}
}

//근데 유도탄 쐈을때 적이 사라지면 이동은 어케됨? 꺾나 아님 원래위치로 떨어져서 박나
void ACLProjectileActor::LaunchProjectile()
{
	SetNiagaraEffect();
	StartLocation = GetActorLocation();	

	if ((ProjectileType != EProjectileType::Projectile_Chaser) || !TargetCharacter.IsValid())
	{
		LaunchVector = FVector(GetActorForwardVector().X, -GetActorForwardVector().Y, GetActorForwardVector().Z);
		MovementComponent->Velocity = LaunchVector * LaunchSpeed;
	}

	if (LaunchSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, LaunchSound, GetActorLocation());
	}

	StartTime = GetWorld()->GetTimeSeconds();

	bStartLaunch = true;
}

void ACLProjectileActor::SetTargetCharacter(ACLBaseCharacter* NewTarget)
{
	if (NewTarget)
	{		
		NewTarget->OnOutOfHealth.AddUObject(this, &ThisClass::FindNextNearestTarget);
	}

	TargetCharacter = NewTarget;
	
	//추적시간 업데이트 필요
	StartLocation = GetActorLocation();
	StartTime = GetWorld()->GetTimeSeconds();
}


void ACLProjectileActor::FindNextNearestTarget()
{
	if (TargetCharacter.IsValid())
	{
		TargetCharacter->OnOutOfHealth.RemoveAll(this);
	}

	TArray<AActor*> Enemies = CLCommonUtilites::GetSpawnedEnemies(GetWorld(), true);

	AActor* Target = nullptr;
	double MinLength = FLT_MAX;
	for (AActor* Actor : Enemies)
	{
		if (Actor && Actor != TargetCharacter && !Actor->IsActorBeingDestroyed())
		{
			double TargetLength = (Actor->GetActorLocation() - GetActorLocation()).Length();
			if (MinLength > TargetLength)
			{
				Target = Actor;
				MinLength = TargetLength;
			}
		}		
	}

	SetTargetCharacter(Cast<ACLBaseCharacter>(Target));
}

void ACLProjectileActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Launch 전에는 충돌 처리 X
	if (!bStartLaunch)
	{
		return;
	}
	
	if ((OtherActor && (OtherActor != this) && OtherComp) && (GetOwner() && (GetOwner() != OtherActor)))
	{

		if (bIsPrecision)
		{
			//타겟이 정확해야지만 추적 가능한 경우
			if ((TargetCharacter.IsValid()) && (OtherActor != TargetCharacter))
			{
				return;
			}
		}

		ACLBaseCharacter* SourceOwner = Cast<ACLBaseCharacter>(GetOwner());

		UCLAbilitySystemComponent* SourceASC = SourceOwner->GetAbilitySystemComponent();
		UCLAbilitySystemComponent* TargetASC = OtherActor->FindComponentByClass<UCLAbilitySystemComponent>();
		if (SourceASC && TargetASC)
		{
			//인스티게이터 = Source / 타겟 = Target
			FGameplayEffectContextHandle EffectContext = FGameplayEffectContextHandle(UAbilitySystemGlobals::Get().AllocGameplayEffectContext());
			EffectContext.AddSourceObject(this);
			EffectContext.AddHitResult(SweepResult);
			EffectContext.AddInstigator(TargetASC->GetOwnerActor(), SourceASC->GetOwnerActor());			

			FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(GameplayEffect, 1, EffectContext);

			if (SpecHandle.IsValid())
			{
				SourceASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), TargetASC);
			}
		}

		if (ExplosionSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, ExplosionSound, GetActorLocation());
		}
		
		if (bDestroyWhenHit)
		{
			ActiveDestroyEvent();
		}
	}
}

void ACLProjectileActor::ActiveDestroyEvent()
{
	if (DestroySound)
	{		
		UGameplayStatics::PlaySoundAtLocation(this, DestroySound, GetActorLocation());
	}

	Destroy();
}


void ACLProjectileActor::SetNiagaraEffect()
{
	if (!(MainVFX) && !(Sprite->GetFlipbook()))
	{
		UE_LOG(LogTemp, Error, TEXT("ACLProjectileActor[ %s ] are Not Have MainVFX & Sprite. That Actor must have MainVFX or Sprite. Fix It."), *GetName());
		return;
	}

	if (MainVFX)
	{
		NiagaraComponents[0]->SetAsset(MainVFX);
		NiagaraComponents[0]->SetWorldLocation(GetActorLocation());

		NiagaraComponents[0]->SetFloatParameter("SpriteRotation", -1 * UKismetMathLibrary::MakeRotFromX(GetActorRightVector()).Yaw);
		NiagaraComponents[0]->SetFloatParameter("SpriteSize", MainEffectSize);
		NiagaraComponents[0]->Activate();
	}

	if (SubVFX)
	{
		NiagaraComponents[1]->SetAsset(SubVFX);
		NiagaraComponents[1]->SetWorldLocation(GetActorLocation());

		NiagaraComponents[1]->SetFloatParameter("SpriteRotation", -1 * UKismetMathLibrary::MakeRotFromX(GetActorRightVector()).Yaw);
		NiagaraComponents[1]->SetFloatParameter("SpriteSize", SubEffectSize);
		NiagaraComponents[1]->Activate();
	}

	if (TrailVFX)	
	{
		NiagaraComponents[2]->SetAsset(TrailVFX);
		NiagaraComponents[2]->SetWorldLocation(GetActorLocation());

		NiagaraComponents[2]->SetFloatParameter("SpriteRotation", -1 * UKismetMathLibrary::MakeRotFromX(GetActorRightVector()).Yaw);
		NiagaraComponents[2]->SetFloatParameter("SpriteSize", SubEffectSize);
		NiagaraComponents[2]->SetFloatParameter("TrailLength", TrailLength);

		NiagaraComponents[2]->Activate();
	}
}

void ACLProjectileActor::UpdateNiagaraEffectLotation()
{
	for (UNiagaraComponent* NiagaraComponent : NiagaraComponents)
	{
		if (NiagaraComponent)
		{
			NiagaraComponent->SetWorldLocation(GetActorLocation());
		}
	}
}

void ACLProjectileActor::UpdateNiagaraEffectTransform()
{
	for (UNiagaraComponent* NiagaraComponent : NiagaraComponents)
	{
		if (NiagaraComponent)
		{
			NiagaraComponent->SetWorldLocation(GetActorLocation());	
			NiagaraComponent->SetFloatParameter("SpriteRotation", UKismetMathLibrary::MakeRotFromX(GetActorForwardVector()).Yaw);
		}
	}
}
