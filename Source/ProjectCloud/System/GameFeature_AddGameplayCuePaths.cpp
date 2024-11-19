// Fill out your copyright notice in the Description page of Project Settings.
#include "GameFeature_AddGameplayCuePaths.h"
#include "AbilitySystemGlobals.h"
#include "GameplayCueManager.h"
#include "GameFeatureData.h"
#include "GameplayCueSet.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GameFeature_AddGameplayCuePaths)

#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

#define LOCTEXT_NAMESPACE "GameFeatures"

UGameFeatureAction_AddGameplayCuePath::UGameFeatureAction_AddGameplayCuePath()
{
	DirectoryPathsToAdd.Add(FDirectoryPath{ TEXT("/GameplayCues") });
}

#if WITH_EDITOR
EDataValidationResult UGameFeatureAction_AddGameplayCuePath::IsDataValid(FDataValidationContext& Context) const
{
	EDataValidationResult Result = Super::IsDataValid(Context);

	for (const FDirectoryPath& Directory : DirectoryPathsToAdd)
	{
		if (Directory.Path.IsEmpty())
		{
			const FText InvalidCuePathError = FText::Format(LOCTEXT("InvalidCuePathError", "'{0}' is not a valid path!"), FText::FromString(Directory.Path));
			Context.AddError(InvalidCuePathError);
			Result = CombineDataValidationResults(Result, EDataValidationResult::Invalid);
		}
	}

	return CombineDataValidationResults(Result, EDataValidationResult::Valid);
}
#endif	// WITH_EDITOR

////////////////////


UCLGameFeature_AddGameplayCuePaths::UCLGameFeature_AddGameplayCuePaths()
	: Super()
{
	//UGameFeaturesSubsystem& Subsystem = UGameFeaturesSubsystem::Get();
	//Subsystem.AddObserver(NewObject<UGameFeature_AddGameplayCuePaths>());
}

void UCLGameFeature_AddGameplayCuePaths::OnGameFeatureRegistering(const UGameFeatureData* GameFeatureData, const FString& PluginName, const FString& PluginURL)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(ULyraGameFeature_AddGameplayCuePaths::OnGameFeatureRegistering);

	const FString PluginRootPath = TEXT("/") + PluginName;
	for (const UGameFeatureAction* Action : GameFeatureData->GetActions())
	{
		if (const UGameFeatureAction_AddGameplayCuePath* AddGameplayCueGFA = Cast<UGameFeatureAction_AddGameplayCuePath>(Action))
		{
			const TArray<FDirectoryPath>& DirsToAdd = AddGameplayCueGFA->GetDirectoryPathsToAdd();

			if (UGameplayCueManager* GCM = UAbilitySystemGlobals::Get().GetGameplayCueManager())
			{
				UGameplayCueSet* RuntimeGameplayCueSet = GCM->GetRuntimeCueSet();
				const int32 PreInitializeNumCues = RuntimeGameplayCueSet ? RuntimeGameplayCueSet->GameplayCueData.Num() : 0;

				for (const FDirectoryPath& Directory : DirsToAdd)
				{
					FString MutablePath = Directory.Path;
					UGameFeaturesSubsystem::FixPluginPackagePath(MutablePath, PluginRootPath, false);
					GCM->AddGameplayCueNotifyPath(MutablePath, /** bShouldRescanCueAssets = */ false);
				}

				// Rebuild the runtime library with these new paths
				if (!DirsToAdd.IsEmpty())
				{
					GCM->InitializeRuntimeObjectLibrary();
				}

				//const int32 PostInitializeNumCues = RuntimeGameplayCueSet ? RuntimeGameplayCueSet->GameplayCueData.Num() : 0;
				//if (PreInitializeNumCues != PostInitializeNumCues)
				//{
				//	GCM->RefreshGameplayCuePrimaryAsset();
				//}
			}
		}
	}
}

void UCLGameFeature_AddGameplayCuePaths::OnGameFeatureUnregistering(const UGameFeatureData* GameFeatureData, const FString& PluginName, const FString& PluginURL)
{
	const FString PluginRootPath = TEXT("/") + PluginName;
	for (const UGameFeatureAction* Action : GameFeatureData->GetActions())
	{
		if (const UGameFeatureAction_AddGameplayCuePath* AddGameplayCueGFA = Cast<UGameFeatureAction_AddGameplayCuePath>(GameFeatureData))
		{
			const TArray<FDirectoryPath>& DirsToAdd = AddGameplayCueGFA->GetDirectoryPathsToAdd();

			if (UGameplayCueManager* GCM = UAbilitySystemGlobals::Get().GetGameplayCueManager())
			{
				int32 NumRemoved = 0;
				for (const FDirectoryPath& Directory : DirsToAdd)
				{
					FString MutablePath = Directory.Path;
					UGameFeaturesSubsystem::FixPluginPackagePath(MutablePath, PluginRootPath, false);
					NumRemoved += GCM->RemoveGameplayCueNotifyPath(MutablePath, /** bShouldRescanCueAssets = */ false);
				}
				ensure(NumRemoved == DirsToAdd.Num());
				// Rebuild the runtime library only if there is a need to
				if (NumRemoved > 0)
				{
					GCM->InitializeRuntimeObjectLibrary();
				}
			}
		}
	}
}

