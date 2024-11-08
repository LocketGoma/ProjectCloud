// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimNodes/PaperZDAnimNode_Base.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimNode_Base() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UFunction();
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimDataLink();
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimNode_Base();
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDExposedValueHandler();
	UPackage* Z_Construct_UPackage__Script_PaperZD();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PaperZDAnimDataLink;
class UScriptStruct* FPaperZDAnimDataLink::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PaperZDAnimDataLink.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PaperZDAnimDataLink.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPaperZDAnimDataLink, (UObject*)Z_Construct_UPackage__Script_PaperZD(), TEXT("PaperZDAnimDataLink"));
	}
	return Z_Registration_Info_UScriptStruct_PaperZDAnimDataLink.OuterSingleton;
}
template<> PAPERZD_API UScriptStruct* StaticStruct<FPaperZDAnimDataLink>()
{
	return FPaperZDAnimDataLink::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LinkID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_LinkID;
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SourceLinkID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceLinkID;
#endif // WITH_EDITORONLY_DATA
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Represents a link to another Animation Node.\n */" },
#endif
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Represents a link to another Animation Node." },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPaperZDAnimDataLink>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewProp_LinkID_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Target ID that this link points to*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target ID that this link points to" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewProp_LinkID = { "LinkID", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPaperZDAnimDataLink, LinkID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewProp_LinkID_MetaData), Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewProp_LinkID_MetaData) };
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewProp_SourceLinkID_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Source ID that this link comes from */" },
#endif
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Source ID that this link comes from" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewProp_SourceLinkID = { "SourceLinkID", nullptr, (EPropertyFlags)0x0010000800000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPaperZDAnimDataLink, SourceLinkID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewProp_SourceLinkID_MetaData), Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewProp_SourceLinkID_MetaData) };
#endif // WITH_EDITORONLY_DATA
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewProp_LinkID,
#if WITH_EDITORONLY_DATA
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewProp_SourceLinkID,
#endif // WITH_EDITORONLY_DATA
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
		nullptr,
		&NewStructOps,
		"PaperZDAnimDataLink",
		Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::PropPointers),
		sizeof(FPaperZDAnimDataLink),
		alignof(FPaperZDAnimDataLink),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimDataLink()
	{
		if (!Z_Registration_Info_UScriptStruct_PaperZDAnimDataLink.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PaperZDAnimDataLink.InnerSingleton, Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PaperZDAnimDataLink.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PaperZDExposedValueHandler;
class UScriptStruct* FPaperZDExposedValueHandler::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PaperZDExposedValueHandler.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PaperZDExposedValueHandler.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPaperZDExposedValueHandler, (UObject*)Z_Construct_UPackage__Script_PaperZD(), TEXT("PaperZDExposedValueHandler"));
	}
	return Z_Registration_Info_UScriptStruct_PaperZDExposedValueHandler.OuterSingleton;
}
template<> PAPERZD_API UScriptStruct* StaticStruct<FPaperZDExposedValueHandler>()
{
	return FPaperZDExposedValueHandler::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoundFunction_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_BoundFunction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Function_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Function;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ValueHandlerNodeProperty_MetaData[];
#endif
		static const UECodeGen_Private::FFieldPathPropertyParams NewProp_ValueHandlerNodeProperty;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// An exposed value updater\n" },
#endif
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "An exposed value updater" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPaperZDExposedValueHandler>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_BoundFunction_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The function to call to update associated properties (can be NULL). */" },
#endif
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The function to call to update associated properties (can be NULL)." },
#endif
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_BoundFunction = { "BoundFunction", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPaperZDExposedValueHandler, BoundFunction), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_BoundFunction_MetaData), Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_BoundFunction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_Function_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Cached UFunction. */" },
#endif
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached UFunction." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_Function = { "Function", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPaperZDExposedValueHandler, Function), Z_Construct_UClass_UFunction, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_Function_MetaData), Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_Function_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_ValueHandlerNodeProperty_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Node property that this value handler is associated with, when the node\n// is instantiated from this property the node's ExposedValueHandler will \n// point back to this FExposedValueHandler:\n" },
#endif
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Node property that this value handler is associated with, when the node\nis instantiated from this property the node's ExposedValueHandler will\npoint back to this FExposedValueHandler:" },
#endif
	};
