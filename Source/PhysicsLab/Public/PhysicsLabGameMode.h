// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PhysicsLabGameMode.generated.h" 


UCLASS(minimalapi)
class APhysicsLabGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APhysicsLabGameMode();

private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class APlaneController> PlaneControllerClass;

	UPROPERTY(EditDefaultsOnly)
	class APlaneController* PlaneController;
};



