// Copyright @Locketgoma. All Rights Reserved.

#include "GameplayAbility_SpellCasting.h"
#include "GameFramework/PlayerController.h"
#include "ProjectCloud/Spell/CLSpellInstance.h"
#include "ProjectCloud/Input/CLInputComponent.h"
#include "ProjectCloud/Character/CLPlayerState.h"
#include "ProjectCloud/Character/CLHeroCharacter.h"
#include "ProjectCloud/Components/CLPlayerSpellManagerComponent.h"
#include "Projectcloud/Abilites/Task/CLAbilityTask_WaitInputRelease.h"

//어빌리티 등록
void UGameplayAbility_SpellCasting::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	ACLHeroCharacter* HeroCharacter = Cast<ACLHeroCharacter>(GetAvatarActorFromActorInfo());
	
	if (HeroCharacter)
	{				
		//인풋 컴포넌트 관련 세팅
		UCLInputComponent* InputComponent = HeroCharacter->GetComponentByClass<UCLInputComponent>();
		if (InputComponent)
		{
			InputComponent->BindAction(Action, ETriggerEvent::Triggered, this, &UGameplayAbility_SpellCasting::CommandInputPressed);
		}
	}
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
	//어빌리티 발동직전마다 스펠이 바뀌었는지 확인할 필요가 있긴 함...
	//1. PS의 스펠 매니저에서 현재 스펠 정보 얻어옴	
	SetSpellCommands();


	//왜 안될까?
	//Task = UCLAbilityTask_WaitInputRelease::WaitInputRelease(this, false);
	//Task->OnRelease.AddDynamic(this, &UGameplayAbility_SpellCasting::TriggerReleased);
	//Task->ReadyForActivation();
}

void UGameplayAbility_SpellCasting::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	//Task->EndTask();	
}

void UGameplayAbility_SpellCasting::CommandInputPressed(const FInputActionValue& Value)
{
	//2. 키 입력시 저장된 스펠 커맨드와 입력된 스펠 커맨드가 일치하는지 비교
	//불일치시 바로 캔슬시킴

	if (IsActive())
	{
		FVector2D MovementVector = Value.Get<FVector2D>();

		EArrowInputHandleType InputType = AbilityUtilites::GetKeyTypeFromVector(MovementVector);

		if (ACLPlayerState* PS = GetPlayerState())
		{
			UCLPlayerSpellManagerComponent* SpellComp = PS->GetPlayerSpellManagerComponent();
			if (SpellComp)
			{
				SpellComp->OnSpelICommandInput.Broadcast(InputType);
			}
		}
	}
}

void UGameplayAbility_SpellCasting::TriggerReleased(float TimeHeld)
{
	//3. 스펠 커맨드가 1단계, 2단계, 3단계 통과시 해당 스펠 발동

	if (ACLPlayerState* PS = GetPlayerState())
	{
		UCLPlayerSpellManagerComponent* SpellComp = PS->GetPlayerSpellManagerComponent();
		if (SpellComp)
		{			
			SpellComp->OnTrySpellActivate.Broadcast();
		}
	}

	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, false, false);
}

void UGameplayAbility_SpellCasting::SetSpellCommands()
{
	//플레이어 스테이트 관련 세팅
	if (ACLPlayerState* PS = GetPlayerState())
	{
		UCLPlayerSpellManagerComponent* SpellComp = PS->GetPlayerSpellManagerComponent();
		if (SpellComp)
		{
			SpellComp->OnTrySpellCommandInput.Broadcast();
		}
	}
}

ACLPlayerState* UGameplayAbility_SpellCasting::GetPlayerState()
{
	ACLHeroCharacter* HeroCharacter = Cast<ACLHeroCharacter>(GetAvatarActorFromActorInfo());
	ACLPlayerState* PS = Cast<ACLPlayerState>(HeroCharacter->GetPlayerState());

	return PS;
}
