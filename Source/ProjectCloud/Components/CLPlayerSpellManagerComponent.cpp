// Fill out your copyright notice in the Description page of Project Settings.

#include "CLPlayerSpellManagerComponent.h"
#include "Engine/DataTable.h"
#include "ProjectCloud/Spell/CLSpellInstance.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/AttributeSet/CLManaAttributeSet.h"
#include "ProjectCloud/Character/CLPlayerState.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"

UCLPlayerSpellManagerComponent::UCLPlayerSpellManagerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;

	PS = Cast<ACLPlayerState>(GetOwner());
}

void UCLPlayerSpellManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	InitializeDelegates();
	UpdateSpellCommands(EActiveSpellType::Spell_Low);
}

void UCLPlayerSpellManagerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UCLPlayerSpellManagerComponent::InitializeComponent()
{
	Super::InitializeComponent();	

}

void UCLPlayerSpellManagerComponent::UninitializeComponent()
{
	Super::UninitializeComponent();
}

void UCLPlayerSpellManagerComponent::InitializeDelegates()
{
	OnSpelICommandInput.AddDynamic(this, &ThisClass::TryCommandInput);
	OnTrySpellActivate.AddDynamic(this, &ThisClass::TryActivateSpell);
}

void UCLPlayerSpellManagerComponent::TryActivateSpell()
{
	EActiveSpellType SpellType = CheckSpellCommandLevel(InputSpellCommands);

	ActivateSpell(SpellType);
}

void UCLPlayerSpellManagerComponent::ActivateSpell(EActiveSpellType SpellType)
{
	TSubclassOf<UCLSpellInstance> TryActiveSpell = GetSpellFromType(SpellType);

	if (TryActiveSpell)
	{
		//ASC 호출하고 스킬 발동

		UCLAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
		ASC->TryActivateAbilityByClass(UCLSpellInstance::GetSpellAbility(TryActiveSpell));		
	}
	ClearSpellCommand();
}

const TSubclassOf<UCLSpellInstance> UCLPlayerSpellManagerComponent::GetSpellFromType(EActiveSpellType SpellType)
{
	switch (SpellType)
	{
	case EActiveSpellType::Spell_Low:
		return LowSpell;		
	case EActiveSpellType::Spell_Mid:
		return MidSpell;		
	case EActiveSpellType::Spell_High:
		return HighSpell;		
	}

	return nullptr;
}

const TArray<EArrowInputHandleType> UCLPlayerSpellManagerComponent::GetSpellCommandFromType(EActiveSpellType SpellType)
{
	switch (SpellType)
	{
	case EActiveSpellType::Spell_Low:
		return LowSpellCommands;
	case EActiveSpellType::Spell_Mid:
		return MiddleSpellCommands;
	case EActiveSpellType::Spell_High:
		return HighSpellCommands;
	}

	return TArray<EArrowInputHandleType>();
}

void UCLPlayerSpellManagerComponent::SetSpellFromInstance(TSubclassOf<UCLSpellInstance> NewInstance)
{
	if (!IsValid(NewInstance))
	{
		UE_LOG(LogCloud, Error, TEXT("Spell Change Failure. Maybe New SpellInstance is Null."));
		return;
	}
	
	switch (UCLSpellInstance::GetSpellType(NewInstance))
	{
		case EActiveSpellType::Spell_Low:
		{
			LowSpell = NewInstance;
			UpdateSpellCommands(EActiveSpellType::Spell_Low);
			break;
		}
		case EActiveSpellType::Spell_Mid:
		{
			MidSpell = NewInstance;
			UpdateSpellCommands(EActiveSpellType::Spell_Mid);
			break;
		}
		case EActiveSpellType::Spell_High:
		{
			HighSpell = NewInstance;
			UpdateSpellCommands(EActiveSpellType::Spell_High);
			break;
		}
	}
}

