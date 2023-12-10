// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/Array.h"
#include "Deck.generated.h"

class ACard;
class AGamer;

UCLASS()
class REMOTEGAMBLE_API ADeck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeck();

	// Mesh
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 덱 위에 카드 올리는 높이
	FVector Offset;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
	TArray<ACard*> Cards;

	int32 CardCount();
	void Shuffle();
	void Draw();
	void Split(TArray<AGamer*> Gamers, int32 Count);
	void Divide(TArray<AGamer*> Gamers);
	void AddCard(ACard* Card);
	void ChangeHeight();
};
