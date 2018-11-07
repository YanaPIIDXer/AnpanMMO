// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "OtherPlayerCharacter.h"
#include "OtherPlayerController.h"

// Spawn
AOtherPlayerCharacter *AOtherPlayerCharacter::Spawn(UWorld *pWorld, const FVector &Position, const FRotator &Rotation)
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	auto *pCharacter = pWorld->SpawnActor<AOtherPlayerCharacter>(Position, Rotation, Param);

	return pCharacter;
}

// コンストラクタ
AOtherPlayerCharacter::AOtherPlayerCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
	AIControllerClass = AOtherPlayerController::StaticClass();
}
