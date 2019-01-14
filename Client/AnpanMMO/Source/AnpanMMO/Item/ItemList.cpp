// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "ItemList.h"

// �R���X�g���N�^
ItemList::ItemList()
{
}

// �ǉ�.
void ItemList::Add(uint32 ItemId, uint32 Count)
{
	if (!Items.Contains(ItemId))
	{
		Items.Add(ItemId, 0);
	}
	Items[ItemId] += Count;
}

// �폜.
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

// �����擾.
uint32 ItemList::GetCount(uint32 ItemId) const
{
	if (!Items.Contains(ItemId)) { return 0; }
	return Items[ItemId];
}

// ��������A�C�e�����X�g���.
TArray<uint32> ItemList::CollectItemList() const
{
	TArray<uint32> List;
	for(const auto &KeyValue : Items)
	{
		List.Add(KeyValue.Key);
	}
	return List;
}

// �A�C�e���V���[�g�J�b�g���X�V.
void ItemList::UpdateItemShortcut(uint32 ItemId1, uint32 ItemId2)
{
	ItemShortcut.RemoveAt(0, ItemShortcut.Num());

	ItemShortcut.Add(ItemId1);
	ItemShortcut.Add(ItemId2);
}
