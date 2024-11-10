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

ACLWeapon::ACLWeapon(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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

void ACLWeapon::SetEquipmentFromInstance()
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

	ASC->AddLooseGameplayTag(UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).KeyTag, UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).Value);
	ASC->AddLooseGameplayTag(UCLWeaponInstance::GetMagazineSizeData(WeaponInstance).KeyTag, UCLWeaponInstance::GetMagazineSizeData(WeaponInstance).Value);
	ASC->AddLooseGameplayTag(UCLWeaponInstance::GetSpareAmmoData(WeaponInstance).KeyTag, UCLWeaponInstance::GetSpareAmmoData(WeaponInstance).Value);

	UpdateAmmoEvent();
}

void ACLWeapon::ActiveEquipment()
{
	if (GetMagazineAmmo() > 0)
	{
		UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

		if (!ensure(ASC))
		{
			return;
		}

		ASC->RemoveGameplayTag(UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).KeyTag, 1);
		FActorSpawnParameters SpawnParameter;
		SpawnParameter.Owner = GetOwner();

		FRotator Rotation = GetRootComponent()->GetRelativeRotation();
		ACLProjectileActor* ProjectileActor = GetWorld()->SpawnActor<ACLProjectileActor>(ProjectileClass, GetActorLocation(), Rotation, SpawnParameter);

		if (!ensureAlways(ProjectileActor))
		{
			return;
		}
		ProjectileActor->SetBaseDamageFromWeapon(UCLWeaponInstance::GetBaseDamage(WeaponInstance));
		ProjectileActor->LaunchVector = GetActorForwardVector();
		ProjectileActor->LaunchProjectile();
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

bool ACLWeapon::CanActiveEquipment()
{
	if (!ensure(WeaponInstance))
	{
		UE_LOG(LogCloud, Error, TEXT("정상적인 무기를 사용하고 있지 않습니다!"));
		return false;
	}

	//재장전중에는 탄 못쏘게
	if (WeaponEventType == EWeaponEventType::Event_Reloading)
	{
		return false;
	}

	if ((WeaponEventType == EWeaponEventType::Event_MagaineEmpty))
	{
		if (UCLWeaponInstance::CanAutoReload(WeaponInstance))
			ReloadEvent();

		return false;
	}
	return true;
}

bool ACLWeapon::CanReload()
{
	if (!ensure(WeaponInstance))
	{
		UE_LOG(LogCloud, Error, TEXT("정상적인 무기를 사용하고 있지 않습니다!"));
		return false;
	}

	//탄 가득차면 굳이 재장전 안함
	if (GetMagazineAmmo() == GetMagazineSize())
	{
		return false;
	}

	//무제한 사격 가능시 재장전 가능하도록 처리
	if (UCLWeaponInstance::HasInfinityAmmo(WeaponInstance))
	{
		return true;
	}

	//남은 예비탄 없음!
	if (WeaponEventType == EWeaponEventType::Event_AmmoEmpty)
	{		
		return false;
	}
	if ((GetMagazineAmmo() == 0 && GetSpareAmmo() == 0))
	{
		UpdateWeaponEventType(EWeaponEventType::Event_AmmoEmpty);
		return false;
	}

	return true;
}

void ACLWeapon::Reload()
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return;
	}

	//1. 무한일때 - 풀 장전
	if (UCLWeaponInstance::HasInfinityAmmo(WeaponInstance))
	{
		//Mag Size만큼 Mag Ammo 채움
		ASC->SetLooseGameplayTagCount(UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).KeyTag, UCLWeaponInstance::GetMagazineSizeData(WeaponInstance).Value);
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
		ASC->AddLooseGameplayTag(UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).KeyTag, RequestedAmmo);
		ASC->RemoveLooseGameplayTag(UCLWeaponInstance::GetSpareAmmoData(WeaponInstance).KeyTag, RequestedAmmo);
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
	return ASC->GetGameplayTagCount(UCLWeaponInstance::GetMagazineSizeData(WeaponInstance).KeyTag);
}

const int ACLWeapon::GetMagazineAmmo()
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return -1;
	}
	return ASC->GetGameplayTagCount(UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).KeyTag);
}

const int ACLWeapon::GetSpareAmmo()
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return -1;
	}
	return ASC->GetGameplayTagCount(UCLWeaponInstance::GetSpareAmmoData(WeaponInstance).KeyTag);
}

const bool ACLWeapon::GetIsInfinite()
{	
	return UCLWeaponInstance::HasInfinityAmmo(WeaponInstance);
}

const float ACLWeapon::GetBaseWeaponDamage()
{
	return UCLWeaponInstance::GetBaseDamage(WeaponInstance);
}

void ACLWeapon::UpdateWeaponEventType(EWeaponEventType NewEvent)
{
#if !UE_BUILD_SHIPPING
	UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EWeaponEventType"), true);
	if (EnumPtr)
		UE_LOG(LogTemp, Log, TEXT("기존 무기 이벤트 타입 : [%s], 신규 무기 이벤트 타입 : [%s]"), *(EnumPtr->GetNameStringByValue((int64)WeaponEventType)), *(EnumPtr->GetNameStringByValue((int64)NewEvent)));
#endif
	WeaponEventType = NewEvent;
}

