// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SpringArmComponent.h"
#include "OffsetSpringArm.generated.h"

/**
 * 
 */
UCLASS()
class DRONEGAME_API UOffsetSpringArm : public USpringArmComponent
{
	GENERATED_BODY()
	
public:
	UOffsetSpringArm();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	FRotator cameraOffset;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;
	
};
