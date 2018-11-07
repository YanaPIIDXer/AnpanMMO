// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterBase.h"

/**
 * プレイヤー管理.
 */
class ANPANMMO_API PlayerManager
{

private:		// 別名定義.

	typedef TWeakObjectPtr<APlayerCharacterBase> PlayerPtr;
	
public:

	// コンストラクタ
	PlayerManager();

	// デストラクタ
	~PlayerManager() {}

	// Worldを設定.
	void SetWorld(UWorld *pInWorld) { pWorld = pInWorld; }

	// 追加.
	void Add(uint8 Uuid, APlayerCharacterBase *pPlayer);

	// 取得.
	APlayerCharacterBase *Get(uint32 Uuid) const;

private:

	// プレイヤーマップ
	TMap<uint8, PlayerPtr> PlayerMap;

	// World
	TWeakObjectPtr<UWorld> pWorld;

};
