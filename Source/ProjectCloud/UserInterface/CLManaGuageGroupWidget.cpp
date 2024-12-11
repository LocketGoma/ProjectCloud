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

	for (UCLManaGuageWidget* WidgetBox : WidgetBoxes)
	{
		if (WidgetBox->CanManaGuageCharging())
		{
			WidgetBox->AddManaGuage(AddManaAmount);	//To do : 남은 양 이월하는 기능 추가
			return;
		}
	}
}

//edit는 어케 하지...?
void UCLManaGuageGroupWidget::EditManaGuage(float NewManaAmount)
{
}
