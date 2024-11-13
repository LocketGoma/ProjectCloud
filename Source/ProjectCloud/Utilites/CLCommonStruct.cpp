// Fill out your copyright notice in the Description page of Project Settings.


#include "CLCommonStruct.h"

FLevelExperienceTableRow::FLevelExperienceTableRow(FLevelExperienceTableRow const& Other)
{
	*this = Other;
}

PROJECTCLOUD_API FLevelExperienceTableRow& FLevelExperienceTableRow::operator=(FLevelExperienceTableRow const& Other)
{
	// TODO: 여기에 return 문을 삽입합니다.
	if (this == &Other)
	{
		return *this;
	}
	Level = Other.Level;
	RequireExperience = Other.RequireExperience;

	return *this;
}

PROJECTCLOUD_API bool FLevelExperienceTableRow::operator==(FLevelExperienceTableRow const& Other) const
{
	return (Level == Other.Level) && (RequireExperience == Other.RequireExperience);
}

PROJECTCLOUD_API bool FLevelExperienceTableRow::operator!=(FLevelExperienceTableRow const& Other) const
{
	return (Level != Other.Level) || (RequireExperience != Other.RequireExperience);
}
