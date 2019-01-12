// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * バッファクラス
 */
class ANPANMMO_API Buffer
{

public:

	// コンストラクタ
	Buffer();

	// デストラクタ
	~Buffer() {}

	// データを追加.
	void Push(const uint8 *pData, int32 Size);

	// データを取り出す
	void Pop(int32 Size);

	// 先頭を取得.
	uint8 *GetTop();

	// サイズを取得.
	int32 GetSize() const { return Data.Num(); }

private:

	// データ
	TArray<uint8> Data;

};
