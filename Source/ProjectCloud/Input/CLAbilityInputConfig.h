#pragma once

#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "CLAbilityInputConfig.generated.h"

/**
 * InputAction과 Tag (Trigger Tag)를 매핑시키는 데이터에셋
 */

USTRUCT(BlueprintType)
struct FCloudInputAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<const UInputAction> InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	//단발식인지, 키 인풋-아웃 풋 처리인지 (true = 단발식)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bTriggeredOnly = true;
};

/**
 * 
 */
UCLASS()
class PROJECTCLOUD_API UCLAbilityInputConfig : public UDataAsset
{
	GENERATED_BODY()	

public:
	UCLAbilityInputConfig(const FObjectInitializer& ObjectInitializer);

	//태그를 찾아주는것도 필요할까...?

	UFUNCTION(BlueprintCallable, Category = "Pawn")
	const UInputAction* FindNativeInputActionFromTag(const FGameplayTag& InputTag, bool bLogNotFound = true) const;

	UFUNCTION(BlueprintCallable, Category = "Pawn")
	const UInputAction* FindAbilityInputActionFromTag(const FGameplayTag& InputTag, bool bLogNotFound = true) const;

public:
	// List of input actions used by the owner.  These input actions are mapped to a gameplay tag and must be manually bound.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (TitleProperty = "InputAction"))
	TArray<FCloudInputAction> NativeInputActions;

	// List of input actions used by the owner.  These input actions are mapped to a gameplay tag and are automatically bound to abilities with matching input tags.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (TitleProperty = "InputAction"))
	TArray<FCloudInputAction> AbilityInputActions;
};
