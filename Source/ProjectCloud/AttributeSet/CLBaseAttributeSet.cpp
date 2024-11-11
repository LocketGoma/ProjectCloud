// Fill out your copyright notice in the Description page of Project Settings.


#include "CLBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"

UAbilitySystemComponent* UCLBaseAttributeSet::GetOwningCLAbilitySystemComponent(AActor* Actor)
{
    if (ensure(Actor))
    {
        ACLBaseCharacter* Character = Cast<ACLBaseCharacter>(Actor);

        return Cast<UAbilitySystemComponent>(Character->GetAbilitySystemComponent());
    }
    return nullptr;
}
