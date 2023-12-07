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

	UPROPERTY(EditAnywhere, Category = "Info")
	FString CardName; // 모양_넘버 ex) spade_jack, heart_6

	// 카드 앞면(모양, 숫자)이 보이는 상태인지 <- 필요없으면 지우기
	UPROPERTY(EditAnywhere, Category = "Info")
	bool IsOpen;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Open();
	void Hide();
};
