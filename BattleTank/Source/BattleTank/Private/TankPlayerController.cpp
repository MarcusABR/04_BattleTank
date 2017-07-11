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
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
			
			//if it hits something
				//Tell the controlled tank to aim at this point.
	}
}

//Get world location if linetrace trough the crosshair, true if hits the LandScape.
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const {
	OutHitLocation = FVector(1.0);
	return true;
}
