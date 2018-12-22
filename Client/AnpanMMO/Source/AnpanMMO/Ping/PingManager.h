// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class AActiveGameMode;

/**
 * Tick管理.
 */
class ANPANMMO_API PingManager
{
public:

	// コンストラクタ
	PingManager();

	// デストラクタ
	~PingManager() {}

	// 更新.
	void Poll(float DeltaTime);

	// ゲームモードをセット
	void SetGameMode(AActiveGameMode *pInGameMode) { pGameMode = pInGameMode; }

	// Pingを受信した。
	bool OnRecvPing(MemoryStreamInterface *pStream);

private:

	// インターバル
	static const float Interval;

	// タイマー
	float Timer;

	// GameMode
	TWeakObjectPtr<AActiveGameMode> pGameMode;

	// Pingを受信したか？
	bool bRecvPing;

};
