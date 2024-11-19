// Fill out your copyright notice in the Description page of Project Settings.


#include "CLGameplayCue_HitEffect.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Components/CLHitEffectComponent.h"
#include "PaperFlipbookComponent.h"

ACLGameplayCue_HitEffect::ACLGameplayCue_HitEffect()
	: Super()
	, OwnerCharacter(nullptr)
	, HitEffectComponent(nullptr)
{
}

bool ACLGameplayCue_HitEffect::Recycle()
{
	return Super::Recycle();
}

bool ACLGameplayCue_HitEffect::OnExecute_Implementation(AActor* Target, const FGameplayCueParameters& Parameters)
{

	RemainEffectCount = EffectCount;
		
	OwnerCharacter = Cast<ACLBaseCharacter>(Target);

	if (!OwnerCharacter.IsValid())
	{
		return false;
	}

	HitEffectComponent = OwnerCharacter->GetComponentByClass<UCLHitEffectComponent>();

	if (!HitEffectComponent.IsValid())
	{
		return false;
	}
	
	//오너 바꾸기부터 호출해야되서 Super 나중에 호출함
	return Super::OnExecute_Implementation(Target, Parameters);	
}

UCLHitEffectComponent* ACLGameplayCue_HitEffect::GetHitEffectComponent()
{
	if (!HitEffectComponent.IsValid())
	{
		if (!OwnerCharacter.IsValid())
		{
			OwnerCharacter = Cast<ACLBaseCharacter>(GetOwner());
		}

		HitEffectComponent = OwnerCharacter->GetComponentByClass<UCLHitEffectComponent>();
	}

	return HitEffectComponent.Get();
}
