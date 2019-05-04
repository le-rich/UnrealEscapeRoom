// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Door.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPE_API UDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor();
	void CloseDoor();

private:
	UPROPERTY(VisibleAnywhere)
	float OpenAngle = 70.0f;
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;
	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.0f;
	float LastDoorOpenTime;
	AActor* ActorThatOpens;
	AActor* Owner;
};
