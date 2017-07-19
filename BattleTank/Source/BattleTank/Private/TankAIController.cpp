// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

ATank * ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{

	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto PlayerPawn = GetPlayerTank();
	auto AiTank = GetControlledTank();

	if (PlayerPawn) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found: %s"), *(PlayerPawn->GetName()))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI has not found the Player Tank."))
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto PlayerTank = GetPlayerTank();
	if (PlayerTank != nullptr) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
	
}

