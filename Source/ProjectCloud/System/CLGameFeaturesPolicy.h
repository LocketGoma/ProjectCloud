// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFeatureStateChangeObserver.h"
#include "GameFeaturesProjectPolicies.h"
#include "CLGameFeaturesPolicy.generated.h"

class FName;
class UGameFeatureData;
struct FPrimaryAssetId;

//Check ULyraGameFeaturePolicy

UCLASS(MinimalAPI, Config = Game)
class UCLGameFeaturesPolicy : public UDefaultGameFeaturesProjectPolicies
{
	GENERATED_BODY()

public:
	PROJECTCLOUD_API static UCLGameFeaturesPolicy& Get();

	UCLGameFeaturesPolicy(const FObjectInitializer& ObjectInitializer);

	//~UGameFeaturesProjectPolicies interface
	virtual void InitGameFeatureManager() override;
	virtual void ShutdownGameFeatureManager() override;
	virtual TArray<FPrimaryAssetId> GetPreloadAssetListForGameFeature(const UGameFeatureData* GameFeatureToLoad, bool bIncludeLoadedAssets = false) const override;
	virtual bool IsPluginAllowed(const FString& PluginURL) const override;
	virtual const TArray<FName> GetPreloadBundleStateForGameFeature() const override;
	virtual void GetGameFeatureLoadingMode(bool& bLoadClientData, bool& bLoadServerData) const override;
	//~End of UGameFeaturesProjectPolicies interface

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> Observers;
};
