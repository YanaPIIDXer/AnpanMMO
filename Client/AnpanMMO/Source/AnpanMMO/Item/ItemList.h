// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * アイテムリストクラス
 */
class ANPANMMO_API ItemList
{

private:		// 別名定義.

	typedef TMap<uint32, uint32> ItemMap;

public:

	// コンストラクタ
	ItemList();

	// デストラクタ
	~ItemList() {}

	// 追加.
	void Add(uint32 ItemId, uint32 Count);

	// 消去.
	void Subtract(uint32 ItemId, uint32 Count);

	// 個数を取得.
	uint32 GetCount(uint32 ItemId) const;

private:

	// アイテムマップ
	ItemMap Items;

};
