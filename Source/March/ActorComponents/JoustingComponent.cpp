// Fill out your copyright notice in the Description page of Project Settings.


#include "JoustingComponent.h"

#include "MarchPlayerController.h"
#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UJoustingComponent::UJoustingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UJoustingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UJoustingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsJousting)
	{
		DragCameraDown(GetWorld()->GetDeltaSeconds());
	}
}

// Enables the Function called in Tick
void UJoustingComponent::StartJousting()
{
	if (IsJousting) return;
	
	IsJousting = true;
	SetComponentTickEnabled(true);
}

void UJoustingComponent::DragCameraDown(float DeltaTime) const
{
	if (!JoustingController) return;

	// Drag Camera
	JoustingController->AddPitchInput(JoustingGravity * DeltaTime);

	// Drag Lance
	FRotator LanceRotation = JoustingCamera->GetComponentRotation();
	LanceRotation.Pitch -= 90.0f;
	JoustingMesh->SetWorldRotation(LanceRotation);
}

// Disables the function called in tick
void UJoustingComponent::StopJousting()
{
	if (!IsJousting)
	{
		if (IsComponentTickEnabled())
		{
			SetComponentTickEnabled(false);
		}
	}
	
	IsJousting = false;
	SetComponentTickEnabled(false);
}

