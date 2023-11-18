// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamer.h"

// Sets default values
AGamer::AGamer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	isPressedMouseRight = false;
}

// Called when the game starts or when spawned
void AGamer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGamer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGamer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("RotateView", IE_Pressed, this, &AGamer::OnPressMouseRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AGamer::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AGamer::LookUp);
	PlayerInputComponent->BindAxis("MoveForward", this, &AGamer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGamer::MoveRight);
}

void AGamer::LookUp(float AxisValue)
{
}

void AGamer::Turn(float AxisValue)
{
}

void AGamer::MoveForward(float AxisValue)
{
}

void AGamer::MoveRight(float AxisValue)
{
}

void AGamer::OnPressMouseRight()
{
	UE_LOG(LogTemp, Log, TEXT("Pressed"));
}

