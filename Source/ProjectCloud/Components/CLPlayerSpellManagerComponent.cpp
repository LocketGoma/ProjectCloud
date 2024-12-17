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
	UpdateSpellCommands(EActiveSpellType::Spell_Low);		
}

void UCLPlayerSpellManagerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	ManaRestoreTimerHandle.Invalidate();
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

	UCLAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
	if (ASC)
	{
		const UCLManaAttributeSet* ManaAttributeSet = ASC->GetSet<UCLManaAttributeSet>();
		if (ManaAttributeSet)
		{
			ManaAttributeSet->OnManaAdded.AddUObject(this, &ThisClass::HandleAddMana);
			ManaAttributeSet->OnManaChanged.AddUObject(this, &ThisClass::HandleChangeMana);
		}
	}
	InitializeTimer();
}

void UCLPlayerSpellManagerComponent::InitializeTimer()
{
	GetWorld()->GetTimerManager().SetTimer(ManaRestoreTimerHandle, this, &ThisClass::AddMana, RestoreInterval, true, 0);
}

void UCLPlayerSpellManagerComponent::TryActivateSpell()
{
	EActiveSpellType SpellType = CheckSpellCommandLevel(InputSpellCommands);

	ActivateSpell(SpellType);
}

void UCLPlayerSpellManagerComponent::AddMana()
{
	UCLAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
	if (IsValid(RestoreManaGameplayEffect) && IsValid(ASC) && ASC->HasBeenInitialized())
	{
		ASC->AddGameplayEffect(RestoreManaGameplayEffect);
	}
}

void UCLPlayerSpellManagerComponent::ApplyPenaltyManaAmount()
{
	UCLAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
	if (IsValid(PenaltyManaGameplayEffect) && IsValid(ASC) && ASC->HasBeenInitialized())
	{
		ASC->AddGameplayEffect(PenaltyManaGameplayEffect);
	}
}

//스펠 발동 함수
void UCLPlayerSpellManagerComponent::ActivateSpell(EActiveSpellType SpellType)
{
	/*
	* To do : 마나 사용량 체크
	* 1. 현재 스펠이 정해지지 않은 경우 마나 차감 - 그냥 0까지 알아서 차감함
	* 1-1. 스펠 정해지지 않은 경우를 Manager 접근을 통해 알 수 있게 처리. 스펠 정해지지 않았을때에만 마나 체크하도록 처리
	* 2. 현재 스펠이 정해진 경우 - 
	* 2-1. 발동시 현재 마나량 > 스펠 코스트일때만 발동
	* 2-2. 발동시 마나량 조건 불만족시 마나 소비 X, 마법 발동 X
	* FGameplayEffectModCallbackData 를 이용할 수 있는 방법은 없을까?
	*/

	TSubclassOf<UCLSpellInstance> TryActiveSpell = GetSpellFromType(SpellType);

	if (TryActiveSpell)
	{
		//ASC 호출하고 스킬 발동		

		UCLAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
		ASC->TryActivateAbilityByClass(UCLSpellInstance::GetSpellAbility(TryActiveSpell));		
		ASC->AddGameplayEffect(UCLSpellInstance::GetSpellCost(TryActiveSpell));
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

	//스펠타입 None 뜨면서 실패할수도 있음...
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

	if (SpellType == EActiveSpellType::Spell_Failure)
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
			else if (InputCommands.Num() >= LowSpellCommands.Num())
			{
				return EActiveSpellType::Spell_Low;
			}
			return EActiveSpellType::Spell_None;
		}
		return EActiveSpellType::Spell_Failure;
	}
	return EActiveSpellType::Spell_None;
}

void UCLPlayerSpellManagerComponent::HandleChangeMana(AActor* Instigator, float Magnitude, float OldValue, float NewValue)
{
	OnManaEdited.Broadcast(NewValue);
}

void UCLPlayerSpellManagerComponent::HandleAddMana(AActor* Instigator, float Magnitude, float OldValue, float NewAddValue)
{
	OnManaAdded.Broadcast(NewAddValue);
}

void UCLPlayerSpellManagerComponent::TryCommandInput(EArrowInputHandleType InputCommand)
{
	if (HighSpellCommands.Num() > InputSpellCommands.Num())
		InputSpellCommands.Add(InputCommand);	

	if (!CheckSpellCorrection(InputSpellCommands))
	{		
		ApplyPenaltyManaAmount();		//실패시 마나 감소 이벤트
		ClearSpellCommand();			//스펠 초기화
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
