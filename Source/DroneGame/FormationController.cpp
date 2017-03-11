// Fill out your copyright notice in the Description page of Project Settings.

#include "DroneGame.h"
#include "Drone.h"
#include "FormationController.h"
#include "DroneGameState.h"

AFormationController::AFormationController() {
	PrimaryActorTick.bCanEverTick = true;
	orbitRadius = 100.0f;
	rotationPeriod = 10.0f;
	drones = TArray<ADrone*>();
}

void AFormationController::Tick(float DeltaTime) {
	GetWorld()->GetGameState<ADroneGameState>()->FormationController = this;
	timeEllapsed += DeltaTime;
	if (timeEllapsed > rotationPeriod)
		timeEllapsed -= rotationPeriod;
	if (drones.Num() !=0) {
		float baseRadians = 2.0f * PI * timeEllapsed / rotationPeriod;
		float iRadians = 2.0f * PI / drones.Num();
		for (int32 i = 0; i < drones.Num(); i++) {
			float radians = baseRadians + i * iRadians;
			FVector dest = GetRootComponent()->GetComponentLocation() + (orbitRadius * FVector(cos(radians), sin(radians), 0.0f));
			drones[i]->GetMovementComponent()->AddInputVector(dest - drones[i]->GetActorLocation());
		}
	}
}

void AFormationController::PossessDrone(ADrone * Drone)
{
	drones.Add(Drone);
}



