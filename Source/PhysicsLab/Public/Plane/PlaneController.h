// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlaneController.generated.h"

/**
 * 
 */
UCLASS()
class APlaneController : public APlayerController
{
	GENERATED_BODY()


protected:
	virtual void BeginPlay() override;



private:

	class APlanePawn* PlanePawn;

	
};
