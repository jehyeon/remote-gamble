// Fill out your copyright notice in the Description page of Project Settings.

#include "Deck.h"
#include "Card.h"
#include "Gamer.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ADeck::ADeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Mesh 설정
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("/Game/Mesh/SM_Deck.SM_Deck"));
	if (SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}

	Offset = FVector(0.f, 0.f, 5.f);

	// Physics & Collision 설정
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ADeck::BeginPlay()
{
	Super::BeginPlay();
	FGenericPlatformMath::SRandInit(time(0));

	this->CreateCards();
	this->Shuffle();
	bIsOpen = false;
}

// Called every frame
void ADeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 ADeck::CardCount()
{
	return Cards.Num();
}

void ADeck::CreateCards()
{
	// 53장 카드 생성(Joker 1장)
	TArray<FString> CardShapeNames = { TEXT("spade"), TEXT("diamond"), TEXT("heart"), TEXT("club") };
	for (int32 i = 0; i < CardShapeNames.Num(); i++)
	{
		FString ShapeName = CardShapeNames[i];
		for (int32 j = 1; j <= 13; j++)
		{
			// 카드 이름 설정
			FString CardName = ShapeName + TEXT("_");
			switch (j)
			{
			case 1:
				CardName += TEXT("a");
				break;
			case 11:
				CardName += TEXT("jack");
				break;
			case 12:
				CardName += TEXT("queen");
				break;
			case 13:
				CardName += TEXT("king");
				break;
			default:
				CardName += FString::FromInt(j);
				break;
			}

			// 카드 생성 후 Cards 에 넣어주기
			ACard* NewCard = GetWorld()->SpawnActor<ACard>(ACard::StaticClass(), this->GetActorLocation(), FRotator::ZeroRotator);
			NewCard->InitInDeck(CardName);
			Cards.Emplace(NewCard);
		}
	}

	// 조커 카드 따로 넣어주기
	ACard* JokerCard = GetWorld()->SpawnActor<ACard>(ACard::StaticClass(), this->GetActorLocation(), FRotator::ZeroRotator);
	JokerCard->InitInDeck(TEXT("joker"));
	Cards.Emplace(JokerCard);
}

void ADeck::SetBackMaterial()
{
	FString CardName = Cards[this->CardCount() - 1]->CardName;
	FString MaterialName = TEXT("/Game/Textures/Cards/Mat_") + CardName + TEXT(".Mat_") + CardName;
	UMaterial* Material = LoadObject<UMaterial>(nullptr, *MaterialName);
	if (Material)
	{
		Mesh->SetMaterial(2, Material);
	}
}

void ADeck::Shuffle() 
{
	for (int32 i = 0; i < this->CardCount(); i++) 
	{
		int32 newIndex = FMath::FMath::Floor(FMath::RandRange(0, i + 1)) % Cards.Num();
		ACard* temp = Cards[i];
		Cards[i] = Cards[newIndex];
		Cards[newIndex] = temp;
	}

	this->SetBackMaterial();
	//UE_LOG(LogTemp, Warning, TEXT("Shuffled : Top Card is now %s."), *Cards[0]->CardName);
}

void ADeck::Draw()
{
	// Card 지정 후 List에서 제거
	if (this->CardCount() > 0)
	{
		int32 CardIndex;
		if (bIsOpen)
			CardIndex = this->CardCount() - 1;
		else
			CardIndex = 0;
		ACard* Card = Cards[CardIndex];
		Cards.RemoveAt(CardIndex);

		// 카드 위치 설정
		FVector CardLocation = this->GetActorLocation() + Offset;
		Card->SetActorLocation(CardLocation);
		Card->SetActorRotation(this->GetActorRotation());
		Card->SetVisibility(true);

		// 카드 Open 여부 설정
		if (bIsOpen)
			Card->Open();
		else
			Card->Hide();

		// Deck의 높이 변경
		ChangeHeight();

		//UE_LOG(LogTemp, Warning, TEXT("%f, %s"), CardLocation.Z, *Card->GetName());

		SetBackMaterial();

		// 남은 카드가 0개였다면 Deck 제거
		if (this->CardCount() == 0)
			this->Destroy();
	}

	//UE_LOG(LogTemp, Warning, TEXT("%d"), this->CardCount());
}

void ADeck::Split(TArray<AGamer*> Gamers, int32 Count)
{
	for (int32 i = 0; i < this->CardCount(); i++) 
	{
		Divide(Gamers);
	}
}

void ADeck::Divide(TArray<AGamer*> Gamers)
{
	for (int32 i = 0; i < this->CardCount(); i++) 
	{
		Draw();
		// TODO : 각 위치의 플레이어 앞으로 카드 Location 이동시키기
	}
}

void ADeck::AddCard(ACard* Card)
{
	Cards.Emplace(Card);

	// Deck의 높이 변경
	ChangeHeight();
}

void ADeck::ChangeHeight()
{
	FVector NewScale = FVector(1.f, 1.f, this->CardCount() / 53.f);
	SetActorScale3D(NewScale);
}

void ADeck::Invert()
{
	bIsOpen = !bIsOpen;

	FRotator CurrentRotation = GetActorRotation();
	if (bIsOpen)
	{
		SetActorRotation(FRotator(180.f, CurrentRotation.Yaw, 0.f));
	}
	else
	{
		SetActorRotation(FRotator(0.f, CurrentRotation.Yaw, 0.f));
	}
}