// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "CLPlayStageGameMode.generated.h"

/**
 * 메인 게임모드
 */
UCLASS()
class PROJECTCLOUD_API ACLPlayStageGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	virtual void InitGameState() override;	
	
	virtual void StartPlay() override;	

	void HandleGameOverEvent();

	//게임 재시작
	virtual void ResetLevel() override;	

	//게임 메인화면 돌아가기
	virtual void ReturnToMainMenuHost() override;

};
