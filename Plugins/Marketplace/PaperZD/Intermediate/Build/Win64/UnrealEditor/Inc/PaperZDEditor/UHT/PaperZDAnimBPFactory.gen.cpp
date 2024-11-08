// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../Private/Factories/PaperZDAnimBPFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimBPFactory() {}
// Cross Module References
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimBPFactory();
	PAPERZDEDITOR_API UClass* Z_Construct_UClass_UPaperZDAnimBPFactory_NoRegister();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_PaperZDEditor();
// End Cross Module References
	void UPaperZDAnimBPFactory::StaticRegisterNativesUPaperZDAnimBPFactory()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimBPFactory);
	UClass* Z_Construct_UClass_UPaperZDAnimBPFactory_NoRegister()
	{
		return UPaperZDAnimBPFactory::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimBPFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimBPFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZDEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimBPFactory_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimBPFactory_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Factory for PaperZD Animation Blueprints.\n */" },
#endif
		{ "IncludePath", "Factories/PaperZDAnimBPFactory.h" },
		{ "ModuleRelativePath", "Private/Factories/PaperZDAnimBPFactory.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Factory for PaperZD Animation Blueprints." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimBPFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimBPFactory>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimBPFactory_Statics::ClassParams = {
		&UPaperZDAnimBPFactory::StaticClass,
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
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimBPFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimBPFactory_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPaperZDAnimBPFactory()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimBPFactory.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimBPFactory.OuterSingleton, Z_Construct_UClass_UPaperZDAnimBPFactory_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimBPFactory.OuterSingleton;
	}
	template<> PAPERZDEDITOR_API UClass* StaticClass<UPaperZDAnimBPFactory>()
	{
		return UPaperZDAnimBPFactory::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimBPFactory);
	UPaperZDAnimBPFactory::~UPaperZDAnimBPFactory() {}
	struct Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Factories_PaperZDAnimBPFactory_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Factories_PaperZDAnimBPFactory_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimBPFactory, UPaperZDAnimBPFactory::StaticClass, TEXT("UPaperZDAnimBPFactory"), &Z_Registration_Info_UClass_UPaperZDAnimBPFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimBPFactory), 2436192808U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Factories_PaperZDAnimBPFactory_h_1868393219(TEXT("/Script/PaperZDEditor"),
		Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Factories_PaperZDAnimBPFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZDEditor_Private_Factories_PaperZDAnimBPFactory_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
