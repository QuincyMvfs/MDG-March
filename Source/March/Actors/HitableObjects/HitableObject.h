#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HitableInterface.h"
#include "HitableObject.generated.h"

UCLASS()
class MARCH_API AHitableObject : public AActor, public IHitableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHitableObject();
	
	UFUNCTION(BlueprintCallable)
	virtual void OnHit_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:	
};
