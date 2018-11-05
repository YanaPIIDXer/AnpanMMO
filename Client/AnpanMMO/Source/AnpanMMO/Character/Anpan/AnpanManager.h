// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class AAnpan;
class MemoryStreamInterface;
class AnpanData;

/**
 * アンパン管理.
 */
class ANPANMMO_API AnpanManager
{

private:		// 別名定義.

	typedef TWeakObjectPtr<AAnpan> AnpanPtr;

public:

	// コンストラクタ
	AnpanManager();

	// デストラクタ
	~AnpanManager() {}

	// 毎フレームの処理.
	void Poll();

	// Worldをセット.
	void SetWorld(UWorld *pInWorld) { pWorld = pInWorld; }

	// 取得.
	AAnpan *Get(uint32 Uuid) const;

	// リストを受信した.
	void OnRecvList(MemoryStreamInterface *pStream);

	// 生成を受信した.
	void OnRecvSpawn(MemoryStreamInterface *pStream);

private:

	// アンパンマップ
	TMap<uint32, AnpanPtr> AnpanMap;

	// World
	TWeakObjectPtr<UWorld> pWorld;


	// アンパンをSpawn
	void SpawnAnpan(const AnpanData &Data);

};
