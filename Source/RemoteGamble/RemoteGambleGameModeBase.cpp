// Copyright Epic Games, Inc. All Rights Reserved.


#include "RemoteGambleGameModeBase.h"
#include "Gamer.h"

ARemoteGambleGameModeBase::ARemoteGambleGameModeBase()
{
	static ConstructorHelpers::FClassFinder<AGamer> PlayerPawnClassFinder(TEXT("Blueprint'/Game/BP_Gamer.BP_Gamer_C'"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}

void ARemoteGambleGameModeBase::BeginPlay()
{
	//UE_LOG(LogTemp, Warning, TEXT("Start"));
}
