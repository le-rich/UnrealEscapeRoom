// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

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

<<<<<<< HEAD
=======
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UDoor::OpenDoor()
{
>>>>>>> ad91499... Cleaned up repo, learned about top to bottom inheritance
	AActor * Owner = GetOwner();

	FRotator NewRotation = FRotator(0.f, 70.0f, 0.f);

	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

