// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* AIControlledTank = GetControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("AIControllerTank Begin Play"));

	if (AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Received tank's name is %s"), *(AIControlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Nanai"));
	}

	ATank* PlayerController = GetPlayerTank();

	if (PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("I founded you %s"), *(PlayerController->GetName()));
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No T enkontre gggg"));
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!PlayerTank)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);

	//return CastedTank;
}
