// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimNodes/PaperZDAnimNode_OverrideSlot.h"
#include "AnimNodes/PaperZDAnimNode_Base.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimNode_OverrideSlot() {}
// Cross Module References
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimDataLink();
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimNode_Base();
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot();
	UPackage* Z_Construct_UPackage__Script_PaperZD();
// End Cross Module References

static_assert(std::is_polymorphic<FPaperZDAnimNode_OverrideSlot>() == std::is_polymorphic<FPaperZDAnimNode_Base>(), "USTRUCT FPaperZDAnimNode_OverrideSlot cannot be polymorphic unless super FPaperZDAnimNode_Base is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PaperZDAnimNode_OverrideSlot;
class UScriptStruct* FPaperZDAnimNode_OverrideSlot::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PaperZDAnimNode_OverrideSlot.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PaperZDAnimNode_OverrideSlot.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot, (UObject*)Z_Construct_UPackage__Script_PaperZD(), TEXT("PaperZDAnimNode_OverrideSlot"));
	}
	return Z_Registration_Info_UScriptStruct_PaperZDAnimNode_OverrideSlot.OuterSingleton;
}
template<> PAPERZD_API UScriptStruct* StaticStruct<FPaperZDAnimNode_OverrideSlot>()
{
	return FPaperZDAnimNode_OverrideSlot::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Animation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Animation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SlotName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GroupName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_GroupName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * Creates an entry point for animations to be played through code that will override the AnimationGraph.\n */" },
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_OverrideSlot.h" },
		{ "ToolTip", "Creates an entry point for animations to be played through code that will override the AnimationGraph." },
	};
#endif
	void* Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPaperZDAnimNode_OverrideSlot>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_Animation_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/* Animation entry. */" },
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_OverrideSlot.h" },
		{ "ToolTip", "Animation entry." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_Animation = { "Animation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPaperZDAnimNode_OverrideSlot, Animation), Z_Construct_UScriptStruct_FPaperZDAnimDataLink, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_Animation_MetaData), Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_Animation_MetaData) }; // 3757750682
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_SlotName_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/* Name of the slot which will be called through code. */" },
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_OverrideSlot.h" },
		{ "NeverAsPin", "" },
		{ "ToolTip", "Name of the slot which will be called through code." },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPaperZDAnimNode_OverrideSlot, SlotName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_SlotName_MetaData), Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_SlotName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_GroupName_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/* Group that this slot belongs to. Only one override can be played per group and any new animation played will cancel every override on this group. */" },
		{ "ModuleRelativePath", "Public/AnimNodes/PaperZDAnimNode_OverrideSlot.h" },
		{ "NeverAsPin", "" },
		{ "ToolTip", "Group that this slot belongs to. Only one override can be played per group and any new animation played will cancel every override on this group." },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_GroupName = { "GroupName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPaperZDAnimNode_OverrideSlot, GroupName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_GroupName_MetaData), Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_GroupName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_Animation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_SlotName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewProp_GroupName,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
		Z_Construct_UScriptStruct_FPaperZDAnimNode_Base,
		&NewStructOps,
		"PaperZDAnimNode_OverrideSlot",
		Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::PropPointers),
		sizeof(FPaperZDAnimNode_OverrideSlot),
		alignof(FPaperZDAnimNode_OverrideSlot),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot()
	{
		if (!Z_Registration_Info_UScriptStruct_PaperZDAnimNode_OverrideSlot.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PaperZDAnimNode_OverrideSlot.InnerSingleton, Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PaperZDAnimNode_OverrideSlot.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_AnimNodes_PaperZDAnimNode_OverrideSlot_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_AnimNodes_PaperZDAnimNode_OverrideSlot_h_Statics::ScriptStructInfo[] = {
		{ FPaperZDAnimNode_OverrideSlot::StaticStruct, Z_Construct_UScriptStruct_FPaperZDAnimNode_OverrideSlot_Statics::NewStructOps, TEXT("PaperZDAnimNode_OverrideSlot"), &Z_Registration_Info_UScriptStruct_PaperZDAnimNode_OverrideSlot, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPaperZDAnimNode_OverrideSlot), 3684210991U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_AnimNodes_PaperZDAnimNode_OverrideSlot_h_118182010(TEXT("/Script/PaperZD"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_AnimNodes_PaperZDAnimNode_OverrideSlot_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_AnimNodes_PaperZDAnimNode_OverrideSlot_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
