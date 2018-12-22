// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterBase.h"

class MemoryStreamInterface;
class PlayerData;

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

	// 生成を受信.
	bool OnRecvSpawn(MemoryStreamInterface *pStream);

	// リストを受信.
	bool OnRecvList(MemoryStreamInterface *pStream);

	// 移動を受信.
	bool OnRecvMove(MemoryStreamInterface *pStream);

	// 退出を受信.
	bool OnRecvExit(MemoryStreamInterface *pStream);

	// リセット.
	void Reset();

private:

	// プレイヤーマップ
	TMap<uint32, PlayerPtr> PlayerMap;

	// World
	TWeakObjectPtr<UWorld> pWorld;


	// キャラクタをSpawn
	void SpawnCharacter(const PlayerData &Data);

};
