// Fill out your copyright notice in the Description page of Project Settings.

#include "DroneGame.h"
#include "DroneHUD.h"
#include "Engine/Canvas.h"

void ADroneHUD::DrawHUD() {
	DrawRect(FLinearColor(1.0f, 0.0f, 0.0f), Canvas->SizeX / 2 - 5.0f, Canvas->SizeY / 2 - 5.0f, 10.0f, 10.0f);
}


