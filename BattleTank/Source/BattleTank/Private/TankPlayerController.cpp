// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();;
	if (ControlledTank) {
		 UE_LOG(LogTemp, Warning, TEXT("Possesing: %s"),*(ControlledTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player controller not possesing tank"));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }
	FVector HitLocation;//Out parameter.

	if (GetSightRayHitLocation(HitLocation)) {//Has a side-effect, its going to line trace
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
			
			//if it hits something
				//Tell the controlled tank to aim at this point.
	}
}

//Get world location if linetrace trough the crosshair, true if hits the LandScape.
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const {
	
	//Find the crosshair position in pixel cordinates.
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D((ViewportSizeX*CrossHairXLocation), (ViewportSizeY*CrossHairYLocation));
	//"De-project" the screen position of the crosshair to a world direction.
	FVector CameraRotation;
	if (GetLookDirection(ScreenLocation, CameraRotation)) {
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *CameraRotation.ToString());
	};
	
	//Line trace  along that direction, and see what we hit(up to max range).
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const {
	FVector CameraLocation; //To be discarted
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraLocation, 
		LookDirection
	);
}
