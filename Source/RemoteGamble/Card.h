// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Movable.h"
#include "Turnable.h"
#include "Card.generated.h"

UCLASS()
class REMOTEGAMBLE_API ACard : public AActor,
public IMovable, public ITurnable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACard();

	// Mesh
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Name")
	FString CardName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
