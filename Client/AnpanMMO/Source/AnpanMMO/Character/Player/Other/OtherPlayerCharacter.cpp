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

	// 足元の座標が送られてくるので中心の座標に変換.
	FVector OffsetPos = Position;
	OffsetPos.Z += pCharacter->GetHalfHeight();
	pCharacter->SetActorLocation(OffsetPos);

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
void AOtherPlayerCharacter::Move(float X, float Y, float Z, float Rotation)
{
	Z += GetHalfHeight();		// 足元の座標から中心の座標に変換.
	pController->Move(X, Y, Z, Rotation);
}

// 移動ベクトルの取得.
FVector AOtherPlayerCharacter::GetMoveVector() const
{
	if (pController == nullptr) { return FVector::ZeroVector; }
	return pController->GetMoveVector();
}
