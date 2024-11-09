// Fill out your copyright notice in the Description page of Project Settings.


#include "CLWeaponInstance.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"

UCLWeaponInstance::UCLWeaponInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	MagazineSize.KeyTag = TAG_Weapon_MagazineSize;
	MagazineAmmo.KeyTag = TAG_Weapon_MagazineAmmo;
	SpareAmmo.KeyTag = TAG_Weapon_SpareAmmo;
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
