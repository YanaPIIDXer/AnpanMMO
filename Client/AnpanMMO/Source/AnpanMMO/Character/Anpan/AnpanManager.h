// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

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
	bool OnRecvList(MemoryStreamInterface *pStream);

	// 生成を受信した.
	bool OnRecvSpawn(MemoryStreamInterface *pStream);

	// 移動を受信した。
	bool OnRecvMove(MemoryStreamInterface *pStream);

	// 回転を受信した。
	bool OnRecvRotate(MemoryStreamInterface *pStream);

	// 停止を受信した。
	bool OnRecvStop(MemoryStreamInterface *pStream);

	// 前方のターゲットを取得.
	AAnpan *FindCenterTarget(float Distance);

	// リセット.
	void Reset();

private:

	// アンパンマップ
	TMap<uint32, AnpanPtr> AnpanMap;

	// World
	TWeakObjectPtr<UWorld> pWorld;


	// アンパンをSpawn
	void SpawnAnpan(const AnpanData &Data);

};