bool UCLPlayerSpellManagerComponent::CheckSpellCorrection(TArray<EArrowInputHandleType> InputCommands)
{
	//이게 False면 바로 스펠 취소걸림
	EActiveSpellType SpellType = CheckSpellCommandLevel(InputCommands);	

	if (SpellType == EActiveSpellType::Spell_None)
	{
		return false;
	}

	return true;
}

EActiveSpellType UCLPlayerSpellManagerComponent::CheckSpellCommandLevel(TArray<EArrowInputHandleType> InputCommands)
{
	if (!InputCommands.IsEmpty())
	{
		if (InputCommands[InputCommands.Num() - 1] == HighSpellCommands[InputCommands.Num() - 1])
		{
			if (InputCommands.Num() >= HighSpellCommands.Num())
			{
				return EActiveSpellType::Spell_High;
			}
			else if (InputCommands.Num() >= MiddleSpellCommands.Num())
			{
				return EActiveSpellType::Spell_Mid;
			}
			//else if (InputCommands.Num() >= LowSpellCommands.Num())

			return EActiveSpellType::Spell_Low;
		}
	}

	return EActiveSpellType::Spell_None;
}

void UCLPlayerSpellManagerComponent::TryCommandInput(EArrowInputHandleType InputCommand)
{
	if (HighSpellCommands.Num() > InputSpellCommands.Num())
		InputSpellCommands.Add(InputCommand);	

	if (!CheckSpellCorrection(InputSpellCommands))
	{
		//실패하면 뭐 이벤트 줘야하나...?
		ClearSpellCommand();
	}
}

void UCLPlayerSpellManagerComponent::UpdateSpellCommands(EActiveSpellType UpdatedSpellType)
{
	HighSpellCommands.Empty();
	
	switch (UpdatedSpellType)
	{
		case EActiveSpellType::Spell_Low:
		{
			LowSpellCommands.Empty();
			MiddleSpellCommands.Empty();
			
			//Low Command Settings
			LowSpellCommands = UCLSpellInstance::GetSpellCommands(LowSpell);
			MiddleSpellCommands = UCLSpellInstance::GetSpellCommands(LowSpell);
			HighSpellCommands = UCLSpellInstance::GetSpellCommands(LowSpell);

			//Mid Command Settings			
			MiddleSpellCommands.Append(UCLSpellInstance::GetSpellCommands(MidSpell));
			HighSpellCommands.Append(UCLSpellInstance::GetSpellCommands(MidSpell));

			//High Command Settings
			HighSpellCommands.Append(UCLSpellInstance::GetSpellCommands(HighSpell));			

			break;
		}
		case EActiveSpellType::Spell_Mid:
		{
			MiddleSpellCommands.Empty();

			//Low Command Settings
			MiddleSpellCommands = UCLSpellInstance::GetSpellCommands(LowSpell);
			HighSpellCommands = UCLSpellInstance::GetSpellCommands(LowSpell);

			//Mid Command Settings			
			MiddleSpellCommands.Append(UCLSpellInstance::GetSpellCommands(MidSpell));
			HighSpellCommands.Append(UCLSpellInstance::GetSpellCommands(MidSpell));

			//High Command Settings
			HighSpellCommands.Append(UCLSpellInstance::GetSpellCommands(HighSpell));

			break;
		}
		case EActiveSpellType::Spell_High:
		{
			//Low Command Settings
			HighSpellCommands = UCLSpellInstance::GetSpellCommands(LowSpell);

			//Mid Command Settings			
			HighSpellCommands.Append(UCLSpellInstance::GetSpellCommands(MidSpell));

			//High Command Settings
			HighSpellCommands.Append(UCLSpellInstance::GetSpellCommands(HighSpell));

			break;
		}
	}
	OnFullSpellCommandChanged.Broadcast();
}

void UCLPlayerSpellManagerComponent::ClearSpellCommand()
{
	InputSpellCommands.Empty();
}
