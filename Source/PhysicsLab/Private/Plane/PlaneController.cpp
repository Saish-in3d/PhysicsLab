// Fill out your copyright notice in the Description page of Project Settings.


#include "Plane/PlaneController.h"
#include "Plane/PlanePawn.h"
#include "Kismet/GameplayStatics.h" 

void APlaneController::BeginPlay()
{
	Super::BeginPlay();

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlanePawn::StaticClass(), FoundActors);

    // Iterate through the array of found actors
    for (AActor* Actor : FoundActors)
    {
        PlanePawn = Cast<APlanePawn>(Actor);
        if (PlanePawn)
        {
            UE_LOG(LogTemp, Warning, TEXT("pOSSESSED"));
            Possess(PlanePawn);
        }
    }

}
