// Fill out your copyright notice in the Description page of Project Settings.


#include "CLWeaponInstance.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"

UCLWeaponInstance::UCLWeaponInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

const bool UCLWeaponInstance::CanAutoReload(UCLWeaponInstance& Instance)
{
	return Instance.bAutoReload;	
}

const bool UCLWeaponInstance::CanAutoReload(TSubclassOf<UCLWeaponInstance> Instance)
{
	if (IsValid(Instance))
	{
		return CanAutoReload(*(Instance.GetDefaultObject()));
	}

	return false;
}

const bool UCLWeaponInstance::HasInfinityAmmo(UCLWeaponInstance& Instance)
{
	return Instance.bInfinity;
}

const bool UCLWeaponInstance::HasInfinityAmmo(TSubclassOf<UCLWeaponInstance> Instance)
{
	if (IsValid(Instance))
	{
		return HasInfinityAmmo(*(Instance.GetDefaultObject()));
	}
	return false;
}

const float UCLWeaponInstance::GetBaseDamage(UCLWeaponInstance& Instance)
{
	return Instance.BaseDamage;
}

const float UCLWeaponInstance::GetBaseDamage(TSubclassOf<UCLWeaponInstance> Instance)
{
	if (IsValid(Instance))
	{
		return GetBaseDamage(*(Instance.GetDefaultObject()));
	}
	return 0.0f;
}

const FWeaponInstance UCLWeaponInstance::GetMagazineSizeData(UCLWeaponInstance& Instance)
{
	return Instance.MagazineSize;
}

const FWeaponInstance UCLWeaponInstance::GetMagazineSizeData(TSubclassOf<UCLWeaponInstance> Instance)
{
	if (IsValid(Instance))
	{
		return GetMagazineSizeData(*(Instance.GetDefaultObject()));
	}

	return FWeaponInstance();
}

const FWeaponInstance UCLWeaponInstance::GetMagazineAmmoData(UCLWeaponInstance& Instance)
{
	return Instance.MagazineAmmo;
}

const FWeaponInstance UCLWeaponInstance::GetMagazineAmmoData(TSubclassOf<UCLWeaponInstance> Instance)
{
	if (IsValid(Instance))
	{
		return GetMagazineAmmoData(*(Instance.GetDefaultObject()));
	}

	return FWeaponInstance();
}

const FWeaponInstance UCLWeaponInstance::GetSpareAmmoData(UCLWeaponInstance& Instance)
{
	return Instance.SpareAmmo;	
}

const FWeaponInstance UCLWeaponInstance::GetSpareAmmoData(TSubclassOf<UCLWeaponInstance> Instance)
{
	if (IsValid(Instance))
	{
		return GetSpareAmmoData(*(Instance.GetDefaultObject()));
	}

	return FWeaponInstance();
}

void UCLWeaponInstance::OnEquipmentTypeChanged()
{
	if (EEquipmentType::Equipment_MainWeapon == EquipmentType)
	{
		MagazineSize.KeyTag = TAG_Weapon_MagazineSize;
		MagazineAmmo.KeyTag = TAG_Weapon_MagazineAmmo;
		SpareAmmo.KeyTag = TAG_Weapon_SpareAmmo;
	}
	else if (EEquipmentType::Equipment_SubEquipment == EquipmentType)
	{
		MagazineSize.KeyTag = TAG_Sub_Weapon_MagazineAmmo;
		MagazineAmmo.KeyTag = TAG_Sub_Weapon_MagazineSize;
		SpareAmmo.KeyTag = TAG_Sub_Weapon_SpareAmmo;
	}
	else
	{
		UE_LOG(LogCloud, Warning, TEXT("%s 's EquipmentType is Empty!!"), *GetNameSafe(this));
	}
}

#if WITH_EDITOR
void UCLWeaponInstance::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent); 
	const FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None; 
	//원래는 GET_MEMBER_NAME_CHECKED 쓰라는거 같긴한데
	//if (PropertyName == FName("EquipmentType"))
	if (PropertyName == GET_MEMBER_NAME_CHECKED(UCLWeaponInstance, EquipmentType))
	{ 
		OnEquipmentTypeChanged();
	}
}
#endif

