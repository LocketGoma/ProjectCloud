// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../Private/Editors/Util/PaperZDEditorSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDEditorSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDEditorSettings();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDEditorSettings_NoRegister();
	PAPERZDEDITOR_API UEnum* Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy();
	TIMEMANAGEMENT_API UEnum* Z_Construct_UEnum_TimeManagement_EFrameNumberDisplayFormats();
	UPackage* Z_Construct_UPackage__Script_PaperZDEditor();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAnimSequencePlacementPolicy;
	static UEnum* EAnimSequencePlacementPolicy_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EAnimSequencePlacementPolicy.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EAnimSequencePlacementPolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy, (UObject*)Z_Construct_UPackage__Script_PaperZDEditor(), TEXT("EAnimSequencePlacementPolicy"));
		}
		return Z_Registration_Info_UEnum_EAnimSequencePlacementPolicy.OuterSingleton;
	}
	template<> PAPERZDEDITOR_API UEnum* StaticEnum<EAnimSequencePlacementPolicy>()
	{
		return EAnimSequencePlacementPolicy_StaticEnum();
	}
	struct Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy_Statics::Enumerators[] = {
		{ "EAnimSequencePlacementPolicy::AlwaysAsk", (int64)EAnimSequencePlacementPolicy::AlwaysAsk },
		{ "EAnimSequencePlacementPolicy::SameFolder", (int64)EAnimSequencePlacementPolicy::SameFolder },
		{ "EAnimSequencePlacementPolicy::SubFolder", (int64)EAnimSequencePlacementPolicy::SubFolder },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy_Statics::Enum_MetaDataParams[] = {
		{ "AlwaysAsk.Name", "EAnimSequencePlacementPolicy::AlwaysAsk" },
		{ "AlwaysAsk.Tooltip", "Ask the user where to put the sequence" },
		{ "ModuleRelativePath", "Private/Editors/Util/PaperZDEditorSettings.h" },
		{ "SameFolder.Name", "EAnimSequencePlacementPolicy::SameFolder" },
		{ "SameFolder.Tooltip", "Put the newly created sequence on the same folder as its parent AnimBP" },
		{ "SubFolder.Name", "EAnimSequencePlacementPolicy::SubFolder" },
		{ "SubFolder.Tooltip", "Put the newly created sequence on a subfolder with an specified name" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PaperZDEditor,
		nullptr,
		"EAnimSequencePlacementPolicy",
		"EAnimSequencePlacementPolicy",
		Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy()
	{
		if (!Z_Registration_Info_UEnum_EAnimSequencePlacementPolicy.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAnimSequencePlacementPolicy.InnerSingleton, Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EAnimSequencePlacementPolicy.InnerSingleton;
	}
	void UPaperZDEditorSettings::StaticRegisterNativesUPaperZDEditorSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDEditorSettings);
	UClass* Z_Construct_UClass_UPaperZDEditorSettings_NoRegister()
	{
		return UPaperZDEditorSettings::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDEditorSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_SequencePlacementPolicy_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SequencePlacementPolicy_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SequencePlacementPolicy;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SequencePlacementFolderName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SequencePlacementFolderName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SequenceDuplicationFolderName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SequenceDuplicationFolderName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ResultNodeTitleColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ResultNodeTitleColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutomaticallyPurgeUnregisteredNotifyFunctions_MetaData[];
#endif
		static void NewProp_bAutomaticallyPurgeUnregisteredNotifyFunctions_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutomaticallyPurgeUnregisteredNotifyFunctions;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimelineScrubSnapValue_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_TimelineScrubSnapValue;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TimelineDisplayFormat_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimelineDisplayFormat_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TimelineDisplayFormat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bTimelineDisplayPercentage_MetaData[];
#endif
		static void NewProp_bTimelineDisplayPercentage_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bTimelineDisplayPercentage;
		static const UECodeGen_Private::FNamePropertyParams NewProp_TimelineEnabledSnaps_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimelineEnabledSnaps_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_TimelineEnabledSnaps;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDEditorSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZDEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDEditorSettings_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Contains the Editor Only settings for PaperZD\n */" },
#endif
		{ "IncludePath", "Editors/Util/PaperZDEditorSettings.h" },
		{ "ModuleRelativePath", "Private/Editors/Util/PaperZDEditorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Contains the Editor Only settings for PaperZD" },
#endif
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementPolicy_MetaData[] = {
		{ "Category", "Animation Blueprint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* When creating a AnimSequence via the AnimBP Editor, where to put said AnimSequence. */" },
#endif
		{ "ModuleRelativePath", "Private/Editors/Util/PaperZDEditorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When creating a AnimSequence via the AnimBP Editor, where to put said AnimSequence." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementPolicy = { "SequencePlacementPolicy", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDEditorSettings, SequencePlacementPolicy), Z_Construct_UEnum_PaperZDEditor_EAnimSequencePlacementPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementPolicy_MetaData), Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementPolicy_MetaData) }; // 489027808
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementFolderName_MetaData[] = {
		{ "Category", "Animation Blueprint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Name of the folder in which to place the AnimSequences. */" },
#endif
		{ "ModuleRelativePath", "Private/Editors/Util/PaperZDEditorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the folder in which to place the AnimSequences." },
#endif
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementFolderName = { "SequencePlacementFolderName", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDEditorSettings, SequencePlacementFolderName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementFolderName_MetaData), Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementFolderName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequenceDuplicationFolderName_MetaData[] = {
		{ "Category", "Animation Blueprint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Folder in which to place the notifies of the duplicated AnimBP. */" },
#endif
		{ "ModuleRelativePath", "Private/Editors/Util/PaperZDEditorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Folder in which to place the notifies of the duplicated AnimBP." },
#endif
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequenceDuplicationFolderName = { "SequenceDuplicationFolderName", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDEditorSettings, SequenceDuplicationFolderName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequenceDuplicationFolderName_MetaData), Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequenceDuplicationFolderName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_ResultNodeTitleColor_MetaData[] = {
		{ "Category", "Animation Blueprint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Color of the result node on the AnimGraph. */" },
#endif
		{ "ModuleRelativePath", "Private/Editors/Util/PaperZDEditorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Color of the result node on the AnimGraph." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_ResultNodeTitleColor = { "ResultNodeTitleColor", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDEditorSettings, ResultNodeTitleColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_ResultNodeTitleColor_MetaData), Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_ResultNodeTitleColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bAutomaticallyPurgeUnregisteredNotifyFunctions_MetaData[] = {
		{ "Category", "Animation Blueprint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Whether to automatically remove Custom AnimNotify functions that have been unregistered on the parent Animation Source.\n\x09 * Disabling this will mark any \"Receive Notify\" function on the Animation Blueprints as \"Unregistered\" when needed, allowing later deletion.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Private/Editors/Util/PaperZDEditorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to automatically remove Custom AnimNotify functions that have been unregistered on the parent Animation Source.\nDisabling this will mark any \"Receive Notify\" function on the Animation Blueprints as \"Unregistered\" when needed, allowing later deletion." },
#endif
	};
#endif
	void Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bAutomaticallyPurgeUnregisteredNotifyFunctions_SetBit(void* Obj)
	{
		((UPaperZDEditorSettings*)Obj)->bAutomaticallyPurgeUnregisteredNotifyFunctions = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bAutomaticallyPurgeUnregisteredNotifyFunctions = { "bAutomaticallyPurgeUnregisteredNotifyFunctions", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaperZDEditorSettings), &Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bAutomaticallyPurgeUnregisteredNotifyFunctions_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bAutomaticallyPurgeUnregisteredNotifyFunctions_MetaData), Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bAutomaticallyPurgeUnregisteredNotifyFunctions_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineScrubSnapValue_MetaData[] = {
		{ "Category", "Timeline settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Snap value used to determine scrub resolution of the anim timeline */" },
#endif
		{ "ModuleRelativePath", "Private/Editors/Util/PaperZDEditorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Snap value used to determine scrub resolution of the anim timeline" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineScrubSnapValue = { "TimelineScrubSnapValue", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDEditorSettings, TimelineScrubSnapValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineScrubSnapValue_MetaData), Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineScrubSnapValue_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineDisplayFormat_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineDisplayFormat_MetaData[] = {
		{ "Category", "Timeline settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Display format for the anim timeline */" },
#endif
		{ "ModuleRelativePath", "Private/Editors/Util/PaperZDEditorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Display format for the anim timeline" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineDisplayFormat = { "TimelineDisplayFormat", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDEditorSettings, TimelineDisplayFormat), Z_Construct_UEnum_TimeManagement_EFrameNumberDisplayFormats, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineDisplayFormat_MetaData), Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineDisplayFormat_MetaData) }; // 3184485747
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bTimelineDisplayPercentage_MetaData[] = {
		{ "Category", "Timeline settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether to display percentage in the anim timeline */" },
#endif
		{ "ModuleRelativePath", "Private/Editors/Util/PaperZDEditorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to display percentage in the anim timeline" },
#endif
	};
#endif
	void Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bTimelineDisplayPercentage_SetBit(void* Obj)
	{
		((UPaperZDEditorSettings*)Obj)->bTimelineDisplayPercentage = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bTimelineDisplayPercentage = { "bTimelineDisplayPercentage", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaperZDEditorSettings), &Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bTimelineDisplayPercentage_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bTimelineDisplayPercentage_MetaData), Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bTimelineDisplayPercentage_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineEnabledSnaps_Inner = { "TimelineEnabledSnaps", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineEnabledSnaps_MetaData[] = {
		{ "Category", "Timeline settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether to snap to various things */" },
#endif
		{ "ModuleRelativePath", "Private/Editors/Util/PaperZDEditorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to snap to various things" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineEnabledSnaps = { "TimelineEnabledSnaps", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDEditorSettings, TimelineEnabledSnaps), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineEnabledSnaps_MetaData), Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineEnabledSnaps_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDEditorSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementPolicy_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementPolicy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequencePlacementFolderName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_SequenceDuplicationFolderName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_ResultNodeTitleColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bAutomaticallyPurgeUnregisteredNotifyFunctions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineScrubSnapValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineDisplayFormat_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineDisplayFormat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_bTimelineDisplayPercentage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineEnabledSnaps_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDEditorSettings_Statics::NewProp_TimelineEnabledSnaps,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDEditorSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDEditorSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDEditorSettings_Statics::ClassParams = {
		&UPaperZDEditorSettings::StaticClass,
		"Editor",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPaperZDEditorSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::PropPointers),
		0,
		0x000000A6u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDEditorSettings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDEditorSettings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDEditorSettings()
	{
		if (!Z_Registration_Info_UClass_UPaperZDEditorSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDEditorSettings.OuterSingleton, Z_Construct_UClass_UPaperZDEditorSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDEditorSettings.OuterSingleton;
	}
	template<> PAPERZDEDITOR_API UClass* StaticClass<UPaperZDEditorSettings>()
	{
		return UPaperZDEditorSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDEditorSettings);
	UPaperZDEditorSettings::~UPaperZDEditorSettings() {}
	struct Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Editors_Util_PaperZDEditorSettings_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Editors_Util_PaperZDEditorSettings_h_Statics::EnumInfo[] = {
		{ EAnimSequencePlacementPolicy_StaticEnum, TEXT("EAnimSequencePlacementPolicy"), &Z_Registration_Info_UEnum_EAnimSequencePlacementPolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 489027808U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Editors_Util_PaperZDEditorSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDEditorSettings, UPaperZDEditorSettings::StaticClass, TEXT("UPaperZDEditorSettings"), &Z_Registration_Info_UClass_UPaperZDEditorSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDEditorSettings), 3170494970U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Editors_Util_PaperZDEditorSettings_h_4227938863(TEXT("/Script/PaperZDEditor"),
		Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Editors_Util_PaperZDEditorSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Editors_Util_PaperZDEditorSettings_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Editors_Util_PaperZDEditorSettings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Editors_Util_PaperZDEditorSettings_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
