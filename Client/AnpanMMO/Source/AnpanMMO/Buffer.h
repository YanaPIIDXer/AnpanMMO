// Copyright 2018 YanaPIIDXer All Rights Reserved.

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
	void Push(uint8 *pData, int32 Size);

	// データを取り出す
	void Pop(int32 Size);

	// 先頭を取得.
	const uint8 *GetTop() const;

private:

	// データ
	TArray<uint8> Data;

};
