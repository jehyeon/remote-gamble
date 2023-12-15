// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turnable.h"
#include "Rollable.h"
#include "Movable.h"
#include "GameFramework/Actor.h"
#include "Chip.generated.h"

UCLASS()
class REMOTEGAMBLE_API AChip : public AActor, public IMovable, public ITurnable,
public IRollable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Mesh;

	UFUNCTION()
	void Invert();
};
