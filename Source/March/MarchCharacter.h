// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MarchCharacter.generated.h"

class UJoustingComponent;

UCLASS(config=Game)
class AMarchCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	// Motorcycle
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Motorcycle, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MotorcycleMeshComponent;

	// Jousting
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Jousting, meta = (AllowPrivateAccess = "true"))
	UJoustingComponent* JoustingComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Jousting, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* LanceMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Jousting, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ShieldMeshComponent;
	//
	
public:
	AMarchCharacter();
	void SetDefaultConstructorVariables();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	FVector StartForwardVector;
	FVector StartRightVector;

protected:

	
	void BeginPlay() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);
	
	void TurnAtRate(float Rate);
	
	void LookUpAtRate(float Rate);
	
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

