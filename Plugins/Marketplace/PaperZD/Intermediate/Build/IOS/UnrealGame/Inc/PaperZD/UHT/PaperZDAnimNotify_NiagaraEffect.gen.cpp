// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Notifies/PaperZDAnimNotify_NiagaraEffect.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimNotify_NiagaraEffect() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimNotify();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PaperZD();
// End Cross Module References
	void UPaperZDAnimNotify_NiagaraEffect::StaticRegisterNativesUPaperZDAnimNotify_NiagaraEffect()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimNotify_NiagaraEffect);
	UClass* Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_NoRegister()
	{
		return UPaperZDAnimNotify_NiagaraEffect::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PSTemplate_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_PSTemplate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocationOffset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LocationOffset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotationOffset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RotationOffset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Scale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAttached_MetaData[];
#endif
		static void NewProp_bAttached_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttached;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SocketName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SocketName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPaperZDAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Spawns a one shot particle effect on a given location around the RenderComponent.\n */" },
		{ "DisplayName", "Play Niagara Particle Effect" },
		{ "HideCategories", "Object UObject" },
		{ "IncludePath", "Notifies/PaperZDAnimNotify_NiagaraEffect.h" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_NiagaraEffect.h" },
		{ "ToolTip", "Spawns a one shot particle effect on a given location around the RenderComponent." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_PSTemplate_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "Comment", "// Particle System to Spawn\n" },
		{ "DisplayName", "Niagara System" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_NiagaraEffect.h" },
		{ "ToolTip", "Particle System to Spawn" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_PSTemplate = { "PSTemplate", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimNotify_NiagaraEffect, PSTemplate), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_PSTemplate_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_PSTemplate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_LocationOffset_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "Comment", "// Location offset from the socket\n" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_NiagaraEffect.h" },
		{ "ToolTip", "Location offset from the socket" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_LocationOffset = { "LocationOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimNotify_NiagaraEffect, LocationOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_LocationOffset_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_LocationOffset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_RotationOffset_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "Comment", "// Rotation offset from socket\n" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_NiagaraEffect.h" },
		{ "ToolTip", "Rotation offset from socket" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_RotationOffset = { "RotationOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimNotify_NiagaraEffect, RotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_RotationOffset_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_RotationOffset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_Scale_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "Comment", "// Scale to spawn the particle system at\n" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_NiagaraEffect.h" },
		{ "ToolTip", "Scale to spawn the particle system at" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000011, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimNotify_NiagaraEffect, Scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_Scale_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_Scale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_bAttached_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "Comment", "// Should attach to the bone/socket\n" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_NiagaraEffect.h" },
		{ "ToolTip", "Should attach to the bone/socket" },
	};
#endif
	void Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_bAttached_SetBit(void* Obj)
	{
		((UPaperZDAnimNotify_NiagaraEffect*)Obj)->bAttached = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_bAttached = { "bAttached", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaperZDAnimNotify_NiagaraEffect), &Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_bAttached_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_bAttached_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_bAttached_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_SocketName_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "Comment", "// SocketName to attach to\n" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDAnimNotify_NiagaraEffect.h" },
		{ "ToolTip", "SocketName to attach to" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_SocketName = { "SocketName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimNotify_NiagaraEffect, SocketName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_SocketName_MetaData), Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_SocketName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_PSTemplate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_LocationOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_RotationOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_Scale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_bAttached,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::NewProp_SocketName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimNotify_NiagaraEffect>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::ClassParams = {
		&UPaperZDAnimNotify_NiagaraEffect::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::PropPointers),
		0,
		0x009120A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimNotify_NiagaraEffect.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimNotify_NiagaraEffect.OuterSingleton, Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimNotify_NiagaraEffect.OuterSingleton;
	}
	template<> PAPERZD_API UClass* StaticClass<UPaperZDAnimNotify_NiagaraEffect>()
	{
		return UPaperZDAnimNotify_NiagaraEffect::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimNotify_NiagaraEffect);
	UPaperZDAnimNotify_NiagaraEffect::~UPaperZDAnimNotify_NiagaraEffect() {}
	struct Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_Notifies_PaperZDAnimNotify_NiagaraEffect_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_Notifies_PaperZDAnimNotify_NiagaraEffect_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimNotify_NiagaraEffect, UPaperZDAnimNotify_NiagaraEffect::StaticClass, TEXT("UPaperZDAnimNotify_NiagaraEffect"), &Z_Registration_Info_UClass_UPaperZDAnimNotify_NiagaraEffect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimNotify_NiagaraEffect), 2311088816U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_Notifies_PaperZDAnimNotify_NiagaraEffect_h_207584296(TEXT("/Script/PaperZD"),
		Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_Notifies_PaperZDAnimNotify_NiagaraEffect_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_Notifies_PaperZDAnimNotify_NiagaraEffect_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
