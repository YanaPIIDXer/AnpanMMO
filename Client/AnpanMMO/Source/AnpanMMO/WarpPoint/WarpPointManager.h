// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class AWarpPoint;

/**
 * ワープポイント管理クラス
 */
class ANPANMMO_API WarpPointManager
{

private:		// 別名定義.

	typedef TWeakObjectPtr<AWarpPoint> WarpPointPtr;

public:

	// コンストラクタ
	WarpPointManager();

	// デストラクタ
	~WarpPointManager() {}

	// Worldを設定.
	void SetWorld(UWorld *pInWorld) { pWorld = pInWorld; }

	// Spawn
	void Spawn(uint32 AreaId);

	// ワープポイントＩＤから生成.
	void SpawnFromWarpPointId(uint32 WarpPointId);

	// リセット
	void Reset();

private:

	// World
	TWeakObjectPtr<UWorld> pWorld;

	// ワープポイントリスト
	TArray<WarpPointPtr> WarpPoints;

};
