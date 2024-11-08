// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Notifies/PaperZDAnimNotify_PlaySound.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimNotify_PlaySound() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimNotify();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimNotify_PlaySound();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PaperZD();
// End Cross Module References
	void UPaperZDAnimNotify_PlaySound::StaticRegisterNativesUPaperZDAnimNotify_PlaySound()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimNotify_PlaySound);
	UClass* Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_NoRegister()
	{
		return UPaperZDAnimNotify_PlaySound::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Sound_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Sound;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VolumeMultiplier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeMultiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PitchMultiplier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bFollow_MetaData[];
#endif
		static void NewProp_bFollow_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFollow;
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPreviewIgnoreAttenuation_MetaData[];
#endif
		static void NewProp_bPreviewIgnoreAttenuation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreviewIgnoreAttenuation;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttachName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_AttachName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPaperZDAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "Play Sound" },
		{ "HideCategories", "UObject" },
		{ "IncludePath", "Notifies/PaperZDAnimNotify_PlaySound.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_PlaySound.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_Sound_MetaData[] = {
		{ "Category", "AnimNotify" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Sound to Play\n" },
#endif
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_PlaySound.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sound to Play" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimNotify_PlaySound, Sound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_Sound_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_Sound_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_VolumeMultiplier_MetaData[] = {
		{ "Category", "AnimNotify" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Volume Multiplier\n" },
#endif
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_PlaySound.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Volume Multiplier" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_VolumeMultiplier = { "VolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimNotify_PlaySound, VolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_VolumeMultiplier_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_VolumeMultiplier_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_PitchMultiplier_MetaData[] = {
		{ "Category", "AnimNotify" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Pitch Multiplier\n" },
#endif
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_PlaySound.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pitch Multiplier" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimNotify_PlaySound, PitchMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_PitchMultiplier_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_PitchMultiplier_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bFollow_MetaData[] = {
		{ "Category", "AnimNotify" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// If this sound should follow its owner\n" },
#endif
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_PlaySound.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If this sound should follow its owner" },
#endif
	};
#endif
	void Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bFollow_SetBit(void* Obj)
	{
		((UPaperZDAnimNotify_PlaySound*)Obj)->bFollow = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bFollow = { "bFollow", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UPaperZDAnimNotify_PlaySound), &Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bFollow_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bFollow_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bFollow_MetaData) };
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bPreviewIgnoreAttenuation_MetaData[] = {
		{ "Category", "AnimNotify" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Should ignore attenuation in the editor and play as a 2D sound?\n" },
#endif
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_PlaySound.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should ignore attenuation in the editor and play as a 2D sound?" },
#endif
	};
#endif
	void Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bPreviewIgnoreAttenuation_SetBit(void* Obj)
	{
		((UPaperZDAnimNotify_PlaySound*)Obj)->bPreviewIgnoreAttenuation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bPreviewIgnoreAttenuation = { "bPreviewIgnoreAttenuation", nullptr, (EPropertyFlags)0x0010000800004001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UPaperZDAnimNotify_PlaySound), &Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bPreviewIgnoreAttenuation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bPreviewIgnoreAttenuation_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bPreviewIgnoreAttenuation_MetaData) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_AttachName_MetaData[] = {
		{ "Category", "AnimNotify" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Socket or bone name to attach sound to\n" },
#endif
		{ "EditCondition", "bFollow" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_PlaySound.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Socket or bone name to attach sound to" },
#endif
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_AttachName = { "AttachName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimNotify_PlaySound, AttachName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_AttachName_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_AttachName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_Sound,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_VolumeMultiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_PitchMultiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bFollow,
#if WITH_EDITORONLY_DATA
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_bPreviewIgnoreAttenuation,
#endif // WITH_EDITORONLY_DATA
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::NewProp_AttachName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimNotify_PlaySound>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::ClassParams = {
		&UPaperZDAnimNotify_PlaySound::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::PropPointers),
		0,
		0x009020A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDAnimNotify_PlaySound()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimNotify_PlaySound.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimNotify_PlaySound.OuterSingleton, Z_Construct_UClass_UPaperZDAnimNotify_PlaySound_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimNotify_PlaySound.OuterSingleton;
	}
	template<> PAPERZD_API UClass* StaticClass<UPaperZDAnimNotify_PlaySound>()
	{
		return UPaperZDAnimNotify_PlaySound::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimNotify_PlaySound);
	UPaperZDAnimNotify_PlaySound::~UPaperZDAnimNotify_PlaySound() {}
	struct Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_Notifies_PaperZDAnimNotify_PlaySound_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_Notifies_PaperZDAnimNotify_PlaySound_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimNotify_PlaySound, UPaperZDAnimNotify_PlaySound::StaticClass, TEXT("UPaperZDAnimNotify_PlaySound"), &Z_Registration_Info_UClass_UPaperZDAnimNotify_PlaySound, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimNotify_PlaySound), 1300903803U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_Notifies_PaperZDAnimNotify_PlaySound_h_676677340(TEXT("/Script/PaperZD"),
		Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_Notifies_PaperZDAnimNotify_PlaySound_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_Notifies_PaperZDAnimNotify_PlaySound_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
