// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../Private/Graphs/Nodes/PaperZDAnimGraphNode_SelectByInt.h"
#include "AnimNodes/PaperZDAnimNode_SelectByInt.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimGraphNode_SelectByInt() {}
// Cross Module References
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimNode_SelectByInt();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_Base();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PaperZDEditor();
// End Cross Module References
	void UPaperZDAnimGraphNode_SelectByInt::StaticRegisterNativesUPaperZDAnimGraphNode_SelectByInt()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimGraphNode_SelectByInt);
	UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_NoRegister()
	{
		return UPaperZDAnimGraphNode_SelectByInt::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimNode_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AnimNode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPaperZDAnimGraphNode_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZDEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Selects between two animations depending on a given boolean value.\n */" },
#endif
		{ "IncludePath", "Graphs/Nodes/PaperZDAnimGraphNode_SelectByInt.h" },
		{ "ModuleRelativePath", "Private/Graphs/Nodes/PaperZDAnimGraphNode_SelectByInt.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Selects between two animations depending on a given boolean value." },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::NewProp_AnimNode_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Runtime node. */" },
#endif
		{ "ModuleRelativePath", "Private/Graphs/Nodes/PaperZDAnimGraphNode_SelectByInt.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime node." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::NewProp_AnimNode = { "AnimNode", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimGraphNode_SelectByInt, AnimNode), Z_Construct_UScriptStruct_FPaperZDAnimNode_SelectByInt, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::NewProp_AnimNode_MetaData), Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::NewProp_AnimNode_MetaData) }; // 667240344
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::NewProp_AnimNode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimGraphNode_SelectByInt>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::ClassParams = {
		&UPaperZDAnimGraphNode_SelectByInt::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimGraphNode_SelectByInt.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimGraphNode_SelectByInt.OuterSingleton, Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimGraphNode_SelectByInt.OuterSingleton;
	}
	template<> PAPERZDEDITOR_API UClass* StaticClass<UPaperZDAnimGraphNode_SelectByInt>()
	{
		return UPaperZDAnimGraphNode_SelectByInt::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimGraphNode_SelectByInt);
	UPaperZDAnimGraphNode_SelectByInt::~UPaperZDAnimGraphNode_SelectByInt() {}
	struct Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_SelectByInt_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_SelectByInt_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimGraphNode_SelectByInt, UPaperZDAnimGraphNode_SelectByInt::StaticClass, TEXT("UPaperZDAnimGraphNode_SelectByInt"), &Z_Registration_Info_UClass_UPaperZDAnimGraphNode_SelectByInt, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimGraphNode_SelectByInt), 3214315491U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_SelectByInt_h_3680153334(TEXT("/Script/PaperZDEditor"),
		Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_SelectByInt_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_Nodes_PaperZDAnimGraphNode_SelectByInt_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
