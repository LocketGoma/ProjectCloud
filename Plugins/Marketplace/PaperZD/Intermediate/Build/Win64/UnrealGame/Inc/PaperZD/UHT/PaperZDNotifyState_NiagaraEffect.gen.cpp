// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Notifies/PaperZDNotifyState_NiagaraEffect.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDNotifyState_NiagaraEffect() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimNotifyState();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PaperZD();
// End Cross Module References
	void UPaperZDNotifyState_NiagaraEffect::StaticRegisterNativesUPaperZDNotifyState_NiagaraEffect()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDNotifyState_NiagaraEffect);
	UClass* Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_NoRegister()
	{
		return UPaperZDNotifyState_NiagaraEffect::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SocketName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SocketName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDestroyAtEnd_MetaData[];
#endif
		static void NewProp_bDestroyAtEnd_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDestroyAtEnd;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPaperZDAnimNotifyState,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Spawns a one shot particle effect on a given location around the RenderComponent.\n */" },
		{ "DisplayName", "Timed Niagara Effect" },
		{ "HideCategories", "Object UObject" },
		{ "IncludePath", "Notifies/PaperZDNotifyState_NiagaraEffect.h" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDNotifyState_NiagaraEffect.h" },
		{ "ToolTip", "Spawns a one shot particle effect on a given location around the RenderComponent." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_PSTemplate_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "Comment", "// Particle System to Spawn\n" },
		{ "DisplayName", "Niagara System" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDNotifyState_NiagaraEffect.h" },
		{ "ToolTip", "Particle System to Spawn" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_PSTemplate = { "PSTemplate", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDNotifyState_NiagaraEffect, PSTemplate), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_PSTemplate_MetaData), Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_PSTemplate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_LocationOffset_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "Comment", "// Location offset from the socket\n" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDNotifyState_NiagaraEffect.h" },
		{ "ToolTip", "Location offset from the socket" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_LocationOffset = { "LocationOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDNotifyState_NiagaraEffect, LocationOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_LocationOffset_MetaData), Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_LocationOffset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_RotationOffset_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "Comment", "// Rotation offset from socket\n" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDNotifyState_NiagaraEffect.h" },
		{ "ToolTip", "Rotation offset from socket" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_RotationOffset = { "RotationOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDNotifyState_NiagaraEffect, RotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_RotationOffset_MetaData), Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_RotationOffset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_Scale_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "Comment", "// Scale to spawn the particle system at\n" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDNotifyState_NiagaraEffect.h" },
		{ "ToolTip", "Scale to spawn the particle system at" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000011, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDNotifyState_NiagaraEffect, Scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_Scale_MetaData), Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_Scale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_SocketName_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "Comment", "// SocketName to attach to\n" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDNotifyState_NiagaraEffect.h" },
		{ "ToolTip", "SocketName to attach to" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_SocketName = { "SocketName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDNotifyState_NiagaraEffect, SocketName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_SocketName_MetaData), Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_SocketName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_bDestroyAtEnd_MetaData[] = {
		{ "Category", "AnimNotify" },
		{ "DisplayName", "Destroy Immediately" },
		{ "ModuleRelativePath", "Public/Notifies/PaperZDNotifyState_NiagaraEffect.h" },
		{ "ToolTip", "Whether the particle system should be immediately destroyed at the end of the notify state or be allowed to finish" },
	};
#endif
	void Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_bDestroyAtEnd_SetBit(void* Obj)
	{
		((UPaperZDNotifyState_NiagaraEffect*)Obj)->bDestroyAtEnd = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_bDestroyAtEnd = { "bDestroyAtEnd", nullptr, (EPropertyFlags)0x0010000000000011, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaperZDNotifyState_NiagaraEffect), &Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_bDestroyAtEnd_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_bDestroyAtEnd_MetaData), Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_bDestroyAtEnd_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_PSTemplate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_LocationOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_RotationOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_Scale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_SocketName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::NewProp_bDestroyAtEnd,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDNotifyState_NiagaraEffect>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::ClassParams = {
		&UPaperZDNotifyState_NiagaraEffect::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::PropPointers),
		0,
		0x009120A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect()
	{
		if (!Z_Registration_Info_UClass_UPaperZDNotifyState_NiagaraEffect.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDNotifyState_NiagaraEffect.OuterSingleton, Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDNotifyState_NiagaraEffect.OuterSingleton;
	}
	template<> PAPERZD_API UClass* StaticClass<UPaperZDNotifyState_NiagaraEffect>()
	{
		return UPaperZDNotifyState_NiagaraEffect::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDNotifyState_NiagaraEffect);
	UPaperZDNotifyState_NiagaraEffect::~UPaperZDNotifyState_NiagaraEffect() {}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_Notifies_PaperZDNotifyState_NiagaraEffect_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_Notifies_PaperZDNotifyState_NiagaraEffect_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDNotifyState_NiagaraEffect, UPaperZDNotifyState_NiagaraEffect::StaticClass, TEXT("UPaperZDNotifyState_NiagaraEffect"), &Z_Registration_Info_UClass_UPaperZDNotifyState_NiagaraEffect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDNotifyState_NiagaraEffect), 418253980U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_Notifies_PaperZDNotifyState_NiagaraEffect_h_3373891840(TEXT("/Script/PaperZD"),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_Notifies_PaperZDNotifyState_NiagaraEffect_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_Notifies_PaperZDNotifyState_NiagaraEffect_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
