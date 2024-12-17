// Fill out your copyright notice in the Description page of Project Settings.

#include "CLManaAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "ProjectCloud/Character/CLPlayerState.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Utilites/CLCommonTextTags.h"

UCLManaAttributeSet::UCLManaAttributeSet()
	: Super()
	, Mana(0.f)
	, MaxMana(0.f)
	, ChangeManaAmount(0.f)
{
	ManaBeforeAttributeChange = 0.f;
	MaxManaBeforeAttributeChange = 0.f;
}

bool UCLManaAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	if (!Super::PreGameplayEffectExecute(Data))
		return false;

	ACLBaseCharacter* Character = nullptr;
	//1. 플레이어인 경우 (플레이어는 PS에 정보 있음) <- 마나는 플레이어만 가지고 있지 않을까?
	if (ACLPlayerState* PS = Cast<ACLPlayerState>(GetOwningActor()))
	{
		Character = Cast<ACLBaseCharacter>(PS->GetPawn());
	}

	//여기는 터트리는게 맞음 (222)
	if (!ensure(Character))
	{
		return false;
	}

	ManaBeforeAttributeChange = GetMana();
	MaxManaBeforeAttributeChange = GetMaxMana();

	return true;
}

void UCLManaAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);	

	const FGameplayEffectContextHandle& EffectContext = Data.EffectSpec.GetEffectContext();
	AActor* Instigator = EffectContext.GetOriginalInstigator();
	AActor* Causer = EffectContext.GetEffectCauser();

	ACLBaseCharacter* Character = nullptr;
	//1. 플레이어인 경우 (플레이어는 PS에 정보 있음) <- 마나는 플레이어만 가지고 있지 않을까?
	if (ACLPlayerState* PS = Cast<ACLPlayerState>(GetOwningActor()))
	{
		Character = Cast<ACLBaseCharacter>(PS->GetPawn());
	}

	//여기는 터트리는게 맞음 (222)
	if (!ensure(Character))
	{
		return;
	}





	//회복, 사용 등
	if (Data.EvaluatedData.Attribute == GetChangeManaAmountAttribute())
	{		
		//발동확률이 1 이하이고 + 값이 Failvaiue 일때 = 실패로 판정함
		if ((ATTRIBUTE_ONEVALUE > Data.EffectSpec.GetChanceToApplyToTarget()) && FMath::IsNearlyEqual(ATTRIBUTE_FAILUREVALUE, GetChangeManaAmount()))
		{
			//On Magic Casting Failure
			OnSpellCastFailure.Broadcast(Instigator, Data.EvaluatedData.Magnitude, ManaBeforeAttributeChange, GetMana());
		}
		else
		{
			SetManaCurrentValue(FMath::Clamp((GetMana() + GetChangeManaAmount()), ATTRIBUTE_MINVALUE, GetMaxMana()));

			if (GetChangeManaAmount() >= 0)
			{
				OnManaAdded.Broadcast(Instigator, Data.EvaluatedData.Magnitude, ManaBeforeAttributeChange, GetChangeManaAmount());
			}
			else if (GetMana() != ManaBeforeAttributeChange)
			{
				OnManaChanged.Broadcast(Instigator, Data.EvaluatedData.Magnitude, ManaBeforeAttributeChange, GetMana());
			}
		}

		SetChangeManaAmountToTarget(0.f, Character);
	}
	else if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetManaCurrentValue(FMath::Clamp(GetMana(), ATTRIBUTE_MINVALUE, GetMaxMana()));
	}
	else if (Data.EvaluatedData.Attribute == GetMaxManaAttribute())
	{
		SetManaCurrentValue(FMath::Clamp(GetMana(), ATTRIBUTE_MINVALUE, GetMaxMana()));
	}

	if (GetMana() <= 0.f)
	{
		OnOutOfMana.Broadcast(Instigator, Data.EvaluatedData.Magnitude, ManaBeforeAttributeChange, GetMana());
	}

}