#endif
	const UECodeGen_Private::FFieldPathPropertyParams Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_ValueHandlerNodeProperty = { "ValueHandlerNodeProperty", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::FieldPath, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPaperZDExposedValueHandler, ValueHandlerNodeProperty), &FStructProperty::StaticClass, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_ValueHandlerNodeProperty_MetaData), Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_ValueHandlerNodeProperty_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_BoundFunction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_Function,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewProp_ValueHandlerNodeProperty,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
		nullptr,
		&NewStructOps,
		"PaperZDExposedValueHandler",
		Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::PropPointers),
		sizeof(FPaperZDExposedValueHandler),
		alignof(FPaperZDExposedValueHandler),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPaperZDExposedValueHandler()
	{
		if (!Z_Registration_Info_UScriptStruct_PaperZDExposedValueHandler.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PaperZDExposedValueHandler.InnerSingleton, Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PaperZDExposedValueHandler.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PaperZDAnimNode_Base;
class UScriptStruct* FPaperZDAnimNode_Base::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PaperZDAnimNode_Base.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PaperZDAnimNode_Base.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPaperZDAnimNode_Base, (UObject*)Z_Construct_UPackage__Script_PaperZD(), TEXT("PaperZDAnimNode_Base"));
	}
	return Z_Registration_Info_UScriptStruct_PaperZDAnimNode_Base.OuterSingleton;
}
template<> PAPERZD_API UScriptStruct* StaticStruct<FPaperZDAnimNode_Base>()
{
	return FPaperZDAnimNode_Base::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPaperZDAnimNode_Base_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDAnimNode_Base_Statics::Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Runtime implementation of an Animation Node.\n */" },
#endif
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime implementation of an Animation Node." },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FPaperZDAnimNode_Base_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPaperZDAnimNode_Base>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPaperZDAnimNode_Base_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
		nullptr,
		&NewStructOps,
		"PaperZDAnimNode_Base",
		nullptr,
		0,
		sizeof(FPaperZDAnimNode_Base),
		alignof(FPaperZDAnimNode_Base),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimNode_Base_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPaperZDAnimNode_Base_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimNode_Base()
	{
		if (!Z_Registration_Info_UScriptStruct_PaperZDAnimNode_Base.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PaperZDAnimNode_Base.InnerSingleton, Z_Construct_UScriptStruct_FPaperZDAnimNode_Base_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PaperZDAnimNode_Base.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimNodes_PaperZDAnimNode_Base_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimNodes_PaperZDAnimNode_Base_h_Statics::ScriptStructInfo[] = {
		{ FPaperZDAnimDataLink::StaticStruct, Z_Construct_UScriptStruct_FPaperZDAnimDataLink_Statics::NewStructOps, TEXT("PaperZDAnimDataLink"), &Z_Registration_Info_UScriptStruct_PaperZDAnimDataLink, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPaperZDAnimDataLink), 508956938U) },
		{ FPaperZDExposedValueHandler::StaticStruct, Z_Construct_UScriptStruct_FPaperZDExposedValueHandler_Statics::NewStructOps, TEXT("PaperZDExposedValueHandler"), &Z_Registration_Info_UScriptStruct_PaperZDExposedValueHandler, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPaperZDExposedValueHandler), 2835639367U) },
		{ FPaperZDAnimNode_Base::StaticStruct, Z_Construct_UScriptStruct_FPaperZDAnimNode_Base_Statics::NewStructOps, TEXT("PaperZDAnimNode_Base"), &Z_Registration_Info_UScriptStruct_PaperZDAnimNode_Base, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPaperZDAnimNode_Base), 4065574670U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimNodes_PaperZDAnimNode_Base_h_2801127435(TEXT("/Script/PaperZD"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimNodes_PaperZDAnimNode_Base_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimNodes_PaperZDAnimNode_Base_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
