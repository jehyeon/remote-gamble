// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"

// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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

	// Material 설정
	//FString MaterialName = TEXT("/Game/Textures/Cards/Mat_") + CardName + TEXT("./Mat_") + CardName;
	FString FrontMaterialName = TEXT("/Game/Textures/Cards/Mat_heart_7.Mat_heart_7"); // 예시 코드, 위쪽 주석으로 변경 요망
	FString BackMaterialName = TEXT("/Game/Textures/Cards/Mat_card_back.Mat_card_back");
	UMaterial* FrontMaterial = LoadObject<UMaterial>(nullptr, *FrontMaterialName);
	UMaterial* BackMaterial = LoadObject<UMaterial>(nullptr, *BackMaterialName);

	Mesh->SetMaterial(1, FrontMaterial);
	Mesh->SetMaterial(2, BackMaterial);

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
