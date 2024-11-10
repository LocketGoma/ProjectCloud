// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility_Attack.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Character/CLEnemyCharacter.h"
#include "ProjectCloud/Character/CLHeroCharacter.h"
#include "ProjectCloud/Weapon/CLEquipmentActor.h"

bool UGameplayAbility_Attack::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
    if (!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
        return false;

    ACLHeroCharacter* HeroCharacter = Cast<ACLHeroCharacter>(ActorInfo->AvatarActor);
    if (HeroCharacter)
    {
        ACLEquipmentActor* Equipment = HeroCharacter->GetEquipmentActor(EquipmentType);
        if (Equipment)
        {
            return Equipment->CanActiveEquipment();
        }
    }

    ACLBaseCharacter* OtherCharacter = Cast<ACLBaseCharacter>(ActorInfo->AvatarActor);
    if (OtherCharacter)
    {
        return true;
    }

    return false;
}

void UGameplayAbility_Attack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    ACLHeroCharacter* HeroCharacter = Cast<ACLHeroCharacter>(ActorInfo->AvatarActor);
    if (HeroCharacter)
    {
        ACLEquipmentActor* Equipment = HeroCharacter->GetEquipmentActor(EquipmentType);
        if (Equipment)
        {
            return Equipment->ActiveEquipment();
        }
    }

    ACLEnemyCharacter* EnemyCharacter = Cast<ACLEnemyCharacter>(ActorInfo->AvatarActor);
    if (EnemyCharacter)
    {
        //Do Something...
    }

}
