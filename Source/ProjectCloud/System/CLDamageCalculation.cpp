// Copyright @Locketgoma. All Rights Reserved.

#include "CLDamageCalculation.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/PlayerState.h"
#include "ProjectCloud/Weapon/CLWeapon.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Character/CLHeroCharacter.h"
#include "ProjectCloud/System/CLCharacterAttributeSet.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "GameplayEffect.h"

UCLDamageCalculation::UCLDamageCalculation()
{
	RelevantAttributesToCapture.Add(FPlayerDamageStatics::Get().DamageDef);
}

//CLProjectileActor 참고

void UCLDamageCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
    FGameplayEffectContext* TypedContext = ExecutionParams.GetOwningSpec().GetContext().Get();

    float Damage = 0.0f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(FPlayerDamageStatics::Get().DamageDef, FAggregatorEvaluateParameters(), Damage);
    float DamageDone = Damage;

     APlayerState* PS = Cast<APlayerState>(TypedContext->GetEffectCauser());

     if (PS)
     {
         ACLHeroCharacter* HeroCharacter = Cast<ACLHeroCharacter>(PS->GetPawn());
         if (HeroCharacter)
         {
             ACLWeapon* Weapon = HeroCharacter->GetWeaponActor();
             if (Weapon)
             {
                 DamageDone *= Weapon->GetBaseWeaponDamage();
             }
         }
     }
    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UCLCharacterAttributeSet::GetDamageAttribute(), EGameplayModOp::Override, DamageDone));
}
