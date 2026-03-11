// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MarchController.generated.h"

/**
 * 
 */
UCLASS()
class MARCH_API AMarchController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Camera)
	FVector2D ViewPitchMinMax = FVector2D(-60.0f, 20.0f);
	FVector2D ViewYawMinMax = FVector2D(-60.0f, 60.0f);
};
