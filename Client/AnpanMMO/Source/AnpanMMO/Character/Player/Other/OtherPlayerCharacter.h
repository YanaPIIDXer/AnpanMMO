// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/Player/PlayerCharacterBase.h"
#include "OtherPlayerCharacter.generated.h"

class AOtherPlayerController;

/**
 * 他人のPlayerCharacter
 */
UCLASS()
class ANPANMMO_API AOtherPlayerCharacter : public APlayerCharacterBase
{

	GENERATED_BODY()
	
public:

	// Spawn
	static AOtherPlayerCharacter *Spawn(UWorld *pWorld, uint32 Uuid, const FVector &Position, const FRotator &Rotation, int32 Hp, int32 MaxHp, const FString &CharacterName, uint8 Job);

	// コンストラクタ
	AOtherPlayerCharacter(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AOtherPlayerCharacter() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// コントローラと紐付けられた。
	virtual void PossessedBy(AController *NewController) override;

	// 移動.
	virtual void Move(float X, float Y, float Z, float Rotation) override;

	// 移動ベクトルの取得.
	virtual FVector GetMoveVector() const override;

	// UUIDを取得.
	virtual uint32 GetUuid() const override { return Uuid; }

	// キャラクタ名を取得.
	virtual FString GetCharacterName() const override { return CharacterName; }

	// キャラクタタイプを取得.
	virtual ECharacterType GetCharacterType() const override { return ECharacterType::Other; }

private:

	// Blueprintのアセットパス
	static const TCHAR *AssetPath;
	
	// コントローラ
	TWeakObjectPtr<AOtherPlayerController> pController;

	// UUID
	uint32 Uuid;

	// ジョブ
	uint8 Job;

	// キャラクタ名.
	FString CharacterName;
	
};
