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
struct FGuageScale
{
	GENERATED_BODY()
	
	//게이지 최소값
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (UiMin = "0", UiMax = "1000", ClampMin = "0", ClampMax = "1000"))
	float MinimumGuage = 0;

	//게이지 최대값	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (UiMin = "0", UiMax = "1000", ClampMin = "0", ClampMax = "1000"))
	float MaximumGuage = 0;

	//게이지 UI 길이
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (UiMin = "0", UiMax = "200", ClampMin = "0", ClampMax = "200"))
	float GuageUILength = 40;
};

class UCLManaGuageWidget;

/**
 * 마나게이지 위젯을 여러개 소지하는 위젯
 */
UCLASS()
class PROJECTCLOUD_API UCLManaGuageGroupWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UCLManaGuageGroupWidget(const FObjectInitializer& ObjectInitializer);

private:
	//TTuple은 UProperty 안됨...
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<FGuageScale> GuageScale;	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLManaGuageWidget> WidgetBoxClass;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<TObjectPtr<UCLManaGuageWidget>> WidgetBox;
};
