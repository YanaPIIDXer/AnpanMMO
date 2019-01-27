#include "stdafx.h"
#include "QuestRewardMaster.h"
#include "MySQL/MySqlConnection.h"

bool QuestRewardMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from QuestReward;");

	QuestRewardItem BindItem;
	s32 Sheet = 0;

	Query.BindResultInt(&BindItem.ID);
	Query.BindResultChar(&BindItem.Type);
	Query.BindResultInt(&BindItem.ItemId);
	Query.BindResultInt(&BindItem.Count);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		QuestRewardItem Item;
		Item.ID = BindItem.ID;
		Item.Type = BindItem.Type;
		Item.ItemId = BindItem.ItemId;
		Item.Count = BindItem.Count;

		Items[Sheet][Item.ID] = Item;

	}

	return true;
}

const QuestRewardItem *QuestRewardMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<QuestRewardItem> QuestRewardMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<QuestRewardItem> AllItem;
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It != Items.end())
	{
		for (ItemMap::const_iterator It2 = It->second.begin(); It2 != It->second.end(); ++It2)
		{
			AllItem.push_back(It2->second);
		}
	}

	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

std::vector<QuestRewardItem> QuestRewardMaster::GetAll() const
{
	std::vector<QuestRewardItem> AllItem;
	for (SheetMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		for (ItemMap::const_iterator It2 = It->second.begin(); It2 != It->second.end(); ++It2)
		{
			AllItem.push_back(It2->second);
		}
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const QuestRewardItem &A, const QuestRewardItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const QuestRewardItem &A, const QuestRewardItem &B)
{
	return (A.ID > B.ID);
}
