//ProjectCloud 공용 Struct 리스트 (주로 데이터테이블용)
#pragma once

#include "CoreMinimal.h"
#include "Stats/Stats.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"
#include "Engine/DataTable.h"
#include "Templates/UniquePtr.h"


#include "CLCommonStruct.generated.h"

#define DATA_NONE -1;


USTRUCT()
struct PROJECTCLOUD_API FLevelExperienceTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Experience")
	int32 Level;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Experience")
	int64 RequireExperience;

	/** Constructors */
	FLevelExperienceTableRow() {}
	FLevelExperienceTableRow(uint32 Level, uint64 RequireExperience) : Level(Level), RequireExperience(RequireExperience) {}
	FLevelExperienceTableRow(FLevelExperienceTableRow const& Other);
		

	/** Assignment/Equality operators */
	FLevelExperienceTableRow& operator=(FLevelExperienceTableRow const& Other);
	bool operator==(FLevelExperienceTableRow const& Other) const;
	bool operator!=(FLevelExperienceTableRow const& Other) const;

};