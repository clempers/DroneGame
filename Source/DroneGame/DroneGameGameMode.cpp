// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DroneGame.h"
#include "DroneGameGameMode.h"
#include "DroneGameCharacter.h"
#include "DroneGameState.h"
#include "DroneHud.h"

ADroneGameGameMode::ADroneGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/AnimStarterPack/Ue4ASP_Character"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	GameStateClass = ADroneGameState::StaticClass();

	HUDClass = ADroneHUD::StaticClass();
}
