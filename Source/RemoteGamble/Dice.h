// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Movable.h"
#include "Rollable.h"
#include "Dice.generated.h"

UCLASS()
class REMOTEGAMBLE_API ADice : public AActor,
public IMovable, public IRollable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADice();

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
