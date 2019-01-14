// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class AGameCharacter;
class UMMOGameInstance;

/**
 * プレイヤー移動パケット処理クラス
 */
class ANPANMMO_API PlayerMove
{

public:

	// コンストラクタ
	PlayerMove();

	// デストラクタ
	~PlayerMove() {}

	// 初期化.
	void Initialize(AGameCharacter *pInCharacter, UMMOGameInstance *pInInst);

	// 毎フレームの処理.
	void Poll(float DeltaTime);

private:

	// 送信インターバル
	static const float SendInterval;

	// プレイヤーキャラ
	TWeakObjectPtr<AGameCharacter> pCharacter;

	// GameInstance
	TWeakObjectPtr<UMMOGameInstance> pInst;

	// 以前の座標.
	FVector PrevPos;

	// 送信タイマー
	float SendTimer;

	// キャラの高さの半分.
	float CharacterHalfHeight;

};
