// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PaperZDAnimInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimInstance() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_APaperZDCharacter_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimInstance();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimInstance_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimPlayer_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimSequence_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PaperZD();
// End Cross Module References
	DEFINE_FUNCTION(UPaperZDAnimInstance::execGetInstanceAssetPlayerTimeFromEndFraction)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_AssetPlayerIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetInstanceAssetPlayerTimeFromEndFraction(Z_Param_AssetPlayerIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execGetInstanceAssetPlayerTimeFromEnd)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_AssetPlayerIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetInstanceAssetPlayerTimeFromEnd(Z_Param_AssetPlayerIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execGetInstanceAssetPlayerTimeFraction)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_AssetPlayerIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetInstanceAssetPlayerTimeFraction(Z_Param_AssetPlayerIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execGetInstanceAssetPlayerTime)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_AssetPlayerIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetInstanceAssetPlayerTime(Z_Param_AssetPlayerIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execGetInstanceAssetPlayerLength)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_AssetPlayerIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetInstanceAssetPlayerLength(Z_Param_AssetPlayerIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execStopAllAnimationOverrides)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopAllAnimationOverrides();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execStopAnimationOverrideByGroup)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_GroupToStop);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopAnimationOverrideByGroup(Z_Param_GroupToStop);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execK2_PlayAnimationOverride)
	{
		P_GET_OBJECT(UPaperZDAnimSequence,Z_Param_AnimSequence);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_AnimationLength);
		P_GET_PROPERTY(FNameProperty,Z_Param_SlotName);
		P_GET_PROPERTY(FFloatProperty,Z_Param_PlayRate);
		P_GET_PROPERTY(FFloatProperty,Z_Param_StartingPosition);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->K2_PlayAnimationOverride(Z_Param_AnimSequence,Z_Param_Out_AnimationLength,Z_Param_SlotName,Z_Param_PlayRate,Z_Param_StartingPosition);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execGetPlayer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPaperZDAnimPlayer**)Z_Param__Result=P_THIS->GetPlayer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execJumpToNode)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_JumpName);
		P_GET_PROPERTY(FNameProperty,Z_Param_StateMachineName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->JumpToNode(Z_Param_JumpName,Z_Param_StateMachineName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execGetPaperCharacter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(APaperZDCharacter**)Z_Param__Result=P_THIS->GetPaperCharacter();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execGetOwningActor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AActor**)Z_Param__Result=P_THIS->GetOwningActor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execOnInit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnInit_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimInstance::execOnTick)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnTick_Implementation(Z_Param_DeltaTime);
		P_NATIVE_END;
	}
	struct PaperZDAnimInstance_eventOnAnimSequencePlaybackComplete_Parms
	{
		const UPaperZDAnimSequence* InAnimSequence;
	};
	struct PaperZDAnimInstance_eventOnAnimSequenceUpdated_Parms
	{
		const UPaperZDAnimSequence* From;
		const UPaperZDAnimSequence* To;
		float CurrentProgress;
	};
	struct PaperZDAnimInstance_eventOnTick_Parms
	{
		float DeltaTime;
	};
	static FName NAME_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete = FName(TEXT("OnAnimSequencePlaybackComplete"));
	void UPaperZDAnimInstance::OnAnimSequencePlaybackComplete(const UPaperZDAnimSequence* InAnimSequence)
	{
		PaperZDAnimInstance_eventOnAnimSequencePlaybackComplete_Parms Parms;
		Parms.InAnimSequence=InAnimSequence;
		ProcessEvent(FindFunctionChecked(NAME_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete),&Parms);
	}
	static FName NAME_UPaperZDAnimInstance_OnAnimSequenceUpdated = FName(TEXT("OnAnimSequenceUpdated"));
	void UPaperZDAnimInstance::OnAnimSequenceUpdated(const UPaperZDAnimSequence* From, const UPaperZDAnimSequence* To, float CurrentProgress)
	{
		PaperZDAnimInstance_eventOnAnimSequenceUpdated_Parms Parms;
		Parms.From=From;
		Parms.To=To;
		Parms.CurrentProgress=CurrentProgress;
		ProcessEvent(FindFunctionChecked(NAME_UPaperZDAnimInstance_OnAnimSequenceUpdated),&Parms);
	}
	static FName NAME_UPaperZDAnimInstance_OnInit = FName(TEXT("OnInit"));
	void UPaperZDAnimInstance::OnInit()
	{
		ProcessEvent(FindFunctionChecked(NAME_UPaperZDAnimInstance_OnInit),NULL);
	}
	static FName NAME_UPaperZDAnimInstance_OnTick = FName(TEXT("OnTick"));
	void UPaperZDAnimInstance::OnTick(float DeltaTime)
	{
		PaperZDAnimInstance_eventOnTick_Parms Parms;
		Parms.DeltaTime=DeltaTime;
		ProcessEvent(FindFunctionChecked(NAME_UPaperZDAnimInstance_OnTick),&Parms);
	}
	void UPaperZDAnimInstance::StaticRegisterNativesUPaperZDAnimInstance()
	{
		UClass* Class = UPaperZDAnimInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetInstanceAssetPlayerLength", &UPaperZDAnimInstance::execGetInstanceAssetPlayerLength },
			{ "GetInstanceAssetPlayerTime", &UPaperZDAnimInstance::execGetInstanceAssetPlayerTime },
			{ "GetInstanceAssetPlayerTimeFraction", &UPaperZDAnimInstance::execGetInstanceAssetPlayerTimeFraction },
			{ "GetInstanceAssetPlayerTimeFromEnd", &UPaperZDAnimInstance::execGetInstanceAssetPlayerTimeFromEnd },
			{ "GetInstanceAssetPlayerTimeFromEndFraction", &UPaperZDAnimInstance::execGetInstanceAssetPlayerTimeFromEndFraction },
			{ "GetOwningActor", &UPaperZDAnimInstance::execGetOwningActor },
			{ "GetPaperCharacter", &UPaperZDAnimInstance::execGetPaperCharacter },
			{ "GetPlayer", &UPaperZDAnimInstance::execGetPlayer },
			{ "JumpToNode", &UPaperZDAnimInstance::execJumpToNode },
			{ "K2_PlayAnimationOverride", &UPaperZDAnimInstance::execK2_PlayAnimationOverride },
			{ "OnInit", &UPaperZDAnimInstance::execOnInit },
			{ "OnTick", &UPaperZDAnimInstance::execOnTick },
			{ "StopAllAnimationOverrides", &UPaperZDAnimInstance::execStopAllAnimationOverrides },
			{ "StopAnimationOverrideByGroup", &UPaperZDAnimInstance::execStopAnimationOverrideByGroup },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics
	{
		struct PaperZDAnimInstance_eventGetInstanceAssetPlayerLength_Parms
		{
			int32 AssetPlayerIndex;
			float ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_AssetPlayerIndex;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::NewProp_AssetPlayerIndex = { "AssetPlayerIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetInstanceAssetPlayerLength_Parms, AssetPlayerIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetInstanceAssetPlayerLength_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::NewProp_AssetPlayerIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::Function_MetaDataParams[] = {
		{ "AnimGetter", "true" },
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Asset Player" },
		{ "Comment", "/** Gets the length in seconds of the asset referenced in an asset player node */" },
		{ "DisplayName", "Length" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Gets the length in seconds of the asset referenced in an asset player node" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "GetInstanceAssetPlayerLength", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::PaperZDAnimInstance_eventGetInstanceAssetPlayerLength_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::PaperZDAnimInstance_eventGetInstanceAssetPlayerLength_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics
	{
		struct PaperZDAnimInstance_eventGetInstanceAssetPlayerTime_Parms
		{
			int32 AssetPlayerIndex;
			float ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_AssetPlayerIndex;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::NewProp_AssetPlayerIndex = { "AssetPlayerIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetInstanceAssetPlayerTime_Parms, AssetPlayerIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetInstanceAssetPlayerTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::NewProp_AssetPlayerIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::Function_MetaDataParams[] = {
		{ "AnimGetter", "true" },
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Asset Player" },
		{ "Comment", "/** Get the current accumulated time in seconds for an asset player node */" },
		{ "DisplayName", "Current Time" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Get the current accumulated time in seconds for an asset player node" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "GetInstanceAssetPlayerTime", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::PaperZDAnimInstance_eventGetInstanceAssetPlayerTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::PaperZDAnimInstance_eventGetInstanceAssetPlayerTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics
	{
		struct PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFraction_Parms
		{
			int32 AssetPlayerIndex;
			float ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_AssetPlayerIndex;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::NewProp_AssetPlayerIndex = { "AssetPlayerIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFraction_Parms, AssetPlayerIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFraction_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::NewProp_AssetPlayerIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::Function_MetaDataParams[] = {
		{ "AnimGetter", "true" },
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Asset Player" },
		{ "Comment", "/** Get the current accumulated time as a fraction for an asset player node */" },
		{ "DisplayName", "Current Time (ratio)" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Get the current accumulated time as a fraction for an asset player node" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "GetInstanceAssetPlayerTimeFraction", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFraction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFraction_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics
	{
		struct PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFromEnd_Parms
		{
			int32 AssetPlayerIndex;
			float ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_AssetPlayerIndex;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::NewProp_AssetPlayerIndex = { "AssetPlayerIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFromEnd_Parms, AssetPlayerIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFromEnd_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::NewProp_AssetPlayerIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::Function_MetaDataParams[] = {
		{ "AnimGetter", "true" },
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Asset Player" },
		{ "Comment", "/** Get the time in seconds from the end of an animation in an asset player node */" },
		{ "DisplayName", "Time Remaining" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Get the time in seconds from the end of an animation in an asset player node" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "GetInstanceAssetPlayerTimeFromEnd", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFromEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFromEnd_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics
	{
		struct PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFromEndFraction_Parms
		{
			int32 AssetPlayerIndex;
			float ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_AssetPlayerIndex;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::NewProp_AssetPlayerIndex = { "AssetPlayerIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFromEndFraction_Parms, AssetPlayerIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFromEndFraction_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::NewProp_AssetPlayerIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::Function_MetaDataParams[] = {
		{ "AnimGetter", "true" },
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Asset Player" },
		{ "Comment", "/** Get the time as a fraction of the asset length of an animation in an asset player node */" },
		{ "DisplayName", "Time Remaining (ratio)" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Get the time as a fraction of the asset length of an animation in an asset player node" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "GetInstanceAssetPlayerTimeFromEndFraction", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFromEndFraction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::PaperZDAnimInstance_eventGetInstanceAssetPlayerTimeFromEndFraction_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics
	{
		struct PaperZDAnimInstance_eventGetOwningActor_Parms
		{
			AActor* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetOwningActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "PaperZD" },
		{ "Comment", "/* Obtain the actor that owns this AnimInstance. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Obtain the actor that owns this AnimInstance." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "GetOwningActor", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::PaperZDAnimInstance_eventGetOwningActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::PaperZDAnimInstance_eventGetOwningActor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics
	{
		struct PaperZDAnimInstance_eventGetPaperCharacter_Parms
		{
			APaperZDCharacter* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetPaperCharacter_Parms, ReturnValue), Z_Construct_UClass_APaperZDCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::Function_MetaDataParams[] = {
		{ "Category", "PaperZD" },
		{ "Comment", "/* Obtain the PaperZD Character that owns this instance if applicable, can be null. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Obtain the PaperZD Character that owns this instance if applicable, can be null." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "GetPaperCharacter", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::PaperZDAnimInstance_eventGetPaperCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::PaperZDAnimInstance_eventGetPaperCharacter_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics
	{
		struct PaperZDAnimInstance_eventGetPlayer_Parms
		{
			UPaperZDAnimPlayer* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventGetPlayer_Parms, ReturnValue), Z_Construct_UClass_UPaperZDAnimPlayer_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "PaperZD|Playback" },
		{ "Comment", "/* Obtains the current player, responsible of storing the playback information of this AnimInstance. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Obtains the current player, responsible of storing the playback information of this AnimInstance." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "GetPlayer", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::PaperZDAnimInstance_eventGetPlayer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::PaperZDAnimInstance_eventGetPlayer_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics
	{
		struct PaperZDAnimInstance_eventJumpToNode_Parms
		{
			FName JumpName;
			FName StateMachineName;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_JumpName;
		static const UECodeGen_Private::FNamePropertyParams NewProp_StateMachineName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::NewProp_JumpName = { "JumpName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventJumpToNode_Parms, JumpName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::NewProp_StateMachineName = { "StateMachineName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventJumpToNode_Parms, StateMachineName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::NewProp_JumpName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::NewProp_StateMachineName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::Function_MetaDataParams[] = {
		{ "Category", "PaperZD" },
		{ "Comment", "/**\n\x09 * Changes current execution state and jumps to the given JumpNode name.\n\x09 * @param JumpName\x09\x09\x09Name of the jump node we wish to go to.\n\x09 * @param StateMachineName\x09If specified, the jump link will only be applied to the given state machine.\n\x09 */" },
		{ "CPP_Default_StateMachineName", "None" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Changes current execution state and jumps to the given JumpNode name.\n@param JumpName                      Name of the jump node we wish to go to.\n@param StateMachineName      If specified, the jump link will only be applied to the given state machine." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "JumpToNode", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::PaperZDAnimInstance_eventJumpToNode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::PaperZDAnimInstance_eventJumpToNode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics
	{
		struct PaperZDAnimInstance_eventK2_PlayAnimationOverride_Parms
		{
			const UPaperZDAnimSequence* AnimSequence;
			float AnimationLength;
			FName SlotName;
			float PlayRate;
			float StartingPosition;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimSequence_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimSequence;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AnimationLength;
		static const UECodeGen_Private::FNamePropertyParams NewProp_SlotName;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StartingPosition;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_AnimSequence_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_AnimSequence = { "AnimSequence", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventK2_PlayAnimationOverride_Parms, AnimSequence), Z_Construct_UClass_UPaperZDAnimSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_AnimSequence_MetaData), Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_AnimSequence_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_AnimationLength = { "AnimationLength", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventK2_PlayAnimationOverride_Parms, AnimationLength), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventK2_PlayAnimationOverride_Parms, SlotName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventK2_PlayAnimationOverride_Parms, PlayRate), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_StartingPosition = { "StartingPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventK2_PlayAnimationOverride_Parms, StartingPosition), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_AnimSequence,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_AnimationLength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_SlotName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_PlayRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::NewProp_StartingPosition,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
		{ "Comment", "/* Play the given animation through the override slot. Returns the animation length if successful. */" },
		{ "CPP_Default_PlayRate", "1.000000" },
		{ "CPP_Default_SlotName", "DefaultSlot" },
		{ "CPP_Default_StartingPosition", "0.000000" },
		{ "DisplayName", "Play Animation Override" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Play the given animation through the override slot. Returns the animation length if successful." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "K2_PlayAnimationOverride", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::PaperZDAnimInstance_eventK2_PlayAnimationOverride_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::PaperZDAnimInstance_eventK2_PlayAnimationOverride_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InAnimSequence_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InAnimSequence;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::NewProp_InAnimSequence_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::NewProp_InAnimSequence = { "InAnimSequence", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventOnAnimSequencePlaybackComplete_Parms, InAnimSequence), Z_Construct_UClass_UPaperZDAnimSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::NewProp_InAnimSequence_MetaData), Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::NewProp_InAnimSequence_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::NewProp_InAnimSequence,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
		{ "Comment", "/**\n\x09 * Called when an AnimSequence completes playback. Will only be called for non-looping sequences, as the looping sequences do not really \"end\" their playback.\n\x09 * @param InAnimSequence\x09Sequence that reached its end\n\x09 */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Called when an AnimSequence completes playback. Will only be called for non-looping sequences, as the looping sequences do not really \"end\" their playback.\n@param InAnimSequence        Sequence that reached its end" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "OnAnimSequencePlaybackComplete", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::PropPointers), sizeof(PaperZDAnimInstance_eventOnAnimSequencePlaybackComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::PropPointers) < 2048);
	static_assert(sizeof(PaperZDAnimInstance_eventOnAnimSequencePlaybackComplete_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_From_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_From;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_To_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_To;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentProgress;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_From_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_From = { "From", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventOnAnimSequenceUpdated_Parms, From), Z_Construct_UClass_UPaperZDAnimSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_From_MetaData), Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_From_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_To_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_To = { "To", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventOnAnimSequenceUpdated_Parms, To), Z_Construct_UClass_UPaperZDAnimSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_To_MetaData), Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_To_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_CurrentProgress = { "CurrentProgress", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventOnAnimSequenceUpdated_Parms, CurrentProgress), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_From,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_To,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::NewProp_CurrentProgress,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
		{ "Comment", "/**\n\x09 * Event called when we update playback, changing to a new sequence. \n\x09 * Only called for Animation Blueprints with \"non-blendable\" animation sources (like flipbooks), as these will only ever run one animation at a time.\n\x09 * This behavior can be overridden if \"bFireSequenceUpdateEvents\" is set to true on the AnimPlayer.\n\x09 * \n\x09 * @param From\x09\x09\x09\x09The previously played sequence\n\x09 * @param To\x09\x09\x09\x09The sequence that will be played now\n\x09 * @param CurrentProgress\x09The progress in which the \"From\" sequence was before changing, ranging from [0-1]\n\x09 */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Event called when we update playback, changing to a new sequence.\nOnly called for Animation Blueprints with \"non-blendable\" animation sources (like flipbooks), as these will only ever run one animation at a time.\nThis behavior can be overridden if \"bFireSequenceUpdateEvents\" is set to true on the AnimPlayer.\n\n@param From                          The previously played sequence\n@param To                            The sequence that will be played now\n@param CurrentProgress       The progress in which the \"From\" sequence was before changing, ranging from [0-1]" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "OnAnimSequenceUpdated", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::PropPointers), sizeof(PaperZDAnimInstance_eventOnAnimSequenceUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::PropPointers) < 2048);
	static_assert(sizeof(PaperZDAnimInstance_eventOnAnimSequenceUpdated_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_OnInit_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_OnInit_Statics::Function_MetaDataParams[] = {
		{ "Category", "PaperZD" },
		{ "Comment", "/**\n\x09 * Called when the AnimInstance has been initialized, but before the first tick.\n\x09 */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Called when the AnimInstance has been initialized, but before the first tick." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_OnInit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "OnInit", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnInit_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_OnInit_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_OnInit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_OnInit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventOnTick_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics::Function_MetaDataParams[] = {
		{ "Category", "PaperZD" },
		{ "Comment", "/**\n\x09 * Called every tick, after all the animations have been processed.\n\x09 */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Called every tick, after all the animations have been processed." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "OnTick", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics::PropPointers), sizeof(PaperZDAnimInstance_eventOnTick_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics::PropPointers) < 2048);
	static_assert(sizeof(PaperZDAnimInstance_eventOnTick_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_OnTick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_OnTick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_StopAllAnimationOverrides_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_StopAllAnimationOverrides_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
		{ "Comment", "/* Stops the animation override with the given group name. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Stops the animation override with the given group name." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_StopAllAnimationOverrides_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "StopAllAnimationOverrides", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_StopAllAnimationOverrides_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_StopAllAnimationOverrides_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_StopAllAnimationOverrides()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_StopAllAnimationOverrides_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics
	{
		struct PaperZDAnimInstance_eventStopAnimationOverrideByGroup_Parms
		{
			FName GroupToStop;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_GroupToStop;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::NewProp_GroupToStop = { "GroupToStop", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimInstance_eventStopAnimationOverrideByGroup_Parms, GroupToStop), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::NewProp_GroupToStop,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
		{ "Comment", "/* Stops the animation override with the given group name. */" },
		{ "CPP_Default_GroupToStop", "DefaultGroup" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Stops the animation override with the given group name." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimInstance, nullptr, "StopAnimationOverrideByGroup", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::PaperZDAnimInstance_eventStopAnimationOverrideByGroup_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::PaperZDAnimInstance_eventStopAnimationOverrideByGroup_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimInstance);
	UClass* Z_Construct_UClass_UPaperZDAnimInstance_NoRegister()
	{
		return UPaperZDAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimPlayer_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_AnimPlayer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PaperCharacter_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PaperCharacter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIgnoreTimeDilation_MetaData[];
#endif
		static void NewProp_bIgnoreTimeDilation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIgnoreTimeDilation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAllowTransitionalStates_MetaData[];
#endif
		static void NewProp_bAllowTransitionalStates_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowTransitionalStates;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimInstance_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPaperZDAnimInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerLength, "GetInstanceAssetPlayerLength" }, // 2588902513
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTime, "GetInstanceAssetPlayerTime" }, // 702069838
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFraction, "GetInstanceAssetPlayerTimeFraction" }, // 3911288424
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEnd, "GetInstanceAssetPlayerTimeFromEnd" }, // 1878207009
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_GetInstanceAssetPlayerTimeFromEndFraction, "GetInstanceAssetPlayerTimeFromEndFraction" }, // 1048825662
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_GetOwningActor, "GetOwningActor" }, // 4053162698
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_GetPaperCharacter, "GetPaperCharacter" }, // 4057859527
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_GetPlayer, "GetPlayer" }, // 1589696145
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_JumpToNode, "JumpToNode" }, // 3018161584
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_K2_PlayAnimationOverride, "K2_PlayAnimationOverride" }, // 3648094572
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequencePlaybackComplete, "OnAnimSequencePlaybackComplete" }, // 1155883625
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_OnAnimSequenceUpdated, "OnAnimSequenceUpdated" }, // 2440522213
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_OnInit, "OnInit" }, // 2708770630
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_OnTick, "OnTick" }, // 2763075957
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_StopAllAnimationOverrides, "StopAllAnimationOverrides" }, // 840581445
		{ &Z_Construct_UFunction_UPaperZDAnimInstance_StopAnimationOverrideByGroup, "StopAnimationOverrideByGroup" }, // 4144744966
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimInstance_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Runtime class that the AnimBP gets compiled into.\n */" },
		{ "IncludePath", "PaperZDAnimInstance.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Runtime class that the AnimBP gets compiled into." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_AnimPlayer_MetaData[] = {
		{ "Comment", "/* Pointer to the Animation Player that is responsible of the playback of the sequences. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "Pointer to the Animation Player that is responsible of the playback of the sequences." },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_AnimPlayer = { "AnimPlayer", nullptr, (EPropertyFlags)0x0044000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimInstance, AnimPlayer), Z_Construct_UClass_UPaperZDAnimPlayer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_AnimPlayer_MetaData), Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_AnimPlayer_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_PaperCharacter_MetaData[] = {
		{ "BlueprintGetter", "GetPaperCharacter" },
		{ "Category", "PaperZD" },
		{ "Comment", "/**\n\x09 * The PaperZD Character that owns this instance, not null when the instance is called through a ZD character.\n\x09 * Maintained only for backwards compatibility only, one should prefer using the \"GetOwningActor\" method instead.\n\x09 *\n\x09 * It internally calls \"GetOwningActor\" while casting to a PaperZDCharacter.\n\x09 */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "The PaperZD Character that owns this instance, not null when the instance is called through a ZD character.\nMaintained only for backwards compatibility only, one should prefer using the \"GetOwningActor\" method instead.\n\nIt internally calls \"GetOwningActor\" while casting to a PaperZDCharacter." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_PaperCharacter = { "PaperCharacter", nullptr, (EPropertyFlags)0x0040000000002014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimInstance, PaperCharacter), Z_Construct_UClass_APaperZDCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_PaperCharacter_MetaData), Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_PaperCharacter_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bIgnoreTimeDilation_MetaData[] = {
		{ "Category", "PaperZD" },
		{ "Comment", "/* If this AnimBP should globally ignore time dilation. */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "If this AnimBP should globally ignore time dilation." },
	};
#endif
	void Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bIgnoreTimeDilation_SetBit(void* Obj)
	{
		((UPaperZDAnimInstance*)Obj)->bIgnoreTimeDilation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bIgnoreTimeDilation = { "bIgnoreTimeDilation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaperZDAnimInstance), &Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bIgnoreTimeDilation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bIgnoreTimeDilation_MetaData), Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bIgnoreTimeDilation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bAllowTransitionalStates_MetaData[] = {
		{ "Category", "PaperZD" },
		{ "Comment", "/**\n\x09 * If we should enable Transitional States, so even after transitioning from State A to State B, we allow for more levels of recursions.\n\x09 * This allows for a simpler more compact graph, by just connecting states and let them naturally flow to the end state, without seeing flicker as it's done on the same frame.\n\x09 * Deactivating this makes each state become an end-state on each tick, and flow has to be done manually, but is overall faster.\n\x09 */" },
		{ "ModuleRelativePath", "Public/PaperZDAnimInstance.h" },
		{ "ToolTip", "If we should enable Transitional States, so even after transitioning from State A to State B, we allow for more levels of recursions.\nThis allows for a simpler more compact graph, by just connecting states and let them naturally flow to the end state, without seeing flicker as it's done on the same frame.\nDeactivating this makes each state become an end-state on each tick, and flow has to be done manually, but is overall faster." },
	};
#endif
	void Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bAllowTransitionalStates_SetBit(void* Obj)
	{
		((UPaperZDAnimInstance*)Obj)->bAllowTransitionalStates = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bAllowTransitionalStates = { "bAllowTransitionalStates", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaperZDAnimInstance), &Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bAllowTransitionalStates_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bAllowTransitionalStates_MetaData), Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bAllowTransitionalStates_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDAnimInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_AnimPlayer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_PaperCharacter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bIgnoreTimeDilation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimInstance_Statics::NewProp_bAllowTransitionalStates,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimInstance_Statics::ClassParams = {
		&UPaperZDAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPaperZDAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimInstance_Statics::PropPointers),
		0,
		0x001000A9u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimInstance_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimInstance_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDAnimInstance()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimInstance.OuterSingleton, Z_Construct_UClass_UPaperZDAnimInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimInstance.OuterSingleton;
	}
	template<> PAPERZD_API UClass* StaticClass<UPaperZDAnimInstance>()
	{
		return UPaperZDAnimInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimInstance);
	UPaperZDAnimInstance::~UPaperZDAnimInstance() {}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimInstance, UPaperZDAnimInstance::StaticClass, TEXT("UPaperZDAnimInstance"), &Z_Registration_Info_UClass_UPaperZDAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimInstance), 1661563836U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimInstance_h_3053400914(TEXT("/Script/PaperZD"),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_PaperZD_Source_PaperZD_Public_PaperZDAnimInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
