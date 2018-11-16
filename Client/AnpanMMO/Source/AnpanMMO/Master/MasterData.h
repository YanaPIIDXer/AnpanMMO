// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WarpDataMaster.h"
#include "WarpPointMaster.h"

/**
 * マスタデータ
 */
class ANPANMMO_API MasterData : FNoncopyable
{

public:

	// デストラクタ
	~MasterData() {}

	// ロード
	void Load();

	// ワープポイントマスタを取得.
	const WarpPointMaster &GetWarpPointMaster() const { return WarpPoint; }

	// ワープデータマスタを取得.
	const WarpDataMaster &GetWarpDataMaster() const { return WarpData; }

private:

	// ワープポイントマスタ
	WarpPointMaster WarpPoint;

	// ワープデータマスタ
	WarpDataMaster WarpData;

	// =========== Singleton ============
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData();
	static MasterData Instance;
};
