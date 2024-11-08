// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../Private/Graphs/Nodes/PaperZDAnimGraphNode_Base.h"
#include "K2Node.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimGraphNode_Base() {}
// Cross Module References
	BLUEPRINTGRAPH_API UClass* Z_Construct_UClass_UK2Node();
	BLUEPRINTGRAPH_API UScriptStruct* Z_Construct_UScriptStruct_FOptionalPinFromProperty();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_Base();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_Base_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PaperZDEditor();
// End Cross Module References
	void UPaperZDAnimGraphNode_Base::StaticRegisterNativesUPaperZDAnimGraphNode_Base()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimGraphNode_Base);
	UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_Base_NoRegister()
	{
		return UPaperZDAnimGraphNode_Base::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ShowPinForProperties_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShowPinForProperties_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ShowPinForProperties;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UK2Node,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZDEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Base class for all the \"Animation Graph\" nodes for PaperZD.\n * Must be paired with a Runtime node implementation.\n */" },
		{ "IncludePath", "Graphs/Nodes/PaperZDAnimGraphNode_Base.h" },
		{ "ModuleRelativePath", "Private/Graphs/Nodes/PaperZDAnimGraphNode_Base.h" },
		{ "ToolTip", "Base class for all the \"Animation Graph\" nodes for PaperZD.\nMust be paired with a Runtime node implementation." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::NewProp_ShowPinForProperties_Inner = { "ShowPinForProperties", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOptionalPinFromProperty, METADATA_PARAMS(0, nullptr) }; // 2173755370
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::NewProp_ShowPinForProperties_MetaData[] = {
		{ "Category", "PinOptions" },
		{ "Comment", "/* List of cached pins to show. */" },
		{ "ModuleRelativePath", "Private/Graphs/Nodes/PaperZDAnimGraphNode_Base.h" },
		{ "ToolTip", "List of cached pins to show." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::NewProp_ShowPinForProperties = { "ShowPinForProperties", nullptr, (EPropertyFlags)0x0040000000000041, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimGraphNode_Base, ShowPinForProperties), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::NewProp_ShowPinForProperties_MetaData), Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::NewProp_ShowPinForProperties_MetaData) }; // 2173755370
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::NewProp_ShowPinForProperties_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::NewProp_ShowPinForProperties,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimGraphNode_Base>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::ClassParams = {
		&UPaperZDAnimGraphNode_Base::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::PropPointers),
		0,
		0x000000A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_Base()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimGraphNode_Base.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimGraphNode_Base.OuterSingleton, Z_Construct_UClass_UPaperZDAnimGraphNode_Base_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimGraphNode_Base.OuterSingleton;
	}
	template<> PAPERZDEDITOR_API UClass* StaticClass<UPaperZDAnimGraphNode_Base>()
	{
		return UPaperZDAnimGraphNode_Base::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimGraphNode_Base);
	UPaperZDAnimGraphNode_Base::~UPaperZDAnimGraphNode_Base() {}
	struct Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_Base_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_Base_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimGraphNode_Base, UPaperZDAnimGraphNode_Base::StaticClass, TEXT("UPaperZDAnimGraphNode_Base"), &Z_Registration_Info_UClass_UPaperZDAnimGraphNode_Base, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimGraphNode_Base), 3159844831U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_Base_h_3320264142(TEXT("/Script/PaperZDEditor"),
		Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_Base_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_Base_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
