// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JoustingComponent.generated.h"


class USphereComponent;
class UCameraComponent;
class AMarchPlayerController;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MARCH_API UJoustingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UJoustingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category="Jousting")
	void StartJousting();

	void DragCameraDown(float DeltaTime) const;

	UFUNCTION(BlueprintCallable, Category="Jousting")
	void StopJousting();
	//

	// Editor Tweak-able Variables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Jousting", meta = (ToolTip = "How fast the Lance lowers"))
	float JoustingGravity = 2.0f;
	//
	
	UPROPERTY()
	bool IsJousting = false;
	
	// Referenced Variables
	UPROPERTY(EditAnywhere, Category="Jousting|Referenced")
	AMarchPlayerController* JoustingController = nullptr;

	UPROPERTY(EditAnywhere, Category="Jousting|Referenced")
	UCameraComponent* JoustingCamera = nullptr;
	
	UPROPERTY()
	USceneComponent* JoustingRoot = nullptr;
	
	UPROPERTY()
	USphereComponent* JoustingCollider = nullptr;
	
	UFUNCTION(BlueprintCallable, Category="Jousting|Referenced")
	void SetJoustingReferences(USceneComponent* Root, USphereComponent* Collider);
	
	UFUNCTION()
	void OnSphereOverlapBegin( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
