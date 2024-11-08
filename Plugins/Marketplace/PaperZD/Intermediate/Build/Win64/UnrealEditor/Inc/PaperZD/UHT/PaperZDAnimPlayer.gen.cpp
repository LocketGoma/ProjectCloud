// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimSequences/Players/PaperZDAnimPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimPlayer() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimPlayer();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimPlayer_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimSequence_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDPlaybackHandle_NoRegister();
	PAPERZD_API UEnum* Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode();
	PAPERZD_API UFunction* Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature();
	PAPERZD_API UFunction* Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature();
	PAPERZD_API UFunction* Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_PaperZD();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAnimPlayerPlaybackMode;
	static UEnum* EAnimPlayerPlaybackMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EAnimPlayerPlaybackMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EAnimPlayerPlaybackMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode, (UObject*)Z_Construct_UPackage__Script_PaperZD(), TEXT("EAnimPlayerPlaybackMode"));
		}
		return Z_Registration_Info_UEnum_EAnimPlayerPlaybackMode.OuterSingleton;
	}
	template<> PAPERZD_API UEnum* StaticEnum<EAnimPlayerPlaybackMode>()
	{
		return EAnimPlayerPlaybackMode_StaticEnum();
	}
	struct Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode_Statics::Enumerators[] = {
		{ "EAnimPlayerPlaybackMode::Forward", (int64)EAnimPlayerPlaybackMode::Forward },
		{ "EAnimPlayerPlaybackMode::Reversed", (int64)EAnimPlayerPlaybackMode::Reversed },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * The type of playbacks available for the player\n */" },
#endif
		{ "Forward.DisplayName", "Forward" },
		{ "Forward.Name", "EAnimPlayerPlaybackMode::Forward" },
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
		{ "Reversed.DisplayName", "Reversed" },
		{ "Reversed.Name", "EAnimPlayerPlaybackMode::Reversed" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The type of playbacks available for the player" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PaperZD,
		nullptr,
		"EAnimPlayerPlaybackMode",
		"EAnimPlayerPlaybackMode",
		Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode()
	{
		if (!Z_Registration_Info_UEnum_EAnimPlayerPlaybackMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAnimPlayerPlaybackMode.InnerSingleton, Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EAnimPlayerPlaybackMode.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics
	{
		struct _Script_PaperZD_eventOnPlaybackSequenceChangedSignature_Parms
		{
			const UPaperZDAnimSequence* From;
			const UPaperZDAnimSequence* To;
			float CurrentProgress;
		};
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_From_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_From = { "From", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_PaperZD_eventOnPlaybackSequenceChangedSignature_Parms, From), Z_Construct_UClass_UPaperZDAnimSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_From_MetaData), Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_From_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_To_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_To = { "To", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_PaperZD_eventOnPlaybackSequenceChangedSignature_Parms, To), Z_Construct_UClass_UPaperZDAnimSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_To_MetaData), Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_To_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_CurrentProgress = { "CurrentProgress", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_PaperZD_eventOnPlaybackSequenceChangedSignature_Parms, CurrentProgress), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_From,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_To,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::NewProp_CurrentProgress,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_PaperZD, nullptr, "OnPlaybackSequenceChangedSignature__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::_Script_PaperZD_eventOnPlaybackSequenceChangedSignature_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::_Script_PaperZD_eventOnPlaybackSequenceChangedSignature_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnPlaybackSequenceChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnPlaybackSequenceChangedSignature, const UPaperZDAnimSequence* From, const UPaperZDAnimSequence* To, float CurrentProgress)
{
	struct _Script_PaperZD_eventOnPlaybackSequenceChangedSignature_Parms
	{
		const UPaperZDAnimSequence* From;
		const UPaperZDAnimSequence* To;
		float CurrentProgress;
	};
	_Script_PaperZD_eventOnPlaybackSequenceChangedSignature_Parms Parms;
	Parms.From=From;
	Parms.To=To;
	Parms.CurrentProgress=CurrentProgress;
	OnPlaybackSequenceChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics
	{
		struct _Script_PaperZD_eventOnPlaybackSequenceCompleteSignature_Parms
		{
			const UPaperZDAnimSequence* AnimSequence;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimSequence_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimSequence;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::NewProp_AnimSequence_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::NewProp_AnimSequence = { "AnimSequence", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_PaperZD_eventOnPlaybackSequenceCompleteSignature_Parms, AnimSequence), Z_Construct_UClass_UPaperZDAnimSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::NewProp_AnimSequence_MetaData), Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::NewProp_AnimSequence_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::NewProp_AnimSequence,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_PaperZD, nullptr, "OnPlaybackSequenceCompleteSignature__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::_Script_PaperZD_eventOnPlaybackSequenceCompleteSignature_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::_Script_PaperZD_eventOnPlaybackSequenceCompleteSignature_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnPlaybackSequenceCompleteSignature_DelegateWrapper(const FMulticastScriptDelegate& OnPlaybackSequenceCompleteSignature, const UPaperZDAnimSequence* AnimSequence)
{
	struct _Script_PaperZD_eventOnPlaybackSequenceCompleteSignature_Parms
	{
		const UPaperZDAnimSequence* AnimSequence;
	};
	_Script_PaperZD_eventOnPlaybackSequenceCompleteSignature_Parms Parms;
	Parms.AnimSequence=AnimSequence;
	OnPlaybackSequenceCompleteSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics
	{
		struct _Script_PaperZD_eventOnPlaybackSequenceLoopedSignature_Parms
		{
			const UPaperZDAnimSequence* AnimSequence;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimSequence_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimSequence;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::NewProp_AnimSequence_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::NewProp_AnimSequence = { "AnimSequence", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_PaperZD_eventOnPlaybackSequenceLoopedSignature_Parms, AnimSequence), Z_Construct_UClass_UPaperZDAnimSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::NewProp_AnimSequence_MetaData), Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::NewProp_AnimSequence_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::NewProp_AnimSequence,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_PaperZD, nullptr, "OnPlaybackSequenceLoopedSignature__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::_Script_PaperZD_eventOnPlaybackSequenceLoopedSignature_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::_Script_PaperZD_eventOnPlaybackSequenceLoopedSignature_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnPlaybackSequenceLoopedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnPlaybackSequenceLoopedSignature, const UPaperZDAnimSequence* AnimSequence)
{
	struct _Script_PaperZD_eventOnPlaybackSequenceLoopedSignature_Parms
	{
		const UPaperZDAnimSequence* AnimSequence;
	};
	_Script_PaperZD_eventOnPlaybackSequenceLoopedSignature_Parms Parms;
	Parms.AnimSequence=AnimSequence;
	OnPlaybackSequenceLoopedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UPaperZDAnimPlayer::execSetCurrentPlaybackTime)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_InCurrentTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCurrentPlaybackTime(Z_Param_InCurrentTime);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimPlayer::execPausePlayback)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PausePlayback();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimPlayer::execResumePlayback)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResumePlayback();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimPlayer::execIsPlaying)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsPlaying();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimPlayer::execRegisterRenderComponent)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_RenderComponent);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RegisterRenderComponent(Z_Param_RenderComponent);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimPlayer::execGetCurrentAnimSequence)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(const UPaperZDAnimSequence**)Z_Param__Result=P_THIS->GetCurrentAnimSequence();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimPlayer::execGetPlaybackProgress)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetPlaybackProgress();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPaperZDAnimPlayer::execGetCurrentPlaybackTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetCurrentPlaybackTime();
		P_NATIVE_END;
	}
	void UPaperZDAnimPlayer::StaticRegisterNativesUPaperZDAnimPlayer()
	{
		UClass* Class = UPaperZDAnimPlayer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCurrentAnimSequence", &UPaperZDAnimPlayer::execGetCurrentAnimSequence },
			{ "GetCurrentPlaybackTime", &UPaperZDAnimPlayer::execGetCurrentPlaybackTime },
			{ "GetPlaybackProgress", &UPaperZDAnimPlayer::execGetPlaybackProgress },
			{ "IsPlaying", &UPaperZDAnimPlayer::execIsPlaying },
			{ "PausePlayback", &UPaperZDAnimPlayer::execPausePlayback },
			{ "RegisterRenderComponent", &UPaperZDAnimPlayer::execRegisterRenderComponent },
			{ "ResumePlayback", &UPaperZDAnimPlayer::execResumePlayback },
			{ "SetCurrentPlaybackTime", &UPaperZDAnimPlayer::execSetCurrentPlaybackTime },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics
	{
		struct PaperZDAnimPlayer_eventGetCurrentAnimSequence_Parms
		{
			const UPaperZDAnimSequence* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimPlayer_eventGetCurrentAnimSequence_Parms, ReturnValue), Z_Construct_UClass_UPaperZDAnimSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Obtain the current, biggest weighted, animation sequence that was rendered this frame.\n\x09 * \n\x09 * Non blending animation sources (like flipbooks) can use this method to know which animation is playing without much concern.\n\x09 * Blending enabled animation sources (2d bones) should be wary that it will only take the most relevant animation into account.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Obtain the current, biggest weighted, animation sequence that was rendered this frame.\n\nNon blending animation sources (like flipbooks) can use this method to know which animation is playing without much concern.\nBlending enabled animation sources (2d bones) should be wary that it will only take the most relevant animation into account." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimPlayer, nullptr, "GetCurrentAnimSequence", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::PaperZDAnimPlayer_eventGetCurrentAnimSequence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::PaperZDAnimPlayer_eventGetCurrentAnimSequence_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics
	{
		struct PaperZDAnimPlayer_eventGetCurrentPlaybackTime_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimPlayer_eventGetCurrentPlaybackTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Obtain the last played time of the primary animation that is currently being played.\n\x09 * \n\x09 * Non blending animation sources (like flipbooks) can use this method to know which animation is playing.\n\x09 * Blending enabled animation sources should be wary that it will only take the most relevant animation into account.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Obtain the last played time of the primary animation that is currently being played.\n\nNon blending animation sources (like flipbooks) can use this method to know which animation is playing.\nBlending enabled animation sources should be wary that it will only take the most relevant animation into account." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimPlayer, nullptr, "GetCurrentPlaybackTime", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::PaperZDAnimPlayer_eventGetCurrentPlaybackTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::PaperZDAnimPlayer_eventGetCurrentPlaybackTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics
	{
		struct PaperZDAnimPlayer_eventGetPlaybackProgress_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimPlayer_eventGetPlaybackProgress_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Obtain the progress, ranging from [0-1] of the the primary animation that is currently being played.\n\x09 *\n\x09 * Non blending animation sources (like flipbooks) can use this method to know which animation is playing without much concern.\n\x09 * Blending enabled animation sources (2d bones) should be wary that it will only take the most relevant animation into account.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Obtain the progress, ranging from [0-1] of the the primary animation that is currently being played.\n\nNon blending animation sources (like flipbooks) can use this method to know which animation is playing without much concern.\nBlending enabled animation sources (2d bones) should be wary that it will only take the most relevant animation into account." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimPlayer, nullptr, "GetPlaybackProgress", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::PaperZDAnimPlayer_eventGetPlaybackProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::PaperZDAnimPlayer_eventGetPlaybackProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics
	{
		struct PaperZDAnimPlayer_eventIsPlaying_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PaperZDAnimPlayer_eventIsPlaying_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PaperZDAnimPlayer_eventIsPlaying_Parms), &Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Returns true if the player is currently running. */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true if the player is currently running." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimPlayer, nullptr, "IsPlaying", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::PaperZDAnimPlayer_eventIsPlaying_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::PaperZDAnimPlayer_eventIsPlaying_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimPlayer_PausePlayback_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimPlayer_PausePlayback_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Pauses the updating of the animation nodes. */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pauses the updating of the animation nodes." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimPlayer_PausePlayback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimPlayer, nullptr, "PausePlayback", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_PausePlayback_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimPlayer_PausePlayback_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPaperZDAnimPlayer_PausePlayback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimPlayer_PausePlayback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics
	{
		struct PaperZDAnimPlayer_eventRegisterRenderComponent_Parms
		{
			UPrimitiveComponent* RenderComponent;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RenderComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::NewProp_RenderComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::NewProp_RenderComponent = { "RenderComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimPlayer_eventRegisterRenderComponent_Parms, RenderComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::NewProp_RenderComponent_MetaData), Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::NewProp_RenderComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::NewProp_RenderComponent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Registers the render component to use for rendering the animation sequences.\n\x09 * @param RenderComponent\x09\x09\x09RenderComponent to be registered.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Registers the render component to use for rendering the animation sequences.\n@param RenderComponent                       RenderComponent to be registered." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimPlayer, nullptr, "RegisterRenderComponent", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::PaperZDAnimPlayer_eventRegisterRenderComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::PaperZDAnimPlayer_eventRegisterRenderComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimPlayer_ResumePlayback_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimPlayer_ResumePlayback_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Resumes the updating of the animation nodes. */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Resumes the updating of the animation nodes." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimPlayer_ResumePlayback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimPlayer, nullptr, "ResumePlayback", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_ResumePlayback_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimPlayer_ResumePlayback_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPaperZDAnimPlayer_ResumePlayback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimPlayer_ResumePlayback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics
	{
		struct PaperZDAnimPlayer_eventSetCurrentPlaybackTime_Parms
		{
			float InCurrentTime;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InCurrentTime;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::NewProp_InCurrentTime = { "InCurrentTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimPlayer_eventSetCurrentPlaybackTime_Parms, InCurrentTime), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::NewProp_InCurrentTime,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//@Deprecated Function: The playback progress is now managed by each \"PlaySequence\" node and thus, this method will not do anything.\n" },
#endif
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Playback progress is now managed and stored by each PlaySequence node. This method will have no effect and will be removed in a later version." },
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@Deprecated Function: The playback progress is now managed by each \"PlaySequence\" node and thus, this method will not do anything." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimPlayer, nullptr, "SetCurrentPlaybackTime", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::PaperZDAnimPlayer_eventSetCurrentPlaybackTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::PaperZDAnimPlayer_eventSetCurrentPlaybackTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimPlayer);
	UClass* Z_Construct_UClass_UPaperZDAnimPlayer_NoRegister()
	{
		return UPaperZDAnimPlayer::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlaybackHandle_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_PlaybackHandle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RegisteredRenderComponent_MetaData[];
#endif
		static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_RegisteredRenderComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPlaybackSequenceChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlaybackSequenceChanged;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPlaybackSequenceComplete_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlaybackSequenceComplete;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPlaybackSequenceLooped_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlaybackSequenceLooped;
		static const UECodeGen_Private::FBytePropertyParams NewProp_PlaybackMode_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlaybackMode_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_PlaybackMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bFireSequenceChangedEvents_MetaData[];
#endif
		static void NewProp_bFireSequenceChangedEvents_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFireSequenceChangedEvents;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPaperZDAnimPlayer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentAnimSequence, "GetCurrentAnimSequence" }, // 1700846927
		{ &Z_Construct_UFunction_UPaperZDAnimPlayer_GetCurrentPlaybackTime, "GetCurrentPlaybackTime" }, // 655313966
		{ &Z_Construct_UFunction_UPaperZDAnimPlayer_GetPlaybackProgress, "GetPlaybackProgress" }, // 479326498
		{ &Z_Construct_UFunction_UPaperZDAnimPlayer_IsPlaying, "IsPlaying" }, // 3662916661
		{ &Z_Construct_UFunction_UPaperZDAnimPlayer_PausePlayback, "PausePlayback" }, // 172130003
		{ &Z_Construct_UFunction_UPaperZDAnimPlayer_RegisterRenderComponent, "RegisterRenderComponent" }, // 4113949372
		{ &Z_Construct_UFunction_UPaperZDAnimPlayer_ResumePlayback, "ResumePlayback" }, // 163439222
		{ &Z_Construct_UFunction_UPaperZDAnimPlayer_SetCurrentPlaybackTime, "SetCurrentPlaybackTime" }, // 1837136106
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimPlayer_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Object responsible for driving the animation sequences playback, ticking notifies and parsing the animation data into the final animation mix.\n */" },
#endif
		{ "IncludePath", "AnimSequences/Players/PaperZDAnimPlayer.h" },
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Object responsible for driving the animation sequences playback, ticking notifies and parsing the animation data into the final animation mix." },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackHandle_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Pointer to the handle that manages render playback for the animation instance. */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pointer to the handle that manages render playback for the animation instance." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackHandle = { "PlaybackHandle", nullptr, (EPropertyFlags)0x0044000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimPlayer, PlaybackHandle), Z_Construct_UClass_UPaperZDPlaybackHandle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackHandle_MetaData), Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackHandle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_RegisteredRenderComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The component that the player is using for rendering the animations. */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The component that the player is using for rendering the animations." },
#endif
	};
#endif
	const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_RegisteredRenderComponent = { "RegisteredRenderComponent", nullptr, (EPropertyFlags)0x0044000000082008, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimPlayer, RegisteredRenderComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_RegisteredRenderComponent_MetaData), Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_RegisteredRenderComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceChanged_MetaData[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Delegate called when the player just starts playing a new sequence, different from the one played last frame.\n\x09 * This delegate only gets called for non-blendable animations (like flipbooks), and will be disabled (not called) for blendable sources (skeleton based animations).\n\x09 * This behavior can be overridden by changing the \"bFireqSequenceChangedEvents\" flag on the AnimPlayer.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate called when the player just starts playing a new sequence, different from the one played last frame.\nThis delegate only gets called for non-blendable animations (like flipbooks), and will be disabled (not called) for blendable sources (skeleton based animations).\nThis behavior can be overridden by changing the \"bFireqSequenceChangedEvents\" flag on the AnimPlayer." },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceChanged = { "OnPlaybackSequenceChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimPlayer, OnPlaybackSequenceChanged), Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceChanged_MetaData), Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceChanged_MetaData) }; // 912943348
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceComplete_MetaData[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when the currently played AnimSequence reaches its end. Will only be called for non-looping sequences.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when the currently played AnimSequence reaches its end. Will only be called for non-looping sequences." },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceComplete = { "OnPlaybackSequenceComplete", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimPlayer, OnPlaybackSequenceComplete), Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceCompleteSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceComplete_MetaData), Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceComplete_MetaData) }; // 1375609104
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceLooped_MetaData[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when the currently played AnimSequence loops. Only called if the playback is set to loop.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when the currently played AnimSequence loops. Only called if the playback is set to loop." },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceLooped = { "OnPlaybackSequenceLooped", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimPlayer, OnPlaybackSequenceLooped), Z_Construct_UDelegateFunction_PaperZD_OnPlaybackSequenceLoopedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceLooped_MetaData), Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceLooped_MetaData) }; // 4032296138
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackMode_MetaData[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Current playback mode. */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current playback mode." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackMode = { "PlaybackMode", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimPlayer, PlaybackMode), Z_Construct_UEnum_PaperZD_EAnimPlayerPlaybackMode, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackMode_MetaData), Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackMode_MetaData) }; // 986087232
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_bFireSequenceChangedEvents_MetaData[] = {
		{ "Category", "Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * If true, the system will fire the \"OnPlaybackSequenceChanged\".\n\x09 * Defaults to true for \"non-blendable\" animation sources (like flipbooks).\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/AnimSequences/Players/PaperZDAnimPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, the system will fire the \"OnPlaybackSequenceChanged\".\nDefaults to true for \"non-blendable\" animation sources (like flipbooks)." },
#endif
	};
#endif
	void Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_bFireSequenceChangedEvents_SetBit(void* Obj)
	{
		((UPaperZDAnimPlayer*)Obj)->bFireSequenceChangedEvents = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_bFireSequenceChangedEvents = { "bFireSequenceChangedEvents", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPaperZDAnimPlayer), &Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_bFireSequenceChangedEvents_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_bFireSequenceChangedEvents_MetaData), Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_bFireSequenceChangedEvents_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDAnimPlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackHandle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_RegisteredRenderComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceComplete,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_OnPlaybackSequenceLooped,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_PlaybackMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimPlayer_Statics::NewProp_bFireSequenceChangedEvents,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimPlayer_Statics::ClassParams = {
		&UPaperZDAnimPlayer::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPaperZDAnimPlayer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimPlayer_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimPlayer_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDAnimPlayer()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimPlayer.OuterSingleton, Z_Construct_UClass_UPaperZDAnimPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimPlayer.OuterSingleton;
	}
	template<> PAPERZD_API UClass* StaticClass<UPaperZDAnimPlayer>()
	{
		return UPaperZDAnimPlayer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimPlayer);
	UPaperZDAnimPlayer::~UPaperZDAnimPlayer() {}
	struct Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimSequences_Players_PaperZDAnimPlayer_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimSequences_Players_PaperZDAnimPlayer_h_Statics::EnumInfo[] = {
		{ EAnimPlayerPlaybackMode_StaticEnum, TEXT("EAnimPlayerPlaybackMode"), &Z_Registration_Info_UEnum_EAnimPlayerPlaybackMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 986087232U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimSequences_Players_PaperZDAnimPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimPlayer, UPaperZDAnimPlayer::StaticClass, TEXT("UPaperZDAnimPlayer"), &Z_Registration_Info_UClass_UPaperZDAnimPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimPlayer), 823671083U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimSequences_Players_PaperZDAnimPlayer_h_2870564194(TEXT("/Script/PaperZD"),
		Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimSequences_Players_PaperZDAnimPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimSequences_Players_PaperZDAnimPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimSequences_Players_PaperZDAnimPlayer_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_AnimSequences_Players_PaperZDAnimPlayer_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
