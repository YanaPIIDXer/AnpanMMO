#include "stdafx.h"
#include "ItemList.h"

// �R���X�g���N�^
ItemList::ItemList()
{
}

// �ǉ�.
void ItemList::Add(u32 ItemId, u32 Count)
{
	if (Items.find(ItemId) == Items.end())
	{
		Items[ItemId] = 0;
	}
	Items[ItemId] += Count;
}

// ����.
void ItemList::Subtract(u32 ItemId, u32 Count)
{
	if (Items.find(ItemId) == Items.end()) { return; }
	if (Items[ItemId] < Count)
	{
		// �����Ă͂Ȃ�Ȃ��������E�E�E
		Items.erase(ItemId);
		return;
	}
	Items[ItemId] -= Count;
	if (Items[ItemId] == 0)
	{
		Items.erase(ItemId);
	}
}

// �����擾.
u32 ItemList::GetCount(u32 ItemId) const
{
	ItemMap::const_iterator It = Items.find(ItemId);
	if (It == Items.end()) { return 0; }
	return It->second;
}