// Copyright @Locketgoma. All Rights Reserved.

#include "CLManaGuageWidget.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"

UCLManaGuageWidget::UCLManaGuageWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
	, MaximumManaAmount(1)
	, MinimumManaGuage(0)
	, MaximumManaGuage(0)
	, NowManaAmount(0)
{
}

void UCLManaGuageWidget::UpdateStatus(float NewMaximumManaAmount, float NewNowManaAmount)
{
	NowManaAmount = NewNowManaAmount;
	MaximumManaAmount = NewMaximumManaAmount;

	CaculateManaGuagePercentage();
}

void UCLManaGuageWidget::UpdateGuageSize(float NewMinimumManaGuage, float NewMaximumManaGuage, float NewGuageUISize)
{
	MinimumManaGuage = NewMinimumManaGuage;
	MaximumManaGuage = NewMaximumManaGuage;

	UpdateManaGuageUISize(NewGuageUISize);
}

void UCLManaGuageWidget::CaculateManaGuagePercentage()
{
	if (FMath::IsNearlyZero(MaximumManaGuage - MinimumManaGuage))
	{
		UE_LOG(LogCloud, Error, TEXT("ManaGuageWidget's Guage Amount is Zero! Guage is Must Over Zero."));
		return;
	}

	float Percentage = FMath::Clamp(((NowManaAmount - MinimumManaGuage)/(MaximumManaGuage - MinimumManaGuage)), 0.f, 1.f);

	UpdateManaGuageUI(Percentage);
}
