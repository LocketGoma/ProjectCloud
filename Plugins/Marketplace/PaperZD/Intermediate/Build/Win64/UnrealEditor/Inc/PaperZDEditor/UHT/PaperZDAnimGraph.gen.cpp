// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../Private/Graphs/PaperZDAnimGraph.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimGraph() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UEdGraph();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraph();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraph_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PaperZDEditor();
// End Cross Module References
	void UPaperZDAnimGraph::StaticRegisterNativesUPaperZDAnimGraph()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimGraph);
	UClass* Z_Construct_UClass_UPaperZDAnimGraph_NoRegister()
	{
		return UPaperZDAnimGraph::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimGraph_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimGraph_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraph,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZDEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraph_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimGraph_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Base class for the Animation Graph for PaperZD\n */" },
#endif
		{ "IncludePath", "Graphs/PaperZDAnimGraph.h" },
		{ "ModuleRelativePath", "Private/Graphs/PaperZDAnimGraph.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base class for the Animation Graph for PaperZD" },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimGraph_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimGraph>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimGraph_Statics::ClassParams = {
		&UPaperZDAnimGraph::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000800A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraph_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimGraph_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPaperZDAnimGraph()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimGraph.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimGraph.OuterSingleton, Z_Construct_UClass_UPaperZDAnimGraph_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimGraph.OuterSingleton;
	}
	template<> PAPERZDEDITOR_API UClass* StaticClass<UPaperZDAnimGraph>()
	{
		return UPaperZDAnimGraph::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimGraph);
	UPaperZDAnimGraph::~UPaperZDAnimGraph() {}
	struct Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_PaperZDAnimGraph_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_PaperZDAnimGraph_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimGraph, UPaperZDAnimGraph::StaticClass, TEXT("UPaperZDAnimGraph"), &Z_Registration_Info_UClass_UPaperZDAnimGraph, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimGraph), 2238820476U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_PaperZDAnimGraph_h_505291024(TEXT("/Script/PaperZDEditor"),
		Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_PaperZDAnimGraph_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_PaperZDAnimGraph_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
