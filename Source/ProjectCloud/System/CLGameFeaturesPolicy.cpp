// Fill out your copyright notice in the Description page of Project Settings.


#include "CLGameFeaturesPolicy.h"
#include "ProjectCloud/System/GameFeature_AddGameplayCuePaths.h"

PROJECTCLOUD_API UCLGameFeaturesPolicy& UCLGameFeaturesPolicy::Get()
{
    return UGameFeaturesSubsystem::Get().GetPolicy<UCLGameFeaturesPolicy>();
}

UCLGameFeaturesPolicy::UCLGameFeaturesPolicy(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UCLGameFeaturesPolicy::InitGameFeatureManager()
{	
	Observers.Add(NewObject<UCLGameFeature_AddGameplayCuePaths>());

	UGameFeaturesSubsystem& Subsystem = UGameFeaturesSubsystem::Get();
	for (UObject* Observer : Observers)
	{
		Subsystem.AddObserver(Observer);
	}

	Super::InitGameFeatureManager();
}

void UCLGameFeaturesPolicy::ShutdownGameFeatureManager()
{
	Super::ShutdownGameFeatureManager();

	UGameFeaturesSubsystem& Subsystem = UGameFeaturesSubsystem::Get();
	for (UObject* Observer : Observers)
	{
		Subsystem.RemoveObserver(Observer);
	}
	Observers.Empty();
}

TArray<FPrimaryAssetId> UCLGameFeaturesPolicy::GetPreloadAssetListForGameFeature(const UGameFeatureData* GameFeatureToLoad, bool bIncludeLoadedAssets) const
{
	return Super::GetPreloadAssetListForGameFeature(GameFeatureToLoad, bIncludeLoadedAssets);
}

bool UCLGameFeaturesPolicy::IsPluginAllowed(const FString& PluginURL) const
{
	return Super::IsPluginAllowed(PluginURL);
}

const TArray<FName> UCLGameFeaturesPolicy::GetPreloadBundleStateForGameFeature() const
{
	return Super::GetPreloadBundleStateForGameFeature();
}

void UCLGameFeaturesPolicy::GetGameFeatureLoadingMode(bool& bLoadClientData, bool& bLoadServerData) const
{
	bLoadClientData = !IsRunningDedicatedServer();
	bLoadServerData = !IsRunningClientOnly();
}
