// Fill out your copyright notice in the Description page of Project Settings.


#include "GamerController.h"
#include "Movable.h"

AGamerController::AGamerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
}

void AGamerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftClick", IE_Pressed, this, &AGamerController::OnPressMouseLeft);
	InputComponent->BindAction("LeftClick", IE_Released, this, &AGamerController::OnPressMouseLeft);
}

void AGamerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	MoveToMouseCursor();
}

void AGamerController::OnPressMouseLeft()
{
	bClickedLeft = true;
}

void AGamerController::OnReleaseMouseLeft()
{
	bClickedLeft = false;
}

void AGamerController::MoveObject(AActor* Target, const FVector Destination)
{
}

void AGamerController::MoveToMouseCursor()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		UClass* ActorClass = Hit.Actor->GetClass();

		if (ActorClass->ImplementsInterface(UMovable::StaticClass()))
		{
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
				TEXT("Movable Mouse Over"));

			UE_LOG(LogTemp, Warning, TEXT("Movable Mouse Over"));
		}
	}
}
