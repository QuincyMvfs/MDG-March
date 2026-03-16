// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MarchPlayerController.generated.h"

class UInputMappingContext;
class UUserWidget;

/**
 *  Basic PlayerController class for a third person game
 *  Manages input mappings
 */
UCLASS(abstract)
class AMarchPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	AMarchPlayerController();
	
	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category ="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;
	
public:
	UPROPERTY(EditAnywhere, Category ="View", meta = (ToolTip = "UP/DOWN - MIN/MAX"))
	FVector2D M_ViewPitch = FVector2D(-40,40);
	
	UPROPERTY(EditAnywhere, Category ="View", meta = (ToolTip = "LEFT/RIGHT - MIN/MAX"))
	FVector2D M_ViewYaw = FVector2D(-40,40);
};
