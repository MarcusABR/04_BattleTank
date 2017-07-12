// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	
	bool GetSightRayHitLocation( FVector &OutHitLocation) const;

	//Starts the barrel movement so that a shot would hit it where the world intersect the crosshair.

	void AimTowardsCrosshair();
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;


	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;
};
