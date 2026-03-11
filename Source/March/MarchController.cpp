// Fill out your copyright notice in the Description page of Project Settings.


#include "MarchController.h"

void AMarchController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCameraManager->ViewPitchMin = ViewPitchMinMax.X;
	PlayerCameraManager->ViewPitchMax = ViewPitchMinMax.Y;
	
	PlayerCameraManager->ViewYawMin = ViewYawMinMax.X;
	PlayerCameraManager->ViewYawMax = ViewYawMinMax.Y;
}
