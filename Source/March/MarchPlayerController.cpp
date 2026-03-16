// Copyright Epic Games, Inc. All Rights Reserved.


#include "MarchPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"

AMarchPlayerController::AMarchPlayerController()
{
	// PlayerCameraManager->ViewPitchMin = M_ViewPitch.X;
	// PlayerCameraManager->ViewPitchMax = M_ViewPitch.Y;
	//
	// PlayerCameraManager->ViewYawMin = M_ViewYaw.X;
	// PlayerCameraManager->ViewYawMax = M_ViewYaw.Y;
}

void AMarchPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerCameraManager->ViewPitchMin = M_ViewPitch.X;
	PlayerCameraManager->ViewPitchMax = M_ViewPitch.Y;
	
	PlayerCameraManager->ViewYawMin = M_ViewYaw.X;
	PlayerCameraManager->ViewYawMax = M_ViewYaw.Y;
}

void AMarchPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}
		}
	}
}