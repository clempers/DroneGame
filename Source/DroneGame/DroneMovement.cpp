// Fill out your copyright notice in the Description page of Project Settings.

#include "DroneGame.h"
#include "DroneMovement.h"



void UDroneMovement::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Make sure that everything is still valid, and that we are allowed to move.
	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{
		return;
	}
	
	float speed = 1500.0f;

	// Get (and then clear) the movement vector that we set in ACollidingPawn::Tick
	FVector inputVector = ConsumeInputVector();
	FVector DesiredMovementThisFrame = inputVector.Size() < DeltaTime * speed ? inputVector : inputVector.GetClampedToMaxSize(1.0f) * DeltaTime * speed;
	if (!DesiredMovementThisFrame.IsZero())
	{
		FHitResult Hit;
		SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

		// If we bumped into something, try to slide along it
		if (Hit.IsValidBlockingHit())
		{
			SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
		}
	}
};
