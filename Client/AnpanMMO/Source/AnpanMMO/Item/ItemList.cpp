// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "ItemList.h"

// コンストラクタ
ItemList::ItemList()
{
}

// 追加.
void ItemList::Add(uint32 ItemId, uint32 Count)
{
	if (!Items.Contains(ItemId))
	{
		Items.Add(ItemId, 0);
	}
	Items[ItemId] += Count;
}

// 削除.
void ItemList::Subtract(uint32 ItemId, uint32 Count)
{
	if (!Items.Contains(ItemId)) { return; }
	if (Items[ItemId] < Count)
	{
		Items.Remove(ItemId);
		return;
	}
	Items[ItemId] -= Count;
	if (Items[ItemId] == 0)
	{
		Items.Remove(ItemId);
	}
}

// 個数を取得.
uint32 ItemList::GetCount(uint32 ItemId) const
{
	if (!Items.Contains(ItemId)) { return 0; }
	return Items[ItemId];
}

// 所持するアイテムリストを列挙.
TArray<uint32> ItemList::CollectItemList() const
{
	TArray<uint32> List;
	for(const auto &KeyValue : Items)
	{
		List.Add(KeyValue.Key);
	}
	return List;
}

// アイテムショートカットを更新.
void ItemList::UpdateItemShortcut(uint32 ItemId1, uint32 ItemId2)
{
	ItemShortcut.RemoveAt(0, ItemShortcut.Num());

	ItemShortcut.Add(ItemId1);
	ItemShortcut.Add(ItemId2);
}
