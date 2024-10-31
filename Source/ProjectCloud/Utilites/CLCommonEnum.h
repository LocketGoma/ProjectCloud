//ProjectCloud 공용 Enum 리스트

#pragma once

#include "CoreMinimal.h"

//무기 타입 지정
UENUM()
enum class EWeaponType : uint8
{
	Weapon_None,				//초기값, 해당 값으로 사용되면 오류 리턴
	Weapon_Projectile,
	Weapon_Melee,
	Weapon_Launcher
};


UENUM()
enum class EWeaponEventType : uint8
{
	Event_Default,
	Event_AutoFire,
	Event_MagaineEmpty,		//탄창이 비었음
	Event_Reloading,
	Event_Overheat,
	Event_AmmoEmpty			//잔탄 없음
};


namespace WeaponUtilites
{
	static bool IsWeaponActivate(EWeaponEventType Type)
	{
		if (Type == EWeaponEventType::Event_Default || Type == EWeaponEventType::Event_AutoFire)
			return true;
		else
			return false;
	}

}