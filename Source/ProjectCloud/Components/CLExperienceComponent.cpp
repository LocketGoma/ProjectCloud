// Fill out your copyright notice in the Description page of Project Settings.


#include "CLExperienceComponent.h"
#include "ProjectCloud/Utilites/CLCommonStruct.h"
#include "Engine/DataTable.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/AttributeSet/CLExperiencePointAttributeSet.h"
#include "ProjectCloud/Character/CLPlayerState.h"

// Sets default values for this component's properties
UCLExperienceComponent::UCLExperienceComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;

	PS = Cast<ACLPlayerState>(GetOwner());
}

// Called when the game starts
void UCLExperienceComponent::BeginPlay()
{
	Super::BeginPlay();	
}

void UCLExperienceComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UCLExperienceComponent::InitializeComponent()
{
	Super::InitializeComponent();
}

void UCLExperienceComponent::UninitializeComponent()
{
	Super::UninitializeComponent();

	UCLAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();

	if (ASC)
	{
		const UCLExperiencePointAttributeSet* ExpAttributeSet = ASC->GetSet<UCLExperiencePointAttributeSet>();
		if (ExpAttributeSet)
		{
			ExpAttributeSet->OnEXPChanged.RemoveAll(this);
		}
	}
}

void UCLExperienceComponent::InitializeDelegates()
{
	UCLAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();

	if (ASC)
	{
		const UCLExperiencePointAttributeSet* ExpAttributeSet = ASC->GetSet<UCLExperiencePointAttributeSet>();
		if (ExpAttributeSet)
		{
			ExpAttributeSet->OnEXPChanged.AddUObject(this, &ThisClass::HandleExphChanged);
		}
	}
}

const int UCLExperienceComponent::GetPlayerLevel()
{
	return PS->GetPlayerLevel();
}

void UCLExperienceComponent::HandleExphChanged(AActor* Instigator, float Magnitude, float OldValue, float NewValue)
{
	float FinishExpValue = NewValue;

	if (NewValue >= GetRequiredExpForLevelUp(GetPlayerLevel()))
	{
		FinishExpValue = NewValue - GetRequiredExpForLevelUp(GetPlayerLevel());

		PS->OnTryLevelUpEvent.Broadcast(NewValue);
	}
	OnEarnExpEvent.Broadcast(OldValue, NewValue);

	OnExpUpdated.Broadcast(GetPlayerLevel(), FinishExpValue, GetRequiredExpForLevelUp(GetPlayerLevel()));
}

int64 UCLExperienceComponent::GetRequiredExpForLevelUp(int32 NowLevel)
{
	FLevelExperienceTableRow* Row = ExperienceTable->FindRow<FLevelExperienceTableRow>(FName(*FString::FromInt(NowLevel)),TEXT(""));;

	if (Row)
	{
		return Row->RequireExperience;
	}	

	return DATA_NONE;
}

void UCLExperienceComponent::UpdateRequireExperience(int32 NowLevel)
{
	UCLAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();

	if (ASC)
	{
		ASC->SetNumericAttributeBase(UCLExperiencePointAttributeSet::GetEXPAttribute(), 0);
				
		OnExpUpdated.Broadcast(NowLevel, 0, GetRequiredExpForLevelUp(NowLevel));

		//ASC->SetNumericAttributeBase(UCLExperiencePointAttributeSet::GetMaxEXPAttribute(), GetRequiredExpForLevelUp(NowLevel));
	}
}

