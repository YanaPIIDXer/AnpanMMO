#include "stdafx.h"
#include "QuestMaster.h"
#include "MySQL/MySqlConnection.h"

bool QuestMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Quest;");

	QuestItem BindItem;
	char NameBind[128];
	Query.BindResultInt(&BindItem.Id);
	Query.BindResultString(NameBind);
	Query.BindResultInt(&BindItem.StartStageId);
	Query.BindResultInt(&BindItem.RewardId);
	Query.BindResultInt(&BindItem.NextQuestId);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		QuestItem Item;
		Item.Id = BindItem.Id;
		Item.Name = NameBind;
		Item.StartStageId = BindItem.StartStageId;
		Item.RewardId = BindItem.RewardId;
		Item.NextQuestId = BindItem.NextQuestId;

		Items[Item.Id] = Item;
	}

	return true;
}

const QuestItem *QuestMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<QuestItem> QuestMaster::GetAll() const
{
	std::vector<QuestItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const QuestItem &A, const QuestItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const QuestItem &A, const QuestItem &B)
{
	return (A.Id > B.Id);
}
