// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "OtherPlayerCharacter.h"
#include "OtherPlayerController.h"
#include "Util.h"

const TCHAR *AOtherPlayerCharacter::AssetPath = TEXT("/Game/Blueprints/System/Active/OtherPlayerCharacter.OtherPlayerCharacter");

// Spawn
AOtherPlayerCharacter *AOtherPlayerCharacter::Spawn(UWorld *pWorld, const FVector &Position, const FRotator &Rotation, int32 Hp, int32 MaxHp)
{
	auto pCharacter = Util::SpawnFromBlueprint<AOtherPlayerCharacter>(pWorld, AssetPath, Position, Rotation);
	pCharacter->Initialize(Hp, MaxHp);

	return pCharacter;
}

// コンストラクタ
AOtherPlayerCharacter::AOtherPlayerCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
	AIControllerClass = AOtherPlayerController::StaticClass();
}

// 開始時の処理.
void AOtherPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// ↓コントローラを生成するにはコイツを呼び出す必要があるらしい。
	SpawnDefaultController();
}

// コントローラと紐付けられた。
void AOtherPlayerCharacter::PossessedBy(AController *NewController)
{
	Super::PossessedBy(NewController);

	pController = Cast<AOtherPlayerController>(NewController);
	check(pController != nullptr);
}

// 移動.
void AOtherPlayerCharacter::Move(float X, float Y, float Rotation)
{
	pController->Move(X, Y, Rotation);
}

// 移動ベクトルの取得.
FVector AOtherPlayerCharacter::GetMoveVector() const
{
	if (pController == nullptr) { return FVector::ZeroVector; }
	return pController->GetMoveVector();
}
