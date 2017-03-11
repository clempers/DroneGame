// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Drone.h"
#include "FormationController.generated.h"

/**
 * 
 */
UCLASS()
class DRONEGAME_API AFormationController : public AAIController
{
	GENERATED_BODY()
	
public:
	AFormationController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Orbit")
		float rotationPeriod;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
		float timeEllapsed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
		float orbitRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	TArray<ADrone*> drones;

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PossessDrone(ADrone* Drone);
};
