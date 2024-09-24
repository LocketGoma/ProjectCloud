// Fill out your copyright notice in the Description page of Project Settings.

#include "CLWeapon.h"
#include "Components/SphereComponent.h"
#include "PaperFlipbookComponent.h"

FName ACLWeapon::SpriteComponentName(TEXT("Sprite0"));
ACLWeapon::ACLWeapon(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CoreComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CoreComponent"));
	CoreComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CoreComponent->SetCollisionResponseToAllChannels(ECR_Ignore);	
	CoreComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = CoreComponent;

	// Try to create the sprite component
	Sprite = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>(ACLWeapon::SpriteComponentName);
	if (Sprite)
	{
		Sprite->AlwaysLoadOnClient = true;
		Sprite->AlwaysLoadOnServer = true;
		Sprite->bOwnerNoSee = false;
		Sprite->bAffectDynamicIndirectLighting = true;
		Sprite->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Sprite->SetupAttachment(CoreComponent);
		static FName CollisionProfileName(TEXT("ObjectMesh"));
		Sprite->SetCollisionProfileName(CollisionProfileName);
		Sprite->SetGenerateOverlapEvents(false);
	}

	CoreComponent->BodyInstance.bLockZRotation = true;	

	WeaponType = EWeaponType::Weapon_None;

}

// Called when the game starts or when spawned
void ACLWeapon::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ACLWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

const EWeaponType ACLWeapon::GetWeaponType() const
{
	if (!ensureAlways(WeaponType == EWeaponType::Weapon_None))
	{
		UE_LOG(LogTemp, Warning, TEXT("잘못된 무기 타입을 사용하고 있습니다."));
	}


	return WeaponType;
}

