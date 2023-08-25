// Copyright Epic Games, Inc. All Rights Reserved.

#include "PhysicsLabGameMode.h"
#include "PhysicsLabCharacter.h"
#include "UObject/ConstructorHelpers.h"

APhysicsLabGameMode::APhysicsLabGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
