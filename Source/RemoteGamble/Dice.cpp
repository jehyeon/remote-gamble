// Fill out your copyright notice in the Description page of Project Settings.


#include "Dice.h"

// Sets default values
ADice::ADice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scale = FVector(1.f);

	// Mesh 설정
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/Mesh/SM_Dice.SM_Dice'"));
	if (SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}

	Mesh->SetMobility(EComponentMobility::Movable);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	RootComponent = Mesh;

	// Collision 설정
	//CollisionComponent = CreateDefaultSubobject<UBoxComponent>("Collision");
	//CollisionComponent->SetBoxExtent(FVector(200.f, 200.f, 200.f));
	//CollisionComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADice::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ADice::CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent)
//{
//
//	UE_LOG(LogTemp, Warning, TEXT("Mouse hover"));
//	if (GEngine)
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Mouse Over"));
//	}
//}


