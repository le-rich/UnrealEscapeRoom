// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"

// Sets default values for this component's properties
UDoor::UDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
}

void UDoor::OpenDoor()
{
	FRotator NewRotation = FRotator(0.f, OpenAngle, 0.f);

	Owner->SetActorRotation(NewRotation);
}

void UDoor::CloseDoor()
{
	FRotator NewRotation = FRotator(0.f, 0.f, 0.f);

	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (GetTotalMassOfActorsOnPlate() > massThreshold) {
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	
	//Check if it's time to close the door.
	if (GetWorld()->GetTimeSeconds() > (LastDoorOpenTime + DoorCloseDelay)) {
		CloseDoor();
	}
}

float UDoor::GetTotalMassOfActorsOnPlate() {
	TArray<AActor*> onPlate;
	PressurePlate->GetOverlappingActors(OUT onPlate);
	
	float rsf = 0;
	for (const auto& Actor : onPlate) {
		rsf += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
	}

	return rsf;
}