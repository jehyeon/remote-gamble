// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Gamer.generated.h"

UCLASS()
class REMOTEGAMBLE_API AGamer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGamer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION()
	void LookUp(float AxisValue);

	UFUNCTION()
	void Turn(float AxisValue);

	UFUNCTION()
	void MoveForward(float AxisValue);

	UFUNCTION()
	void MoveRight(float AxisValue);

	UFUNCTION()
	void UpDown(float AxisValue);

	UFUNCTION()
	void OnPressMouseRight();

	UFUNCTION()
	void OnReleaseMouseRight();

private:
	UPROPERTY(VisibleAnywhere)
	bool isPressedMouseRight;
};
