// Copyright @Locketgoma. All Rights Reserved.

#include "CLManaGuageWidget.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"

UCLManaGuageWidget::UCLManaGuageWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
	, MaximumManaGuage(0)
	, NowManaGuageAmount(0)
{
}

void UCLManaGuageWidget::UpdateManaGuage(float NewMaximumManaAmount, float NewNowManaAmount)
{
	MaximumManaGuage = NewMaximumManaAmount;
	NowManaGuageAmount = NewNowManaAmount;

}

void UCLManaGuageWidget::AddManaGuage(float AddManaAmount)
{
	NowManaGuageAmount += AddManaAmount;

	CaculateManaGuagePercentage();
}

void UCLManaGuageWidget::UpdateGuageSize(float NewMaximumManaGuage, float NewGuageUISize)
{
	MaximumManaGuage = NewMaximumManaGuage;

	UpdateManaGuageUISize(NewGuageUISize);
}

const bool UCLManaGuageWidget::CanManaGuageCharging()
{
	return MaximumManaGuage > NowManaGuageAmount;
}

void UCLManaGuageWidget::CaculateManaGuagePercentage()
{
	if (FMath::IsNearlyZero(MaximumManaGuage))
	{
		UE_LOG(LogCloud, Error, TEXT("ManaGuageWidget's Guage Amount is Zero! Guage is Must Over Zero."));
		return;
	}

	float Percentage = FMath::Clamp(((NowManaGuageAmount)/(MaximumManaGuage)), 0.f, 1.f);

	UpdateManaGuageUI(Percentage);
}
