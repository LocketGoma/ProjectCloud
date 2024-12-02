// Copyright @Locketgoma. All Rights Reserved.

#pragma once

#include "UObject/NoExportTypes.h"
#include "UObject/Object.h" 
#include "GameplayTagContainer.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLSpellInstance.generated.h"

//DataAsset으로 바꿀까 했는데 DataAsset이 UObject 보다 갖고있는게 많네....

/**
 * 마법 정보를 담고 있는 인스턴스
 */

//필요시 struct 구조로..
//USTRUCT(BlueprintType)
//struct PROJECTCLOUD_API FSpellInstance
//{
//	GENERATED_USTRUCT_BODY()
//
//};

UCLASS(BlueprintType, Blueprintable)
class PROJECTCLOUD_API UCLSpellInstance : public UObject
{
	GENERATED_BODY()

public:
	//유틸함수들
	static const TArray<EArrowInputHandleType> GetSpellCommands(UCLSpellInstance& Instance);
	static const TArray<EArrowInputHandleType> GetSpellCommands(TSubclassOf<UCLSpellInstance> Instance);

	static const FGameplayTag GetSpellTag(UCLSpellInstance& Instance);
	static const FGameplayTag GetSpellTag(TSubclassOf<UCLSpellInstance> Instance);

	static const EActiveSpellType GetSpellType(UCLSpellInstance& Instance);
	static const EActiveSpellType GetSpellType(TSubclassOf<UCLSpellInstance> Instance);


public:
	UPROPERTY(EditDefaultsOnly)
	EActiveSpellType SpellType;

	//입력해야하는 커맨드를 순서대로 지정해주세요
	UPROPERTY(EditDefaultsOnly)
	TArray<EArrowInputHandleType> SpellCommands;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag SpellTag;
};
