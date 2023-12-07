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
}

// Called when the game starts or when spawned
void ADeck::BeginPlay()
{
	Super::BeginPlay();
	FGenericPlatformMath::SRandInit(time(0));
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

void ADeck::Shuffle() 
{
	for (int32 i = 0; i < Cards.Num(); i++) 
	{
		int32 newIndex = FMath::FMath::Floor(FMath::RandRange(0, i + 1)) % Cards.Num();
		ACard* temp = Cards[i];
		Cards[i] = Cards[newIndex];
		Cards[newIndex] = temp;
	}
}

ACard* ADeck::Draw()
{
	if (Cards.Num() > 0)
	{
		ACard* ret = Cards[0];
		Cards.RemoveAt(0);
		return ret;
	}

	return nullptr;
}

void ADeck::Split(TArray<AGamer*> Gamers, int32 Count)
{
	for (int32 i = 0; i < Count; i++) 
	{
		Divide(Gamers);
	}
}

void ADeck::Divide(TArray<AGamer*> Gamers)
{
	// TODO
}