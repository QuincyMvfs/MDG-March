// Copyright Epic Games, Inc. All Rights Reserved.

#include "MarchCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "MarchController.h"
#include "ActorComponents/JoustingComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// AMarchCharacter

AMarchCharacter::AMarchCharacter()
{
	SetDefaultConstructorVariables();

	MotorcycleMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Motorcycle");
	MotorcycleMeshComponent->SetupAttachment(GetRootComponent());
	
	LanceMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Lance");
	LanceMeshComponent->SetupAttachment(GetMesh());
	ShieldMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Shield");
	ShieldMeshComponent->SetupAttachment(GetMesh());

	JoustingComponent = CreateDefaultSubobject<UJoustingComponent>("JoustingComponent");
	JoustingComponent->JoustingMesh = LanceMeshComponent;
	JoustingComponent->JoustingCamera = GetFollowCamera();

}

//////////////////////////////////////////////////////////////////////////
// Input
void AMarchCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	// PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	// PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMarchCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMarchCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMarchCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMarchCharacter::LookUpAtRate);

	// // handle touch devices
	// PlayerInputComponent->BindTouch(IE_Pressed, this, &AMarchCharacter::TouchStarted);
	// PlayerInputComponent->BindTouch(IE_Released, this, &AMarchCharacter::TouchStopped);
}

void AMarchCharacter::SetDefaultConstructorVariables()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AMarchCharacter::BeginPlay()
{
	Super::BeginPlay();

	//AMarchController* Controller = Cast<AMarchController>(GetController());
	JoustingComponent->JoustingController = Cast<AMarchController>(GetController());
	
	StartForwardVector = GetRootComponent()->GetForwardVector();
	StartRightVector = GetRootComponent()->GetRightVector();
}

void AMarchCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMarchCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMarchCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		AddMovementInput(StartForwardVector, Value);
	}
}

void AMarchCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		AddMovementInput(StartRightVector, Value * 0.5f);
	}
}
