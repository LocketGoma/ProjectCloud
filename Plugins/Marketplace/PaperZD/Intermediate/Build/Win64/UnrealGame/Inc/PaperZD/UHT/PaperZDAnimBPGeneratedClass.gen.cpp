// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PaperZDAnimBPGeneratedClass.h"
#include "AnimNodes/PaperZDAnimNode_Base.h"
#include "AnimNodes/PaperZDAnimStateMachine.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimBPGeneratedClass() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintGeneratedClass();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimationSource_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimBPGeneratedClass();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_NoRegister();
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimBPDebugData();
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimStateMachine();
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDExposedValueHandler();
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor();
	UPackage* Z_Construct_UPackage__Script_PaperZD();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PaperZDAnimBPDebugData;
class UScriptStruct* FPaperZDAnimBPDebugData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PaperZDAnimBPDebugData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PaperZDAnimBPDebugData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPaperZDAnimBPDebugData, (UObject*)Z_Construct_UPackage__Script_PaperZD(), TEXT("PaperZDAnimBPDebugData"));
	}
	return Z_Registration_Info_UScriptStruct_PaperZDAnimBPDebugData.OuterSingleton;
}
template<> PAPERZD_API UScriptStruct* StaticStruct<FPaperZDAnimBPDebugData>()
{
	return FPaperZDAnimBPDebugData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPaperZDAnimBPDebugData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDAnimBPDebugData_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * Structure that holds the debug data for a given AnimBP class\n */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimBPGeneratedClass.h" },
		{ "ToolTip", "Structure that holds the debug data for a given AnimBP class" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPaperZDAnimBPDebugData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPaperZDAnimBPDebugData>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPaperZDAnimBPDebugData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
		nullptr,
		&NewStructOps,
		"PaperZDAnimBPDebugData",
		nullptr,
		0,
		sizeof(FPaperZDAnimBPDebugData),
		alignof(FPaperZDAnimBPDebugData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDAnimBPDebugData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPaperZDAnimBPDebugData_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPaperZDAnimBPDebugData()
	{
		if (!Z_Registration_Info_UScriptStruct_PaperZDAnimBPDebugData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PaperZDAnimBPDebugData.InnerSingleton, Z_Construct_UScriptStruct_FPaperZDAnimBPDebugData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PaperZDAnimBPDebugData.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PaperZDOverrideSlotDescriptor;
class UScriptStruct* FPaperZDOverrideSlotDescriptor::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PaperZDOverrideSlotDescriptor.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PaperZDOverrideSlotDescriptor.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor, (UObject*)Z_Construct_UPackage__Script_PaperZD(), TEXT("PaperZDOverrideSlotDescriptor"));
	}
	return Z_Registration_Info_UScriptStruct_PaperZDOverrideSlotDescriptor.OuterSingleton;
}
template<> PAPERZD_API UScriptStruct* StaticStruct<FPaperZDOverrideSlotDescriptor>()
{
	return FPaperZDOverrideSlotDescriptor::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/* Holds the descriptor for a slot override that has been registered to the class. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimBPGeneratedClass.h" },
		{ "ToolTip", "Holds the descriptor for a slot override that has been registered to the class." },
	};
#endif
	void* Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPaperZDOverrideSlotDescriptor>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewProp_SlotName_MetaData[] = {
		{ "Comment", "/* Name of the slot, unique. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimBPGeneratedClass.h" },
		{ "ToolTip", "Name of the slot, unique." },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPaperZDOverrideSlotDescriptor, SlotName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewProp_SlotName_MetaData), Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewProp_SlotName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewProp_GroupName_MetaData[] = {
		{ "Comment", "/* Name of the group that the slot belongs to. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimBPGeneratedClass.h" },
		{ "ToolTip", "Name of the group that the slot belongs to." },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewProp_GroupName = { "GroupName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPaperZDOverrideSlotDescriptor, GroupName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewProp_GroupName_MetaData), Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewProp_GroupName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewProp_SlotName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewProp_GroupName,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
		nullptr,
		&NewStructOps,
		"PaperZDOverrideSlotDescriptor",
		Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::PropPointers),
		sizeof(FPaperZDOverrideSlotDescriptor),
		alignof(FPaperZDOverrideSlotDescriptor),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor()
	{
		if (!Z_Registration_Info_UScriptStruct_PaperZDOverrideSlotDescriptor.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PaperZDOverrideSlotDescriptor.InnerSingleton, Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PaperZDOverrideSlotDescriptor.InnerSingleton;
	}
	void UPaperZDAnimBPGeneratedClass::StaticRegisterNativesUPaperZDAnimBPGeneratedClass()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimBPGeneratedClass);
	UClass* Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_NoRegister()
	{
		return UPaperZDAnimBPGeneratedClass::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SupportedAnimationSource_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_SupportedAnimationSource;
		static const UECodeGen_Private::FStructPropertyParams NewProp_EvaluateGraphExposedInputs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EvaluateGraphExposedInputs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_EvaluateGraphExposedInputs;
		static const UECodeGen_Private::FStructPropertyParams NewProp_StateMachines_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StateMachines_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_StateMachines;
		static const UECodeGen_Private::FNamePropertyParams NewProp_AnimNotifyFunctionMapping_ValueProp;
		static const UECodeGen_Private::FNamePropertyParams NewProp_AnimNotifyFunctionMapping_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimNotifyFunctionMapping_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_AnimNotifyFunctionMapping;
		static const UECodeGen_Private::FStructPropertyParams NewProp_RegisteredOverrideSlots_ValueProp;
		static const UECodeGen_Private::FNamePropertyParams NewProp_RegisteredOverrideSlots_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RegisteredOverrideSlots_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_RegisteredOverrideSlots;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintGeneratedClass,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Generated class for the PaperZDAnimBP.\n */" },
		{ "IncludePath", "PaperZDAnimBPGeneratedClass.h" },
		{ "ModuleRelativePath", "Public/PaperZDAnimBPGeneratedClass.h" },
		{ "ToolTip", "Generated class for the PaperZDAnimBP." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_SupportedAnimationSource_MetaData[] = {
		{ "Comment", "/* The animation source that the class has been compiled to support. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimBPGeneratedClass.h" },
		{ "ToolTip", "The animation source that the class has been compiled to support." },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_SupportedAnimationSource = { "SupportedAnimationSource", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimBPGeneratedClass, SupportedAnimationSource), Z_Construct_UClass_UPaperZDAnimationSource_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_SupportedAnimationSource_MetaData), Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_SupportedAnimationSource_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_EvaluateGraphExposedInputs_Inner = { "EvaluateGraphExposedInputs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPaperZDExposedValueHandler, METADATA_PARAMS(0, nullptr) }; // 2377893110
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_EvaluateGraphExposedInputs_MetaData[] = {
		{ "Comment", "/* List of the exposed value handlers. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimBPGeneratedClass.h" },
		{ "ToolTip", "List of the exposed value handlers." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_EvaluateGraphExposedInputs = { "EvaluateGraphExposedInputs", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimBPGeneratedClass, EvaluateGraphExposedInputs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_EvaluateGraphExposedInputs_MetaData), Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_EvaluateGraphExposedInputs_MetaData) }; // 2377893110
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_StateMachines_Inner = { "StateMachines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPaperZDAnimStateMachine, METADATA_PARAMS(0, nullptr) }; // 721407113
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_StateMachines_MetaData[] = {
		{ "Comment", "/* List of state machine definitions. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimBPGeneratedClass.h" },
		{ "ToolTip", "List of state machine definitions." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_StateMachines = { "StateMachines", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimBPGeneratedClass, StateMachines), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_StateMachines_MetaData), Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_StateMachines_MetaData) }; // 721407113
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_AnimNotifyFunctionMapping_ValueProp = { "AnimNotifyFunctionMapping", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_AnimNotifyFunctionMapping_Key_KeyProp = { "AnimNotifyFunctionMapping_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_AnimNotifyFunctionMapping_MetaData[] = {
		{ "Comment", "/* Mapping between Custom AnimNotify name to function name. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimBPGeneratedClass.h" },
		{ "ToolTip", "Mapping between Custom AnimNotify name to function name." },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_AnimNotifyFunctionMapping = { "AnimNotifyFunctionMapping", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimBPGeneratedClass, AnimNotifyFunctionMapping), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_AnimNotifyFunctionMapping_MetaData), Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_AnimNotifyFunctionMapping_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_RegisteredOverrideSlots_ValueProp = { "RegisteredOverrideSlots", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor, METADATA_PARAMS(0, nullptr) }; // 755288744
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_RegisteredOverrideSlots_Key_KeyProp = { "RegisteredOverrideSlots_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_RegisteredOverrideSlots_MetaData[] = {
		{ "Comment", "/* List of registered override animation slots for this class, keyed by the slot name */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimBPGeneratedClass.h" },
		{ "ToolTip", "List of registered override animation slots for this class, keyed by the slot name" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_RegisteredOverrideSlots = { "RegisteredOverrideSlots", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimBPGeneratedClass, RegisteredOverrideSlots), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_RegisteredOverrideSlots_MetaData), Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_RegisteredOverrideSlots_MetaData) }; // 755288744
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_SupportedAnimationSource,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_EvaluateGraphExposedInputs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_EvaluateGraphExposedInputs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_StateMachines_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_StateMachines,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_AnimNotifyFunctionMapping_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_AnimNotifyFunctionMapping_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_AnimNotifyFunctionMapping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_RegisteredOverrideSlots_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_RegisteredOverrideSlots_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::NewProp_RegisteredOverrideSlots,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimBPGeneratedClass>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::ClassParams = {
		&UPaperZDAnimBPGeneratedClass::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::PropPointers),
		0,
		0x009200A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDAnimBPGeneratedClass()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimBPGeneratedClass.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimBPGeneratedClass.OuterSingleton, Z_Construct_UClass_UPaperZDAnimBPGeneratedClass_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimBPGeneratedClass.OuterSingleton;
	}
	template<> PAPERZD_API UClass* StaticClass<UPaperZDAnimBPGeneratedClass>()
	{
		return UPaperZDAnimBPGeneratedClass::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimBPGeneratedClass);
	UPaperZDAnimBPGeneratedClass::~UPaperZDAnimBPGeneratedClass() {}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimBPGeneratedClass_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimBPGeneratedClass_h_Statics::ScriptStructInfo[] = {
		{ FPaperZDAnimBPDebugData::StaticStruct, Z_Construct_UScriptStruct_FPaperZDAnimBPDebugData_Statics::NewStructOps, TEXT("PaperZDAnimBPDebugData"), &Z_Registration_Info_UScriptStruct_PaperZDAnimBPDebugData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPaperZDAnimBPDebugData), 70599037U) },
		{ FPaperZDOverrideSlotDescriptor::StaticStruct, Z_Construct_UScriptStruct_FPaperZDOverrideSlotDescriptor_Statics::NewStructOps, TEXT("PaperZDOverrideSlotDescriptor"), &Z_Registration_Info_UScriptStruct_PaperZDOverrideSlotDescriptor, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPaperZDOverrideSlotDescriptor), 755288744U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimBPGeneratedClass_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimBPGeneratedClass, UPaperZDAnimBPGeneratedClass::StaticClass, TEXT("UPaperZDAnimBPGeneratedClass"), &Z_Registration_Info_UClass_UPaperZDAnimBPGeneratedClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimBPGeneratedClass), 2416164852U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimBPGeneratedClass_h_2457277300(TEXT("/Script/PaperZD"),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimBPGeneratedClass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimBPGeneratedClass_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimBPGeneratedClass_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimBPGeneratedClass_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
