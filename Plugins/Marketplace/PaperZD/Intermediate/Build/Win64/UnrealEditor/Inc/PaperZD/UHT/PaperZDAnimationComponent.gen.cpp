// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PaperZDAnimationComponent.h"
#include "../../Source/Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "PaperZDComponentReference.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaperZDAnimationComponent() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FComponentReference();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimationComponent();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimationComponent_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimInstance_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDAnimInstanceManager_NoRegister();
	PAPERZD_API UClass* Z_Construct_UClass_UPaperZDSequencerSource_NoRegister();
	PAPERZD_API UScriptStruct* Z_Construct_UScriptStruct_FPaperZDComponentReference();
	UPackage* Z_Construct_UPackage__Script_PaperZD();
// End Cross Module References
	DEFINE_FUNCTION(UPaperZDAnimationComponent::execSetAnimInstanceClass)
	{
		P_GET_OBJECT(UClass,Z_Param_InAnimInstanceClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAnimInstanceClass(Z_Param_InAnimInstanceClass);
		P_NATIVE_END;
	}
	void UPaperZDAnimationComponent::StaticRegisterNativesUPaperZDAnimationComponent()
	{
		UClass* Class = UPaperZDAnimationComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetAnimInstanceClass", &UPaperZDAnimationComponent::execSetAnimInstanceClass },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics
	{
		struct PaperZDAnimationComponent_eventSetAnimInstanceClass_Parms
		{
			TSubclassOf<UPaperZDAnimInstance>  InAnimInstanceClass;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_InAnimInstanceClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::NewProp_InAnimInstanceClass = { "InAnimInstanceClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PaperZDAnimationComponent_eventSetAnimInstanceClass_Parms, InAnimInstanceClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UPaperZDAnimInstance_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::NewProp_InAnimInstanceClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::Function_MetaDataParams[] = {
		{ "Category", "PaperZD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Sets the AnimInstanceClass to use, replacing any AnimInstane that could already be running. */" },
#endif
		{ "ModuleRelativePath", "Public/PaperZDAnimationComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the AnimInstanceClass to use, replacing any AnimInstane that could already be running." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaperZDAnimationComponent, nullptr, "SetAnimInstanceClass", nullptr, nullptr, Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::PaperZDAnimationComponent_eventSetAnimInstanceClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::PaperZDAnimationComponent_eventSetAnimInstanceClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPaperZDAnimationComponent);
	UClass* Z_Construct_UClass_UPaperZDAnimationComponent_NoRegister()
	{
		return UPaperZDAnimationComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPaperZDAnimationComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimInstanceClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_AnimInstanceClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RenderComponent_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RenderComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RenderComponentRef_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RenderComponentRef;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_AnimInstance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaperZDAnimationComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_PaperZD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimationComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPaperZDAnimationComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPaperZDAnimationComponent_SetAnimInstanceClass, "SetAnimInstanceClass" }, // 533773518
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimationComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimationComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "PaperZD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Provides an interface for running an Animation Blueprint on any actor.\n */" },
#endif
		{ "DisplayName", "PaperZD Animation" },
		{ "IncludePath", "PaperZDAnimationComponent.h" },
		{ "ModuleRelativePath", "Public/PaperZDAnimationComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides an interface for running an Animation Blueprint on any actor." },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_AnimInstanceClass_MetaData[] = {
		{ "Category", "PaperZD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Animation blueprint class to use. */" },
#endif
		{ "ModuleRelativePath", "Public/PaperZDAnimationComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Animation blueprint class to use." },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_AnimInstanceClass = { "AnimInstanceClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimationComponent, AnimInstanceClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UPaperZDAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_AnimInstanceClass_MetaData), Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_AnimInstanceClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_RenderComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* DEPRECATED: Render component to update when using the animation blueprints. Superseded by the new component ref. */" },
#endif
		{ "ModuleRelativePath", "Public/PaperZDAnimationComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "DEPRECATED: Render component to update when using the animation blueprints. Superseded by the new component ref." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_RenderComponent = { "RenderComponent", nullptr, (EPropertyFlags)0x0040000020000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimationComponent, RenderComponent_DEPRECATED), Z_Construct_UScriptStruct_FComponentReference, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_RenderComponent_MetaData), Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_RenderComponent_MetaData) }; // 834145860
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_RenderComponentRef_MetaData[] = {
		{ "AllowAnyComponent", "" },
		{ "AllowedClasses", "/Script/Engine.PrimitiveComponent" },
		{ "Category", "PaperZD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Render component to update when using the animation blueprints. */" },
#endif
		{ "ModuleRelativePath", "Public/PaperZDAnimationComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Render component to update when using the animation blueprints." },
#endif
		{ "UseComponentPicker", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_RenderComponentRef = { "RenderComponentRef", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimationComponent, RenderComponentRef), Z_Construct_UScriptStruct_FPaperZDComponentReference, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_RenderComponentRef_MetaData), Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_RenderComponentRef_MetaData) }; // 2905931635
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_AnimInstance_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "PaperZD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The animation instance used for managing the animation. */" },
#endif
		{ "ModuleRelativePath", "Public/PaperZDAnimationComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The animation instance used for managing the animation." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_AnimInstance = { "AnimInstance", nullptr, (EPropertyFlags)0x0044000000002014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPaperZDAnimationComponent, AnimInstance), Z_Construct_UClass_UPaperZDAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_AnimInstance_MetaData), Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_AnimInstance_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPaperZDAnimationComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_AnimInstanceClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_RenderComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_RenderComponentRef,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPaperZDAnimationComponent_Statics::NewProp_AnimInstance,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UPaperZDAnimationComponent_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UPaperZDAnimInstanceManager_NoRegister, (int32)VTABLE_OFFSET(UPaperZDAnimationComponent, IPaperZDAnimInstanceManager), false },  // 1805320539
			{ Z_Construct_UClass_UPaperZDSequencerSource_NoRegister, (int32)VTABLE_OFFSET(UPaperZDAnimationComponent, IPaperZDSequencerSource), false },  // 2485786959
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimationComponent_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaperZDAnimationComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaperZDAnimationComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPaperZDAnimationComponent_Statics::ClassParams = {
		&UPaperZDAnimationComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPaperZDAnimationComponent_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimationComponent_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimationComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPaperZDAnimationComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPaperZDAnimationComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPaperZDAnimationComponent()
	{
		if (!Z_Registration_Info_UClass_UPaperZDAnimationComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPaperZDAnimationComponent.OuterSingleton, Z_Construct_UClass_UPaperZDAnimationComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPaperZDAnimationComponent.OuterSingleton;
	}
	template<> PAPERZD_API UClass* StaticClass<UPaperZDAnimationComponent>()
	{
		return UPaperZDAnimationComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaperZDAnimationComponent);
	UPaperZDAnimationComponent::~UPaperZDAnimationComponent() {}
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(UPaperZDAnimationComponent)
	struct Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_PaperZDAnimationComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_PaperZDAnimationComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPaperZDAnimationComponent, UPaperZDAnimationComponent::StaticClass, TEXT("UPaperZDAnimationComponent"), &Z_Registration_Info_UClass_UPaperZDAnimationComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPaperZDAnimationComponent), 2348811030U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_PaperZDAnimationComponent_h_2262983016(TEXT("/Script/PaperZD"),
		Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_PaperZDAnimationComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ProjectCloud_Plugins_Marketplace_PaperZD_Source_PaperZD_Public_PaperZDAnimationComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
