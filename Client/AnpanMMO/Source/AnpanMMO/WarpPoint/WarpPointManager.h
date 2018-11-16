// Copyright 2018 YanaPIIDXer All Rights Reserved.

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

private:

	// ワープポイントリスト
	TArray<WarpPointPtr> WarpPoints;

};
