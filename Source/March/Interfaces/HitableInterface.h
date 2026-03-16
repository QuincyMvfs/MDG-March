// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HitableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UHitableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MARCH_API IHitableInterface
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnHit();
};
