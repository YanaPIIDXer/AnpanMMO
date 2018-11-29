// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class MemoryStreamInterface;
class AActiveGameMode;

/**
 * パーティ情報.
 */
class ANPANMMO_API PartyInformation
{

public:

	// コンストラクタ
	PartyInformation();

	// デストラクタ
	~PartyInformation() {}

	// GameModeをセット。
	void SetGameMode(AActiveGameMode *pInGameMode) { pGameMode = pInGameMode; }

	// 参加しているか？
	bool IsJoined() const { return (PartyId != 0); }

	// 作成結果を受信した。
	void OnRecvCreateResult(MemoryStreamInterface *pStream);

private:

	// パーティＩＤ
	uint32 PartyId;

	// GameMode
	TWeakObjectPtr<AActiveGameMode> pGameMode;

};
