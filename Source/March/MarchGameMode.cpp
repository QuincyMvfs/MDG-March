// Copyright Epic Games, Inc. All Rights Reserved.

#include "MarchGameMode.h"
#include "MarchCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMarchGameMode::AMarchGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
