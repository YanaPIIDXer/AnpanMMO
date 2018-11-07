// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterBase.h"

class MemoryStreamInterface;

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
	void OnRecvSpawn(MemoryStreamInterface *pStream);

	// リストを受信.
	void OnRecvList(MemoryStreamInterface *pStream);

	// 移動を受信.
	void OnRecvMove(MemoryStreamInterface *pStream);

	// 退出を受信.
	void OnRecvExit(MemoryStreamInterface *pStream);

private:

	// プレイヤーマップ
	TMap<uint8, PlayerPtr> PlayerMap;

	// World
	TWeakObjectPtr<UWorld> pWorld;


	// キャラクタをSpawn
	void SpawnCharacter(uint32 Uuid, float X, float Y, float Rotation);

};
