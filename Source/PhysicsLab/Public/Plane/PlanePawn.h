// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlanePawn.generated.h"

UCLASS()
class PHYSICSLAB_API APlanePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlanePawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MainBody;

	UPROPERTY(VisibleAnywhere)
	class	UPawnMovementComponent* PawnMovementComponent;

private:	

	UFUNCTION()
	void MoveForward(float Value);

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	FVector Directiontemp;

	float AxisValue;

};
