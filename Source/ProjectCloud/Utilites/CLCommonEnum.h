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
