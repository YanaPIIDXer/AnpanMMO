// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameController.h"
#include "Engine/World.h"

// コンストラクタ
AGameController::AGameController(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCamera(nullptr)
{
}

// Pawnが紐付けられた。
void AGameController::Possess(APawn *aPawn)
{
	Super::Possess(aPawn);
	
	// カメラを生成.
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.Owner = this;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	pCamera = GetWorld()->SpawnActor<AGameCamera>(AGameCamera::StaticClass(), Param);
	SetViewTargetWithBlend(pCamera.Get());

	auto *pPlayer = Cast<AGameCharacter>(aPawn);
	check(pPlayer != nullptr);
	pCamera->SetGameCharacter(pPlayer);
}
