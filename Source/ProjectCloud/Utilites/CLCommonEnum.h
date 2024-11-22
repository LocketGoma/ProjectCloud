//ProjectCloud 공용 Enum 리스트

#pragma once

//장비 타입 지정
UENUM()
enum class EEquipmentType : uint8
{
	//초기값, 해당 값으로 사용되면 오류 리턴
	Equipment_None,

	//메인 무기
	Equipment_MainWeapon,		

	//서브 무기
	Equipment_SubEquipment		
};

//무기 타입 지정
UENUM()
enum class EWeaponType : uint8
{
	//초기값, 해당 값으로 사용되면 오류 리턴
	Weapon_None,				
	Weapon_Projectile,
	Weapon_Melee,
	Weapon_Launcher
};

UENUM()
enum class ESubEquipmentType : uint8
{
	//초기값, 해당 값으로 사용되면 오류 리턴
	SubEquipment_None,				
	//무기로 사용되는 서브웨폰
	SubEquipment_Weapon,			
	//임시
	SubEquipment_Shield,
	//임시
	SubEquipment_BuffFlag			
};

UENUM()
enum class EWeaponEventType : uint8
{
	Event_Default,
	Event_AutoFire,
	//탄창이 비었음
	Event_MagaineEmpty,		
	Event_Reloading,
	Event_Overheat,
	//잔탄 없음
	Event_AmmoEmpty		
};

//방향키 입력
UENUM()
enum class EArrowInputHandleType : uint8
{
	Arrow_UpArrow,
	Arrow_DownArrow,
	Arrow_LeftArrow,
	Arrow_RightArrow
};

UENUM()
enum class EActiveSpellType : uint8
{
	//실패한 경우?
	Spell_None,
	//Low Level
	Spell_Low,
	//Middle Level
	Spell_Mid,
	//High Level
	Spell_High
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