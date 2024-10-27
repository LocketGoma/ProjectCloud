// Fill out your copyright notice in the Description page of Project Settings.

#include "CLWeapon.h"
#include "Components/SphereComponent.h"
#include "PaperFlipbookComponent.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Weapon/CLWeaponInstance.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"
#include "ProjectCloud/Weapon/CLProjectileActor.h"

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

void ACLWeapon::SetWeaponFromInstance()
{
	if (!(ensure(WeaponInstance)) || !(ensure(GetOwner())))
	{
		return;
	}

	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return;
	}

	ASC->AddLooseGameplayTag(WeaponInstance.GetDefaultObject()->MagazineAmmo.KeyTag, WeaponInstance.GetDefaultObject()->MagazineAmmo.Value);
	ASC->AddLooseGameplayTag(WeaponInstance.GetDefaultObject()->MagazineSize.KeyTag, WeaponInstance.GetDefaultObject()->MagazineSize.Value);
	ASC->AddLooseGameplayTag(WeaponInstance.GetDefaultObject()->SpareAmmo.KeyTag, WeaponInstance.GetDefaultObject()->SpareAmmo.Value);	

}

void ACLWeapon::Attack_Implementation()
{
	if (GetMagazineAmmo() > 0)
	{
		UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

		if (!ensure(ASC))
		{
			return;
		}

		ASC->RemoveLooseGameplayTag(WeaponInstance.GetDefaultObject()->MagazineAmmo.KeyTag, 1);

		FRotator Rotation = GetRootComponent()->GetRelativeRotation();
		ACLProjectileActor* Projectile = GetWorld()->SpawnActor<ACLProjectileActor>(ProjectileClass, GetActorLocation(), Rotation);
		Projectile->LaunchVector = GetActorForwardVector();
		Projectile->LaunchProjectile();

	}
	else
	{
		FTimerHandle TempHandle;
		GetWorld()->GetTimerManager().SetTimer(TempHandle, this, &ACLWeapon::Reload, 1.5f, false);
	}

	//To do 
	/*
	* 1. 탄 쏠때 탄환 남았는지 체크	
	* 2. 남아있으면 1발 줄이고 발사
	* 3. 없으면 자동 재장전
	*/
}

void ACLWeapon::Reload_Implementation()
{
	if (!ensure(WeaponInstance))
	{
		return;
	}
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return;
	}
	//Mag Size만큼 Mag Ammo 채움
	ASC->SetLooseGameplayTagCount(WeaponInstance.GetDefaultObject()->MagazineAmmo.KeyTag, WeaponInstance.GetDefaultObject()->MagazineSize.Value);

}

const EWeaponType ACLWeapon::GetWeaponType() const
{
	if (!ensureAlways(WeaponType == EWeaponType::Weapon_None))
	{
		UE_LOG(LogTemp, Warning, TEXT("잘못된 무기 타입을 사용하고 있습니다."));
	}
	return WeaponType;
}

const int ACLWeapon::GetMagazineSize()
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return -1;
	}
	return ASC->GetGameplayTagCount(WeaponInstance.GetDefaultObject()->MagazineSize.KeyTag);	
}

const int ACLWeapon::GetMagazineAmmo()
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return -1;
	}
	return ASC->GetGameplayTagCount(WeaponInstance.GetDefaultObject()->MagazineAmmo.KeyTag);
}

const int ACLWeapon::GetSpareAmmo()
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return -1;
	}
	return ASC->GetGameplayTagCount(WeaponInstance.GetDefaultObject()->SpareAmmo.KeyTag);
}

UCLAbilitySystemComponent* ACLWeapon::GetOwnerAbilitySystemComponent() const
{
	if (!ensure(GetOwner()))
	{
		return nullptr;
	}

	ACLBaseCharacter* OwnerCharacter = Cast<ACLBaseCharacter>(GetOwner());

	if (!ensure(OwnerCharacter))
	{
		return nullptr;
	}

	UCLAbilitySystemComponent* ASC = OwnerCharacter->GetAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return nullptr;
	}

	return ASC;
}

