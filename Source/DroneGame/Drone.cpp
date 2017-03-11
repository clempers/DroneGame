// Fill out your copyright notice in the Description page of Project Settings.

#include "DroneGame.h"
#include "FormationController.h"
#include "DroneGameState.h"
#include "DroneMovement.h"
#include "Drone.h"


// Sets default values
ADrone::ADrone()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
	RootComponent = BoxComponent;

	BoxComponent->InitBoxExtent(FVector(50.0f, 50.0f, 20.0f));
	BoxComponent->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));
	BoxComponent->SetCollisionProfileName(TEXT("Pawn"));

	if(FormationController)
		FormationController->Possess(this);

	// Create and position a mesh component so we can see where our sphere is
	DroneVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	DroneVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> DroneVisualAsset(TEXT("/Game/Drone/Pawn/RoundDrone"));
	if (DroneVisualAsset.Succeeded())
	{
		DroneVisual->SetStaticMesh(DroneVisualAsset.Object);
		DroneVisual->SetRelativeRotation(FRotator(0.0f, 290.0f, 0.0f));
	}

	DroneMovement = CreateDefaultSubobject<UDroneMovement>(TEXT("CustomDroneMovement"));
	DroneMovement->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void ADrone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame0
void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!AddedDrone && GetWorld()->GetGameState<ADroneGameState>()->FormationController) {
		AddedDrone = true;
		GetWorld()->GetGameState<ADroneGameState>()->FormationController->PossessDrone(this);
	}
}

// Called to bind functionality to input
void ADrone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UPawnMovementComponent* ADrone::GetMovementComponent() const
{
	return DroneMovement;
}

