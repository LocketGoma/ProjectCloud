// Copyright @Locketgoma. All Rights Reserved.

#include "CLManaGuageGroupWidget.h"
#include "CLManaGuageWidget.h"

UCLManaGuageGroupWidget::UCLManaGuageGroupWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void UCLManaGuageGroupWidget::AddManaguage(float AddManaAmount)
{
	if (WidgetBoxes.IsEmpty())
		return;

	float RemainManaAmount = AddManaAmount;

	for (UCLManaGuageWidget* WidgetBox : WidgetBoxes)
	{
		if (WidgetBox->CanManaGuageCharging())
		{
			RemainManaAmount = WidgetBox->AddManaGuage(RemainManaAmount);	//To do : 남은 양 이월하는 기능 추가

			if (FMath::IsNearlyZero(RemainManaAmount))
				return;

			//Remain이 0 미만이 나오면 안됨.
			if (RemainManaAmount < 0)
			{
				checkNoEntry();
				return;
			}
		}
	}
}

//edit는 어케 하지...?
void UCLManaGuageGroupWidget::EditManaGuage(float NewManaAmount)
{


}
