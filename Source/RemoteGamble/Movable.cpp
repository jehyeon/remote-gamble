// Fill out your copyright notice in the Description page of Project Settings.


#include "Movable.h"

// Add default functionality here for any IMovable functions that are not pure virtual.

void IMovable::OnBeginMouseOver()
{
	unimplemented();
	UE_LOG(LogTemp, Warning, TEXT("Mouse hover"));
}
