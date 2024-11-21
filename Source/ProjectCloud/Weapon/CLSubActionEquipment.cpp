// Fill out your copyright notice in the Description page of Project Settings.


#include "CLSubActionEquipment.h"
#include "ProjectCloud/Weapon/CLProjectileActor.h"
#include "ProjectCloud/Weapon/CLWeaponInstance.h"
#include "ProjectCloud/Character/CLPlayerController.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Utilites/CLCommonUtilityFunction.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"

ACLSubActionEquipment::ACLSubActionEquipment(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void ACLSubActionEquipment::BeginPlay()
{
	Super::BeginPlay();
}

void ACLSubActionEquipment::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (GetOwner()->IsActorBeingDestroyed())
	{
		return;
	}

	ACLPlayerController* Controller = CLCommonUtilites::GetPlayerControllerFromActor(GetOwner());
	if (Controller)
	{
		Controller->OnSubEquipmentChanged.Broadcast(nullptr);
	}

	//임의 제거가 아닌 시스템상 제거 (게임 터진 경우)인 경우 바로 return
	if (EndPlayReason != EEndPlayReason::Destroyed && EndPlayReason != EEndPlayReason::RemovedFromWorld)
	{
		return;
	}

	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return;
	}

	switch (SubEquipmentType)
	{
		case ESubEquipmentType::SubEquipment_Weapon:
		{
			RemoveEquipmentFromWeaponInstance(ASC);
			break;
		}
		case ESubEquipmentType::SubEquipment_Shield:
		{
			break;
		}
		case ESubEquipmentType::SubEquipment_BuffFlag:
		{
			break;
		}
		default:
		{
			break;
		}
	}	
}

void ACLSubActionEquipment::SetEquipmentFromInstance()
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return;
	}

	switch (SubEquipmentType)
	{
		case ESubEquipmentType::SubEquipment_Weapon:
		{
			SetEquipmentFromWeaponInstance(ASC);
			break;
		}
		case ESubEquipmentType::SubEquipment_Shield:
		{
			break;
		}
		case ESubEquipmentType::SubEquipment_BuffFlag:
		{
			break;
		}
		default:
		{
			break;
		}
	}

	ACLPlayerController* Controller = CLCommonUtilites::GetPlayerControllerFromActor(GetOwner());
	if (Controller)
	{
		Controller->OnSubEquipmentChanged.Broadcast(this);
		Controller->OnSubEquipmentStatusUIChanged.Broadcast(GetMagazineAmmo(), GetMagazineSize(), GetSpareAmmo(), GetIsInfinite());
	}

	Super::SetEquipmentFromInstance();

}
void ACLSubActionEquipment::SetEquipmentFromWeaponInstance(UCLAbilitySystemComponent* ASC)
{
	if (!(ensure(WeaponInstance)) || !(ensure(GetOwner())))
	{
		return;
	}

	ASC->AddLooseGameplayTag(UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).KeyTag, UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).Value);
	ASC->AddLooseGameplayTag(UCLWeaponInstance::GetMagazineSizeData(WeaponInstance).KeyTag, UCLWeaponInstance::GetMagazineSizeData(WeaponInstance).Value);
	ASC->AddLooseGameplayTag(UCLWeaponInstance::GetSpareAmmoData(WeaponInstance).KeyTag, UCLWeaponInstance::GetSpareAmmoData(WeaponInstance).Value);
}

void ACLSubActionEquipment::RemoveEquipmentFromWeaponInstance(UCLAbilitySystemComponent* ASC)
{
	if (!(ensure(WeaponInstance)) || !(ensure(GetOwner())))
	{
		return;
	}

	ASC->ClearGameplayTag(UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).KeyTag);
	ASC->ClearGameplayTag(UCLWeaponInstance::GetMagazineSizeData(WeaponInstance).KeyTag);
	ASC->ClearGameplayTag(UCLWeaponInstance::GetSpareAmmoData(WeaponInstance).KeyTag);
}

void ACLSubActionEquipment::ActiveWeaponEquipment()
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();
	if (!ensure(ASC))
	{
		return;
	}

	if (ASC->GetGameplayTagCount(UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).KeyTag) > 0)
	{
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

	ACLPlayerController* Controller = CLCommonUtilites::GetPlayerControllerFromActor(GetOwner());
	if (Controller)
	{
		Controller->OnSubEquipmentStatusUIChanged.Broadcast(GetMagazineAmmo(), GetMagazineSize(), GetSpareAmmo(), GetIsInfinite());
	}

	//잔탄 부족해지면 Destroy 해주기

	if (GetMagazineAmmo() == 0)
	{
		Destroy();
	}
}

bool ACLSubActionEquipment::CanActiveWeaponEquipment()
{
	if (!ensure(WeaponInstance))
	{
		UE_LOG(LogCloud, Error, TEXT("정상적인 보조장비를 사용하고 있지 않습니다!"));
		return false;
	}
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();
	if (!(IsValid(ASC)))
	{
		return false;
	}
	
	return (ASC->GetGameplayTagCount(UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).KeyTag) > 0);
}

void ACLSubActionEquipment::ActiveEquipment()
{
	switch (SubEquipmentType)
	{
		case ESubEquipmentType::SubEquipment_Weapon:
		{
			ActiveWeaponEquipment();
			break;
		}
		case ESubEquipmentType::SubEquipment_Shield:
		{
			break;
		}
		case ESubEquipmentType::SubEquipment_BuffFlag:
		{
			break;
		}
		default:
		{
			break;
		}
	}	

	Super::ActiveEquipment();

}

bool ACLSubActionEquipment::CanActiveEquipment()
{
	switch (SubEquipmentType)
	{
		case ESubEquipmentType::SubEquipment_Weapon:
		{		
			return CanActiveWeaponEquipment();	
		}
		case ESubEquipmentType::SubEquipment_Shield:
		{
			break;
		}
		case ESubEquipmentType::SubEquipment_BuffFlag:
		{
			break;
		}
		default:
		{
			break;
		}
	}
	return false;

}

void ACLSubActionEquipment::Reload()
{
	//To do : 리로드 기능 필요해지면 추가하기

	Super::Reload();
}

bool ACLSubActionEquipment::CanReload()
{
	return false;
}

const int ACLSubActionEquipment::GetMagazineSize() const
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return 0;
	}
	return ASC->GetGameplayTagCount(UCLWeaponInstance::GetMagazineSizeData(WeaponInstance).KeyTag);
}

const int ACLSubActionEquipment::GetMagazineAmmo() const
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return 0;
	}
	return ASC->GetGameplayTagCount(UCLWeaponInstance::GetMagazineAmmoData(WeaponInstance).KeyTag);
}

const int ACLSubActionEquipment::GetSpareAmmo() const
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return 0;
	}
	return ASC->GetGameplayTagCount(UCLWeaponInstance::GetSpareAmmoData(WeaponInstance).KeyTag);
}

const bool ACLSubActionEquipment::GetIsInfinite() const
{
	UCLAbilitySystemComponent* ASC = GetOwnerAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return 0;
	}
	return UCLWeaponInstance::HasInfinityAmmo(WeaponInstance);
}

const float ACLSubActionEquipment::GetBaseEquipmentValue() const
{
	switch (SubEquipmentType)
	{
		case ESubEquipmentType::SubEquipment_Weapon:
		{
			return UCLWeaponInstance::GetBaseDamage(WeaponInstance);		
		}
		case ESubEquipmentType::SubEquipment_Shield:
		{
			break;
		}
		case ESubEquipmentType::SubEquipment_BuffFlag:
		{
			break;
		}
		default:
		{
			break;
		}
	}

	return 0.0f;
}

