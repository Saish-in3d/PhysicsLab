// Copyright Epic Games, Inc. All Rights Reserved.

#include "PhysicsLabGameMode.h"
#include "PhysicsLabCharacter.h"
#include "Plane/PlanePawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Plane/PlaneController.h"

APhysicsLabGameMode::APhysicsLabGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_Plane"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = APlaneController::StaticClass();
}



//Blueprint'/Game/ThirdPerson/Blueprints/Plane.Plane'
///Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter
//Blueprint'/Game/ThirdPerson/Blueprints/BP_Plane.BP_Plane'