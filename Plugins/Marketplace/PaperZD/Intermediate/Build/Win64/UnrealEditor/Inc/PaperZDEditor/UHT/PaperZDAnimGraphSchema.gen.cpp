// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../Private/Graphs/PaperZDAnimGraphSchema.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimGraphSchema() {}
// Cross Module References
	BLUEPRINTGRAPH_API UClass* Z_Construct_UClass_UEdGraphSchema_K2();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraphSchema();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimGraphSchema_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PaperZDEditor();
// End Cross Module References
	void UPaperZDAnimGraphSchema::StaticRegisterNativesUPaperZDAnimGraphSchema()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimGraphSchema);
	UClass* Z_Construct_UClass_UPaperZDAnimGraphSchema_NoRegister()
	{
		return UPaperZDAnimGraphSchema::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultEvaluationHandlerName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_DefaultEvaluationHandlerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraphSchema_K2,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZDEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graphs/PaperZDAnimGraphSchema.h" },
		{ "ModuleRelativePath", "Private/Graphs/PaperZDAnimGraphSchema.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::NewProp_DefaultEvaluationHandlerName_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Name of the generated function used to get the exposed pins data. */" },
#endif
		{ "ModuleRelativePath", "Private/Graphs/PaperZDAnimGraphSchema.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the generated function used to get the exposed pins data." },
#endif
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::NewProp_DefaultEvaluationHandlerName = { "DefaultEvaluationHandlerName", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimGraphSchema, DefaultEvaluationHandlerName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::NewProp_DefaultEvaluationHandlerName_MetaData), Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::NewProp_DefaultEvaluationHandlerName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::NewProp_DefaultEvaluationHandlerName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimGraphSchema>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::ClassParams = {
		&UPaperZDAnimGraphSchema::StaticClass,
		"Editor",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::PropPointers),
		0,
		0x000800A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDAnimGraphSchema()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimGraphSchema.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimGraphSchema.OuterSingleton, Z_Construct_UClass_UPaperZDAnimGraphSchema_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimGraphSchema.OuterSingleton;
	}
	template<> PAPERZDEDITOR_API UClass* StaticClass<UPaperZDAnimGraphSchema>()
	{
		return UPaperZDAnimGraphSchema::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimGraphSchema);
	UPaperZDAnimGraphSchema::~UPaperZDAnimGraphSchema() {}
	struct Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_PaperZDAnimGraphSchema_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_PaperZDAnimGraphSchema_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimGraphSchema, UPaperZDAnimGraphSchema::StaticClass, TEXT("UPaperZDAnimGraphSchema"), &Z_Registration_Info_UClass_UPaperZDAnimGraphSchema, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimGraphSchema), 3115662167U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_PaperZDAnimGraphSchema_h_225104957(TEXT("/Script/PaperZDEditor"),
		Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_PaperZDAnimGraphSchema_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Graphs_PaperZDAnimGraphSchema_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
