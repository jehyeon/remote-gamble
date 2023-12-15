// Fill out your copyright notice in the Description page of Project Settings.


#include "Chip.h"

// Sets default values
AChip::AChip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Mesh 설정
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetMobility(EComponentMobility::Movable);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AChip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChip::Invert()
{
	FRotator CurrentRotation = GetActorRotation();
	SetActorRotation(FRotator((CurrentRotation.Pitch + 180.f) / 360.f, CurrentRotation.Yaw, 0.f));
}
