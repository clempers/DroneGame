// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameStateBase.h"
#include "DroneGameState.generated.h"

/**
 * 
 */
UCLASS()
class DRONEGAME_API ADroneGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AFormationController* FormationController;
};
