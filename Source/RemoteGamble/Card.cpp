// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"

// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	UStaticMeshComponent* FirstPlaneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FirstPlaneMesh"));
	UStaticMeshComponent* SecondPlaneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondPlaneMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM1(TEXT("StaticMesh'/Engine/BasicShapes/Plane.Plane'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM2(TEXT("StaticMesh'/Engine/BasicShapes/Plane.Plane'"));
	if (SM1.Succeeded() && SM2.Succeeded())
	{
		FirstPlaneMesh->SetStaticMesh(SM1.Object);
		SecondPlaneMesh->SetStaticMesh(SM2.Object);

		FirstPlaneMesh->SetupAttachment(RootComponent);
		SecondPlaneMesh->SetupAttachment(RootComponent);

		// FString MaterialName = TEXT("/Game/Textures/") + CardName + TEXT(".") + CardName;
		// UMaterial* FrontMaterial = LoadObject<UMaterial>(nullptr, *MaterialName);
		// TODO : 카드 뒷면 텍스쳐 구해서 바꿔주기
		UMaterial* FrontMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Game/Textures/Mat_dice_01.Mat_dice_01")); 
		UMaterial* BackMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Game/Textures/Mat_dice_02.Mat_dice_02")); 

		FirstPlaneMesh->SetMaterial(0, FrontMaterial);
		SecondPlaneMesh->SetMaterial(0, BackMaterial);

		FRotator Rotation = FRotator(-180.f, 0.f, 0.f);
		SecondPlaneMesh->SetRelativeRotation(Rotation);
	}
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
