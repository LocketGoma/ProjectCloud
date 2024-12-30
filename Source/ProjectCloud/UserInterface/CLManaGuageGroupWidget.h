// Copyright @Locketgoma. All Rights Reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Containers/Array.h"
#include "Containers/ArrayView.h"
#include "Templates/Tuple.h"
#include "Templates/UnrealTemplate.h"
#include "UObject/Class.h"
#include "UObject/ObjectMacros.h"
#include "CLManaGuageGroupWidget.generated.h"

USTRUCT(BlueprintType)
struct FGuageVisualSetting
{
	GENERATED_BODY()

	//게이지 최대값	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (UiMin = "0", UiMax = "1000", ClampMin = "0", ClampMax = "100"))
	float MaximumGuage = 10;

	//게이지 UI 길이
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (UiMin = "0", UiMax = "200", ClampMin = "0", ClampMax = "200"))
	float GuageUILength = 40;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FLinearColor UIColor;
};

class UCLManaGuageWidget;

/**
 * 마나게이지 위젯을 여러개 소지하는 위젯
 * 마나게이지를 채우는 역할을 수행함.
 */
UCLASS()
class PROJECTCLOUD_API UCLManaGuageGroupWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UCLManaGuageGroupWidget(const FObjectInitializer& ObjectInitializer);

public:
	UFUNCTION(BlueprintCallable)
	void AddManaguage(float AddManaAmount);

	UFUNCTION(BlueprintCallable)
	void EditManaGuage(float NewManaAmount);
		

private:
	//TTuple은 UProperty 안됨...
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<FGuageVisualSetting> GuageVisualSettings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLManaGuageWidget> WidgetBoxClass;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<TObjectPtr<UCLManaGuageWidget>> WidgetBoxes;
};
