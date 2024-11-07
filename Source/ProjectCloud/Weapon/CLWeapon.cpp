// Fill out your copyright notice in the Description page of Project Settings.

#include "CLWeapon.h"
#include "Components/SphereComponent.h"
#include "PaperFlipbookComponent.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Weapon/CLWeaponInstance.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"
#include "ProjectCloud/Weapon/CLProjectileActor.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"

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

	ReloadTime = 1.5f;

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

	UpdateAmmoEvent();

}

bool ACLWeapon::CanReload()
{
	if (!ensure(WeaponInstance))
	{
		UE_LOG(LogCloud, Error, TEXT("정상적인 무기를 사용하고 있지 않습니다!"));
		return false;
	}

	if (WeaponEventType == EWeaponEventType::Event_AmmoEmpty)
	{
		//탄약 없음!
		return false;
	}	
	if ((GetMagazineAmmo() == 0 && GetSpareAmmo() == 0))
	{
		UpdateWeaponEventType(EWeaponEventType::Event_AmmoEmpty);
		return false;
	}

	return true;
}

void ACLWeapon::Attack_Implementation()
{
	//재장전중에는 탄 못쏘게
	if (WeaponEventType == EWeaponEventType::Event_Reloading)
	{
		return;
	}

	if (GetMagazineAmmo() > 0)
	{
		UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

		if (!ensure(ASC))
		{
			return;
		}

		ASC->RemoveLooseGameplayTag(WeaponInstance.GetDefaultObject()->MagazineAmmo.KeyTag, 1);

		FActorSpawnParameters SpawnParameter;
		SpawnParameter.Owner = GetOwner();

		FRotator Rotation = GetRootComponent()->GetRelativeRotation();
		ACLProjectileActor* Projectile = GetWorld()->SpawnActor<ACLProjectileActor>(ProjectileClass, GetActorLocation(), Rotation, SpawnParameter);
		Projectile->LaunchVector = GetActorForwardVector();
		Projectile->LaunchProjectile();

	}
	else if (WeaponEventType == EWeaponEventType::Event_MagaineEmpty)
	{
		ReloadEvent();
	}
	
	if (WeaponUtilites::IsWeaponActivate(WeaponEventType) && GetMagazineAmmo() == 0)
	{
		UpdateWeaponEventType(EWeaponEventType::Event_MagaineEmpty);		
	}

	UpdateAmmoEvent();

	/*
	* 1. 탄 쏠때 탄환 남았는지 체크	
	* 2. 남아있으면 1발 줄이고 발사
	* 3. 없으면 자동 재장전
	*/
}

void ACLWeapon::Reload_Implementation()
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return;
	}

	//1. 무한일때 - 풀 장전
	if (WeaponInstance.GetDefaultObject()->bInfinity == true)
	{
		//Mag Size만큼 Mag Ammo 채움
		ASC->SetLooseGameplayTagCount(WeaponInstance.GetDefaultObject()->MagazineAmmo.KeyTag, WeaponInstance.GetDefaultObject()->MagazineSize.Value);	
	}	
	else
	{
		//2. 탄이 비었을때 - 풀 장전 + 탄 감소
		//3. 탄이 비긴 했는데 남은 탄약이 부족할때 = 부족한 만큼만 채우기
		int RequestedAmmo = GetMagazineSize() - GetMagazineAmmo();
		if (GetSpareAmmo() <= RequestedAmmo)
		{
			RequestedAmmo = GetSpareAmmo();
		}
		ASC->AddLooseGameplayTag(WeaponInstance.GetDefaultObject()->MagazineAmmo.KeyTag, RequestedAmmo);
		ASC->RemoveLooseGameplayTag(WeaponInstance.GetDefaultObject()->SpareAmmo.KeyTag, RequestedAmmo);
	}
	UpdateAmmoEvent();
	UpdateWeaponEventType(EWeaponEventType::Event_Default);
}

void ACLWeapon::ReloadEvent_Implementation()
{
	if (!CanReload())
	{
		return;
	}
	UpdateWeaponEventType(EWeaponEventType::Event_Reloading);	

	FTimerHandle TempHandle;
	GetWorld()->GetTimerManager().SetTimer(TempHandle, this, &ACLWeapon::Reload, ReloadTime, false);
}

AController* ACLWeapon::GetOwnerController()
{
	if (!GetOwner())
	{
		return nullptr;
	}
	APawn* OwnerPawn = Cast<APawn>(GetOwner());

	if (IsValid(OwnerPawn))
	{
		return OwnerPawn->GetController();
	}

	return nullptr;
}

const EWeaponType ACLWeapon::GetWeaponType() const
{
	if (!ensureAlways(WeaponType == EWeaponType::Weapon_None))
	{
		UE_LOG(LogCloud, Warning, TEXT("잘못된 무기 타입을 사용하고 있습니다."));
	}
	return WeaponType;
}

const EWeaponEventType ACLWeapon::GetWeaponEventType() const
{
	return WeaponEventType;
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

const bool ACLWeapon::GetIsInfinite()
{	
	return WeaponInstance.GetDefaultObject()->bInfinity;
}

const float ACLWeapon::GetBaseWeaponDamage()
{
	return WeaponInstance.GetDefaultObject()->BaseDamage;
}

void ACLWeapon::UpdateWeaponEventType(EWeaponEventType NewEvent)
{
	UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EWeaponEventType"), true);
	if (EnumPtr)
		UE_LOG(LogTemp, Log, TEXT("기존 무기 이벤트 타입 : [%s], 신규 무기 이벤트 타입 : [%s]"), *(EnumPtr->GetNameStringByValue((int64)WeaponEventType)), *(EnumPtr->GetNameStringByValue((int64)NewEvent)));

	WeaponEventType = NewEvent;
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

