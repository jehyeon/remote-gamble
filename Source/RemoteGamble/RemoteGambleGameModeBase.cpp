// Copyright Epic Games, Inc. All Rights Reserved.


#include "RemoteGambleGameModeBase.h"
#include "GamerController.h"
#include "Gamer.h"

ARemoteGambleGameModeBase::ARemoteGambleGameModeBase()
{
	static ConstructorHelpers::FClassFinder<AGamer> PlayerPawnClassFinder(TEXT("Blueprint'/Game/Blueprints/BP_Gamer.BP_Gamer_C'"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	PlayerControllerClass = AGamerController::StaticClass();
}

void ARemoteGambleGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}
