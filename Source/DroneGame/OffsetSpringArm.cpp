// Fill out your copyright notice in the Description page of Project Settings.

#include "DroneGame.h"
#include "OffsetSpringArm.h"

UOffsetSpringArm::UOffsetSpringArm() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UOffsetSpringArm::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//AddLocalRotation(FRotator(90.0f, 90.0f, 90.0f));
	AActor* rootActor = GetAttachmentRootActor();
	if (rootActor) {
		UE_LOG(LogTemp, Warning, TEXT("Camera Update"));
		SetRelativeRotation(((APawn*)rootActor)->GetViewRotation() + cameraOffset);
	}
}



