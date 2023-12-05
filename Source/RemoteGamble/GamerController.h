// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamerController.generated.h"

/**
 * 
 */
UCLASS()
class REMOTEGAMBLE_API AGamerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AGamerController();

protected:
	bool bClickedLeft;

public:
	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;

	void OnPressMouseLeft();
	void OnReleaseMouseLeft();

	void MoveObject(AActor* Target, const FVector Destination);

	// 마우스 현재 위치
	void MoveToMouseCursor();
};
