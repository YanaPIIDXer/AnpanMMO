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
