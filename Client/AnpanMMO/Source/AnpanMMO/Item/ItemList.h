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

	// 所持するアイテムリストを列挙.
	// ※個数は考えない。
	TArray<uint32> CollectItemList() const;

	// アイテムショートカットを更新.
	void UpdateItemShortcut(uint32 ItemId1, uint32 ItemId2);

	// アイテムショートカットを取得.
	const TArray<uint32> &GetItemShortcut() const { return ItemShortcut; }

private:

	// アイテムマップ
	ItemMap Items;

	// アイテムショートカット
	TArray<uint32> ItemShortcut;

};
