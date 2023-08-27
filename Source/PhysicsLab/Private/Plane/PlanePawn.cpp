// Fill out your copyright notice in the Description page of Project Settings.


#include "Plane/PlanePawn.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Plane/PlanePawnMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlanePawn::APlanePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	MainBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMeshComponent"));
	RootComponent = MainBody;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/EditorMeshes/EditorCube.EditorCube'"));
	if (MeshAsset.Succeeded())
	{
		MainBody->SetStaticMesh(MeshAsset.Object);
		MainBody->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));	
	}

	//CharacterMovementComponent = CreateDefaultSubobject<UCharacterMovementComponent>(TEXT("CharacterMovementComponent"));
	PawnMovementComponent = CreateDefaultSubobject<UPawnMovementComponent>(TEXT("PawnMovementComponent"));
	//PawnMovementComponent->UpdatedComponent = RootComponent;


	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APlanePawn::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PCTemp = Cast<APlayerController>(GetController());
	if (PCTemp)
	{
		
	}
	
}

// Called every frame
void APlanePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddMovementInput(Directiontemp, AxisValue);
}

// Called to bind functionality to input
void APlanePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &APlanePawn::MoveForward);

}

void APlanePawn::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		
		/*FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);*/



		UE_LOG(LogTemp, Warning, TEXT("Input"));
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AxisValue = Value;
		Directiontemp = Direction;
		//AddMovementInput(Direction, Value);

		/*if (PawnMovementComponent && (PawnMovementComponent->UpdatedComponent == RootComponent))
		{
			UE_LOG(LogTemp, Warning, TEXT("Input"));
			PawnMovementComponent->AddInputVector(GetActorForwardVector() * Value);
		}*/
	}

}

