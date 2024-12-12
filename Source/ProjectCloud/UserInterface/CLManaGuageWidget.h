// Copyright @Locketgoma. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CLManaGuageWidget.generated.h"

/**
* 필요한 정보 (아래 4개는 델리게이트 / 함수로)
* 1. 위젯이 가질 수 있는 마나 게이지 총량
* 2. 전체 마나 총량 (맥시멈)
* 3. 현재 위젯이 가질 수 있는 마나 게이지의 "바닥"
* 4. 현재 마나 수치
* 
* 
* 5. 게이지 올라가는 속도 - 이건 위젯별 동일 (일단 크기랑 상관없대용)
*/

/**
 * 마나 게이지 박스 하나하나씩을 의미하는 위젯
 */
UCLASS()
class PROJECTCLOUD_API UCLManaGuageWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UCLManaGuageWidget(const FObjectInitializer& ObjectInitializer);

	void UpdateManaGuage(float NewMaximumManaAmount, float NewNowManaAmount);
	float AddManaGuage(float AddManaAmount);

	UFUNCTION(BlueprintCallable)
	void UpdateGuageSize(float NewMaximumManaGuage, float NewGuageUISize);

	//마나게이지 충전이 가능한지 여부 (가득 찼으면 X)
	UFUNCTION(BlueprintPure, BlueprintCallable)
	const bool CanManaGuageCharging();

	//얘는 마나 게이지 길이 바꿔주는애고
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateManaGuageUISize(float NewSize);

	//이건 차오른 마나 게이지 퍼센트를 반영시켜주는 애고
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateManaGuageUI(float Percentage);

private:
	//이건 마나 게이지 차오르는 정도 계산해주는 함수고...
	void CaculateManaGuagePercentage();


private:	
	//게이지가 담을수 있는 총 마나 용량
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	float MaximumManaGuage;

	//게이지에 걸린 마나 용량
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	float NowManaGuageAmount;	
};
