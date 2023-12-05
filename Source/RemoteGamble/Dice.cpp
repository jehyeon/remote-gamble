// Fill out your copyright notice in the Description page of Project Settings.


#include "Dice.h"

// Sets default values
ADice::ADice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/SM_Dice.SM_Dice'"));

	if (SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}

	//Mesh->OnBeginCursorOver.AddDynamic(this, &ADice::CustomOnBeginMouseOver);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
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


