#include "stdafx.h"
#include "QuestRewardMaster.h"
#include "MySQL/MySqlConnection.h"

bool QuestRewardMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from QuestReward;");

	QuestRewardItem BindItem;

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

		Items[Item.ID] = Item;
	}

	return true;
}

const QuestRewardItem *QuestRewardMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<QuestRewardItem> QuestRewardMaster::GetAll() const
{
	std::vector<QuestRewardItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
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
