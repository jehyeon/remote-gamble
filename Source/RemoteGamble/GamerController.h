// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamerController.generated.h"

//class AGamer;
/**
 * 
 */
UCLASS()
class REMOTEGAMBLE_API AGamerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AGamerController();

	//virtual void OnPossess(APawn* InPawn) override;
	//virtual void OnUnPossess() override;

protected:
	//AGamer* Gamer;

	bool bPressedLeft;
	bool bPressedRight;
	bool bIsMovingObject;

	AActor* TargetActor;
	FVector MovingActorOffset;

public:
	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;

	UFUNCTION()
	void OnPressMouseLeft();

	UFUNCTION()
	void OnReleaseMouseLeft();

	UFUNCTION()
	void OnPressMouseRight();

	UFUNCTION()
	void OnReleaseMouseRight();

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
	void MoveObject(AActor* Target, const FVector Destination);

	UFUNCTION()
	void Roll();

	UFUNCTION()
	void Shuffle();

	UFUNCTION()
	void Draw();

	UFUNCTION()
	void OpenOrHideCard();

	// 마우스 현재 위치
	void MoveToMouseCursor();
};
