// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "DroneHUD.generated.h"

/**
 * 
 */
UCLASS()
class DRONEGAME_API ADroneHUD : public AHUD
{
	GENERATED_BODY()
	
	
	
public:
	virtual void DrawHUD() override;
};
