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
