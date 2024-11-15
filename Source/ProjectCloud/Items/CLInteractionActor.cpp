// Fill out your copyright notice in the Description page of Project Settings.


#include "CLInteractionActor.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "AbilitySystemGlobals.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"


FName ACLInteractionActor::SpriteComponentName(TEXT("MainSprite"));

// Sets default values
ACLInteractionActor::ACLInteractionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));

	CapsuleComponent->InitCapsuleSize(10.0f, 8.f);
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);	
	CapsuleComponent->SetCollisionProfileName(FName("InteractionActor"), true);

	//획득용 컴포넌트
	SphereComponent->InitSphereRadius(64.f);	
	SphereComponent->SetCollisionProfileName(FName("InteractionCollision"), true);

	RootComponent = CapsuleComponent;
	SphereComponent->SetupAttachment(RootComponent);
	NiagaraComponent->SetupAttachment(RootComponent);

	// Try to create the sprite component
	RenderComponent = CreateOptionalDefaultSubobject<UPaperSpriteComponent>(ACLInteractionActor::SpriteComponentName);
	if (RenderComponent)
	{		
		RenderComponent->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
		RenderComponent->SetupAttachment(RootComponent);
		RenderComponent->SetRelativeScale3D(FVector(0.1, 0.1, 0.1));
		RenderComponent->SetGenerateOverlapEvents(false);	
	}

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ACLInteractionActor::OnComponentBeginOverlap);
}

// Called when the game starts or when spawned
void ACLInteractionActor::BeginPlay()
{
	Super::BeginPlay();
	
	RenderComponent->SetRelativeRotation(FRotator(0, 0, 90));
}

void ACLInteractionActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

// Called every frame
void ACLInteractionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACLInteractionActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor && (OtherActor != this) && OtherComp))
	{		
		ACLBaseCharacter* Target = Cast<ACLBaseCharacter>(OtherActor);

		if (!ensure(Target))
			return;

		UCLAbilitySystemComponent* TargetASC = Target->GetAbilitySystemComponent();

		if (!ensure(TargetASC))
			return;

		//인스티게이터 = Source / 타겟 = Target
		FGameplayEffectContextHandle EffectContext = TargetASC->MakeEffectContext();
		EffectContext.AddSourceObject(this);
		EffectContext.AddHitResult(SweepResult);		

		FGameplayEffectSpecHandle SpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffect, 1, EffectContext);

		if (SpecHandle.IsValid())
		{
			TargetASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), TargetASC);
		}

		Destroy();
	}
}

void ACLInteractionActor::SetActorSprite(UPaperSprite* NewSprite)
{
	if (NewSprite)
	{
		RenderComponent->SetSprite(NewSprite);
	}
}

void ACLInteractionActor::SetNiagaraEffect()
{
}

