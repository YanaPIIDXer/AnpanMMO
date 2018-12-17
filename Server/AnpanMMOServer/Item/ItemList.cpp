#include "stdafx.h"
#include "ItemList.h"

// コンストラクタ
ItemList::ItemList()
{
}

// 追加.
void ItemList::Add(u32 ItemId, u32 Count)
{
	if (Items.find(ItemId) == Items.end())
	{
		Items[ItemId] = 0;
	}
	Items[ItemId] += Count;
}

// 消費.
void ItemList::Subtract(u32 ItemId, u32 Count)
{
	if (Items.find(ItemId) == Items.end()) { return; }
	if (Items[ItemId] < Count)
	{
		// あってはならない事だが・・・
		Items.erase(ItemId);
		return;
	}
	Items[ItemId] -= Count;
	if (Items[ItemId] == 0)
	{
		Items.erase(ItemId);
	}
}

// 個数を取得.
u32 ItemList::GetCount(u32 ItemId) const
{
	ItemMap::const_iterator It = Items.find(ItemId);
	if (It == Items.end()) { return 0; }
	return It->second;
}
