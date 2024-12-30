// Copyright @Locketgoma. All Rights Reserved.

#include "CLManaGuageWidget.h"
#include "CLManaGuageGroupWidget.h"
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

void UCLManaGuageWidget::ClearManaGuage()
{
	UpdateManaGuage(MaximumManaGuage, 0);
	CaculateManaGuagePercentage();
}

float UCLManaGuageWidget::AddManaGuage(float AddManaAmount)
{
	NowManaGuageAmount += AddManaAmount;

	CaculateManaGuagePercentage();

	return FMath::Clamp(NowManaGuageAmount - MaximumManaGuage, 0.f, NowManaGuageAmount);
}

void UCLManaGuageWidget::UpdateGuageVisualSetting(FGuageVisualSetting NewSetting)
{
	MaximumManaGuage = NewSetting.MaximumGuage;
	UpdateManaGuageUISize(NewSetting.GuageUILength);
	UpdateManaGuageColor(NewSetting.UIColor);
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
