// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility_Reload.h"
#include "ProjectCloud/Character/CLHeroCharacter.h"
#include "ProjectCloud/Weapon/CLWeapon.h"


bool UGameplayAbility_Reload::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
    if (!Super::CanActivateAbility(Handle,ActorInfo,SourceTags,TargetTags,OptionalRelevantTags))
        return false;

    ACLHeroCharacter* HeroCharacter = Cast<ACLHeroCharacter>(ActorInfo->AvatarActor);
    if (HeroCharacter)
    {
        ACLWeapon* Weapon = HeroCharacter->GetWeaponActor();
        if (Weapon)
        {
            return Weapon->CanReload();
        }
    }
    return false;
}

void UGameplayAbility_Reload::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    ACLHeroCharacter* HeroCharacter =  Cast<ACLHeroCharacter>(ActorInfo->AvatarActor);
    if (HeroCharacter)
    {
       ACLWeapon* Weapon = HeroCharacter->GetWeaponActor();
       if (Weapon)
       {
           Weapon->Reload();
       }
    }
}
