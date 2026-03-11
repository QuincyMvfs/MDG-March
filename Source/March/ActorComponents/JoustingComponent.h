// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "JoustingComponent.generated.h"

class UCameraComponent;
class AMarchController;

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

	// Functions used for the jousting minigame
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, Category="Jousting")
	void StartJousting();

	void DragCameraDown(float DeltaTime) const;

	UFUNCTION(BlueprintCallable, Category="Jousting")
	void StopJousting();
	//

	// Editor Tweak-able Variables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Jousting")
	float JoustingGravity = 2.0f;
	//
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(HideInDetailPanel), Category="Jousting")
	bool IsJousting = false;

	// Referenced Variables
	UPROPERTY(EditAnywhere, meta=(HideInDetailPanel), Category="Jousting")
	AMarchController* JoustingController = nullptr;

	UPROPERTY(EditAnywhere, meta=(HideInDetailPanel), Category="Jousting")
	UCameraComponent* JoustingCamera = nullptr;
	
	UPROPERTY(EditAnywhere, meta=(HideInDetailPanel), Category="Jousting")
	UStaticMeshComponent* JoustingMesh = nullptr;
};
