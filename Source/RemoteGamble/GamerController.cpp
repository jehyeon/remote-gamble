// Fill out your copyright notice in the Description page of Project Settings.


#include "GamerController.h"
#include "Movable.h"
#include "Rollable.h"
//#include "Gamer.h"

AGamerController::AGamerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;

	bPressedLeft = false;
	bPressedRight = false;
	bIsMovingObject = false;

	TargetActor = nullptr;
	MovingActorOffset = FVector(0.f, 0.f, 100.f);	// temp
}

//void AGamerController::OnPossess(APawn* InPawn)
//{
//	Super::Possess(InPawn);
//	if (GetPawn() != nullptr)
//	{
//		Gamer = Cast<AGamer>(GetPawn());
//	}
//}
//
//void AGamerController::OnUnPossess()
//{
//	Super::OnUnPossess();
//
//	Gamer = nullptr;
//}

void AGamerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftClick", IE_Pressed, this, &AGamerController::OnPressMouseLeft);
	InputComponent->BindAction("LeftClick", IE_Released, this, &AGamerController::OnReleaseMouseLeft);
	InputComponent->BindAction("RotateView", IE_Pressed, this, &AGamerController::OnPressMouseRight);
	InputComponent->BindAction("RotateView", IE_Released, this, &AGamerController::OnReleaseMouseRight);

	InputComponent->BindAxis("LookUp", this, &AGamerController::LookUp);
	InputComponent->BindAxis("Turn", this, &AGamerController::Turn);
	InputComponent->BindAxis("MoveForward", this, &AGamerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AGamerController::MoveRight);
	InputComponent->BindAxis("UpDown", this, &AGamerController::UpDown);

	InputComponent->BindAction("Roll", IE_Pressed, this, &AGamerController::Roll);
}

void AGamerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	MoveToMouseCursor();
}

void AGamerController::OnPressMouseLeft()
{
	bPressedLeft = true;
}

void AGamerController::OnReleaseMouseLeft()
{
	bPressedLeft = false;
}

void AGamerController::OnPressMouseRight()
{
	bPressedRight = true;
}

void AGamerController::OnReleaseMouseRight()
{
	bPressedRight = false;
	bIsMovingObject = false;
	TargetActor = nullptr;
}

void AGamerController::LookUp(float AxisValue)
{
	//if (!Gamer)
	//{
	//	return;
	//}

	if (bPressedRight)
	{
		//Gamer->AddControllerPitchInput(AxisValue);
		GetPawn()->AddControllerPitchInput(AxisValue);
	}
}

void AGamerController::Turn(float AxisValue)
{
	//if (!Gamer)
	//{
	//	return;
	//}

	if (bPressedRight)
	{
		//Gamer->AddControllerYawInput(AxisValue);
		GetPawn()->AddControllerYawInput(AxisValue);
	}
}

void AGamerController::MoveForward(float AxisValue)
{
	//if (!Gamer)
	//{
	//	return;
	//}

	//Gamer->AddMovementInput(Gamer->GetActorForwardVector(), AxisValue);
	GetPawn()->AddMovementInput(GetPawn()->GetActorForwardVector(), AxisValue);
}

void AGamerController::MoveRight(float AxisValue)
{
	//if (!Gamer)
	//{
	//	return;
	//}

	//Gamer->AddMovementInput(Gamer->GetActorRightVector(), AxisValue);
	GetPawn()->AddMovementInput(GetPawn()->GetActorRightVector(), AxisValue);
}

void AGamerController::UpDown(float AxisValue)
{
	//if (!Gamer)
	//{
	//	return;
	//}

	//Gamer->AddMovementInput(Gamer->GetActorUpVector(), AxisValue);
	GetPawn()->AddMovementInput(GetPawn()->GetActorUpVector(), AxisValue);
}

void AGamerController::MoveObject(AActor* Target, const FVector Destination)
{
}

void AGamerController::Roll()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		UClass* ActorClass = Hit.Actor->GetClass();
		if (ActorClass->ImplementsInterface(URollable::StaticClass()))
		{
			UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>(Hit.GetComponent());
			if (IsValid(StaticMesh))
			{
				const float pitch = FMath::FRandRange(-180.f, 180.f);
				const float yaw = FMath::FRandRange(-180.f, 180.f);
				const float roll = FMath::FRandRange(-180.f, 180.f);

				StaticMesh->SetWorldRotation(FRotator(pitch, yaw, roll));
				StaticMesh->AddForce(FVector(0.f, 0.f, 1.f) * 50000 * StaticMesh->GetMass());
			}
		}
	}
}

void AGamerController::MoveToMouseCursor()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		UClass* ActorClass = Hit.Actor->GetClass();
		
		// Left Click 중인 경우
		if (bPressedLeft)
		{
			// 움직이고 있는 Actor가 없는 경우
			if (!bIsMovingObject)
			{
				// Movable Actor일 때 Target Actor 새로 등록
				if (ActorClass->ImplementsInterface(UMovable::StaticClass()))
				{
					bIsMovingObject = true;
					TargetActor = Hit.GetActor();

					//FVector TargetLocation = TargetActor->GetActorLocation();
					//TargetActor->SetActorLocation(TargetLocation + MovingActorOffset);
				}
			}
			// 움직이고 있는 Actor가 있는 경우
			else if (bIsMovingObject && TargetActor)
			{
				if (Hit.GetActor() != TargetActor)
				{
					TargetActor->SetActorLocation(Hit.Location + MovingActorOffset);
				}
			}
		}
		else
		{
			bIsMovingObject = false;
			TargetActor = nullptr;
		}
	}
}
