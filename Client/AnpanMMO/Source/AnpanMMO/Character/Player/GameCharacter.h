// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterBase.h"
#include "PlayerStatus.h"
#include "GameCharacter.generated.h"

class UFloatingPawnMovement;
class USkeletalMeshComponent;

/**
 * プレイヤーキャラクタクラス
 */
UCLASS()
class ANPANMMO_API AGameCharacter : public APlayerCharacterBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	AGameCharacter(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AGameCharacter() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// 攻撃.
	void Attack();

	// ステータス取得.
	const PlayerStatus &GetStatus() const { return Status; }

	// 経験値を受信した。
	void OnRecvExp(int32 Exp);

	// レベルアップした。
	void OnLevelUp(int32 MaxHp, int32 Atk, int32 Def);

private:

	// AnimInstanceのクラスパス
	static const TCHAR *AnimInstanceClassPath;

	// 移動用Component
	UPROPERTY()
	UFloatingPawnMovement *pMovementComponent;

	// ステータス
	PlayerStatus Status;

};
