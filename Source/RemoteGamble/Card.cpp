// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include "Insights/ViewModels/BaseTimingTrack.h"

// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("/Game/Mesh/SM_Card.SM_Card"));
	if (SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}

	// Physics & Collision 설정
	Mesh->SetMobility(EComponentMobility::Movable);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACard::InitInDeck(FString Name)
{
	// Name 설정
	CardName = Name;

	// Material 설정
	FString FrontMaterialName = TEXT("/Game/Textures/Cards/Mat_") + CardName + TEXT(".Mat_") + CardName;
	FString BackMaterialName = TEXT("/Game/Textures/Cards/Mat_card_back.Mat_card_back");
	UMaterial* FrontMaterial = LoadObject<UMaterial>(nullptr, *FrontMaterialName);
	UMaterial* BackMaterial = LoadObject<UMaterial>(nullptr, *BackMaterialName);

	if (FrontMaterial && BackMaterial)
	{
		Mesh->SetMaterial(1, FrontMaterial);
		Mesh->SetMaterial(2, BackMaterial);
	}

	// Deck에서 소환되었을 때엔 안 보이게 설정
	this->SetVisibility(false);
}

void ACard::Open()
{
	bIsOpen = true;
	FRotator CurrentRotation = GetActorRotation();
	SetActorRotation(FRotator(0.f, CurrentRotation.Yaw, 0.f));
}

void ACard::Hide()
{
	bIsOpen = false;
	FRotator CurrentRotation = GetActorRotation();
	SetActorRotation(FRotator(180.f, CurrentRotation.Yaw, 0.f));
}

void ACard::Invert()
{
	bIsOpen = !bIsOpen;
	FRotator CurrentRotation = GetActorRotation();
	if (bIsOpen)
		SetActorRotation(FRotator(0.f, CurrentRotation.Yaw, 0.f));
	else
		SetActorRotation(FRotator(180.f, CurrentRotation.Yaw, 0.f));
}

void ACard::SetVisibility(bool IsVisible)
{
	SetActorHiddenInGame(!IsVisible);
	SetActorEnableCollision(IsVisible);
	SetActorTickEnabled(IsVisible);
	Mesh->SetSimulatePhysics(IsVisible);

	// 속도 0으로 강제 조정
	if (IsVisible)
		Mesh->SetPhysicsLinearVelocity(FVector::ZeroVector);
}

