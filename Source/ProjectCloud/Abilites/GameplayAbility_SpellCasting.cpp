// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility_SpellCasting.h"
#include "GameFramework/PlayerController.h"
#include "ProjectCloud/Character/CLHeroCharacter.h"
#include "ProjectCloud/Input/CLInputComponent.h"
#include "Abilities/Tasks/AbilityTask_WaitInputPress.h"
#include "Abilities/Tasks/AbilityTask_WaitInputRelease.h"


//어빌리티 등록
void UGameplayAbility_SpellCasting::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	ACLHeroCharacter* HeroCharacter = Cast<ACLHeroCharacter>(GetAvatarActorFromActorInfo());
	
	if (HeroCharacter)
	{
		UCLInputComponent* InputComponent = HeroCharacter->GetComponentByClass<UCLInputComponent>();
		if (InputComponent)
		{
			InputComponent->BindAction(Action, ETriggerEvent::Triggered, this, &UGameplayAbility_SpellCasting::CommandInputPressed);
		}
	}
	Task = UAbilityTask_WaitInputRelease::WaitInputRelease(this, true);
	Task->OnRelease.AddDynamic(this, &UGameplayAbility_SpellCasting::TriggerReleased);

	Task->ReadyForActivation();

	InputSpellCommands.Reserve(12);
}

bool UGameplayAbility_SpellCasting::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	if (!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
		return false;

	return true;
}

void UGameplayAbility_SpellCasting::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

}

void UGameplayAbility_SpellCasting::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	//벡터 테스트
	InputSpellCommands.Empty();	

	/*if (Task)
		Task->EndTask();*/
}

void UGameplayAbility_SpellCasting::CommandInputPressed(const FInputActionValue& Value)
{
	//Do something;
	FVector2D MovementVector = Value.Get<FVector2D>();

	InputSpellCommands.Add(AbilityUtilites::GetKeyTypeFromVector(MovementVector));
}

void UGameplayAbility_SpellCasting::TriggerReleased(float TimeHeld)
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, false, false);
}
