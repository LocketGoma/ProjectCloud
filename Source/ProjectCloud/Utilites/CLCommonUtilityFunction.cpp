// Fill out your copyright notice in the Description page of Project Settings.

#include "CLCommonUtilityFunction.h"
#include "ProjectCloud/Character/CLPlayerState.h"
#include "ProjectCloud/Character/CLHeroCharacter.h"
#include "ProjectCloud/Character/CLPlayerController.h"

ACLPlayerController* CLCommonUtilites::GetPlayerControllerFromActor(AActor* Actor)
{
	ACLPlayerController* CLPlayerController = nullptr;
	if (Actor)
	{
		//1. Actor가 PS인 경우
		if (ACLPlayerState* PS = Cast<ACLPlayerState>(Actor))
		{
			CLPlayerController = Cast<ACLPlayerController>(PS->GetPlayerController());

		}

		//2. Actor가 Hero Character인 경우
		else if (ACLHeroCharacter* PlayerPawn = Cast<ACLHeroCharacter>(Actor))
		{
			CLPlayerController = Cast<ACLPlayerController>(PlayerPawn->GetController());
		}
	}
	return CLPlayerController;
}