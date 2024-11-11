// Copyright @Locketgoma. All Rights Reserved.

#include "CLDamageCalculation.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/PlayerState.h"
#include "ProjectCloud/Weapon/CLEquipmentActor.h"
#include "ProjectCloud/Weapon/CLWeapon.h"
#include "ProjectCloud/Weapon/CLSubActionEquipment.h"
#include "ProjectCloud/Weapon/CLProjectileActor.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/Character/CLHeroCharacter.h"
#include "ProjectCloud/AttributeSet/CLCharacterAttributeSet.h"
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
             //To do. 필요시 주무기에서 나온건지 보조무기에서 나온건지 알아야 할 필요 있음. 3d64bff (11월 10일자) 커밋 참고.
             ACLProjectileActor* ProjectileActor = Cast<ACLProjectileActor>(TypedContext->GetSourceObject());
             if (ProjectileActor)
             {
                 DamageDone *= ProjectileActor->GetBaseDamageFromWeapon();                 
             }
         }
     }
    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UCLCharacterAttributeSet::GetDamageAttribute(), EGameplayModOp::Override, DamageDone));
}
