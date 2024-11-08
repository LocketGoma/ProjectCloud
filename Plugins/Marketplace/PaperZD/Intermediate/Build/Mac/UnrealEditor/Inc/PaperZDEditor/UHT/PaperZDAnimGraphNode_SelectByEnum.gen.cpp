// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../Private/Graphs/Nodes/PaperZDAnimGraphNode_SelectByEnum.h"
#include "AnimNodes/PaperZDAnimNode_SelectByEnum.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimGraphNode_SelectByEnum() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UEnum();
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimNode_SelectByEnum();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_Base();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PaperZDEditor();
// End Cross Module References
	void UPaperZDAnimGraphNode_SelectByEnum::StaticRegisterNativesUPaperZDAnimGraphNode_SelectByEnum()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimGraphNode_SelectByEnum);
	UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_NoRegister()
	{
		return UPaperZDAnimGraphNode_SelectByEnum::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimNode_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AnimNode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoundEnum_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_BoundEnum;
		static const UECodeGen_Private::FNamePropertyParams NewProp_VisibleEnumEntries_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VisibleEnumEntries_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_VisibleEnumEntries;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPaperZDAnimGraphNode_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZDEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Selects between two animations depending on a given Enum value.\n */" },
		{ "IncludePath", "Graphs/Nodes/PaperZDAnimGraphNode_SelectByEnum.h" },
		{ "ModuleRelativePath", "Private/Graphs/Nodes/PaperZDAnimGraphNode_SelectByEnum.h" },
		{ "ToolTip", "Selects between two animations depending on a given Enum value." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_AnimNode_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/* Runtime node. */" },
		{ "ModuleRelativePath", "Private/Graphs/Nodes/PaperZDAnimGraphNode_SelectByEnum.h" },
		{ "ToolTip", "Runtime node." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_AnimNode = { "AnimNode", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimGraphNode_SelectByEnum, AnimNode), Z_Construct_UScriptStruct_FPaperZDAnimNode_SelectByEnum, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_AnimNode_MetaData), Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_AnimNode_MetaData) }; // 3671428295
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_BoundEnum_MetaData[] = {
		{ "Comment", "/* Enum being switched on */" },
		{ "ModuleRelativePath", "Private/Graphs/Nodes/PaperZDAnimGraphNode_SelectByEnum.h" },
		{ "ToolTip", "Enum being switched on" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_BoundEnum = { "BoundEnum", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimGraphNode_SelectByEnum, BoundEnum), Z_Construct_UClass_UEnum, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_BoundEnum_MetaData), Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_BoundEnum_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_VisibleEnumEntries_Inner = { "VisibleEnumEntries", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_VisibleEnumEntries_MetaData[] = {
		{ "Comment", "/* List of enum entries this graph is exposing. */" },
		{ "ModuleRelativePath", "Private/Graphs/Nodes/PaperZDAnimGraphNode_SelectByEnum.h" },
		{ "ToolTip", "List of enum entries this graph is exposing." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_VisibleEnumEntries = { "VisibleEnumEntries", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimGraphNode_SelectByEnum, VisibleEnumEntries), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_VisibleEnumEntries_MetaData), Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_VisibleEnumEntries_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_AnimNode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_BoundEnum,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_VisibleEnumEntries_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::NewProp_VisibleEnumEntries,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimGraphNode_SelectByEnum>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::ClassParams = {
		&UPaperZDAnimGraphNode_SelectByEnum::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimGraphNode_SelectByEnum.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimGraphNode_SelectByEnum.OuterSingleton, Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimGraphNode_SelectByEnum.OuterSingleton;
	}
	template<> PAPERZDEDITOR_API UClass* StaticClass<UPaperZDAnimGraphNode_SelectByEnum>()
	{
		return UPaperZDAnimGraphNode_SelectByEnum::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimGraphNode_SelectByEnum);
	UPaperZDAnimGraphNode_SelectByEnum::~UPaperZDAnimGraphNode_SelectByEnum() {}
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(UPaperZDAnimGraphNode_SelectByEnum)
	struct Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_SelectByEnum_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_SelectByEnum_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByEnum, UPaperZDAnimGraphNode_SelectByEnum::StaticClass, TEXT("UPaperZDAnimGraphNode_SelectByEnum"), &Z_Registration_Info_UClass_UPaperZDAnimGraphNode_SelectByEnum, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimGraphNode_SelectByEnum), 2863017575U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_SelectByEnum_h_2047349987(TEXT("/Script/PaperZDEditor"),
		Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_SelectByEnum_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_SelectByEnum_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
