#include "stdafx.h"
#include "QuestStageMaster.h"
#include "MySQL/MySqlConnection.h"

bool QuestStageMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from QuestStage;");

	QuestStageItem BindItem;

	Query.BindResultInt(&BindItem.Id);
	Query.BindResultChar(&BindItem.Condition);
	Query.BindResultInt(&BindItem.TargetId);
	Query.BindResultInt(&BindItem.Count);
	Query.BindResultInt(&BindItem.NextStageId);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		QuestStageItem Item;
		Item.Id = BindItem.Id;
		Item.Condition = BindItem.Condition;
		Item.TargetId = BindItem.TargetId;
		Item.Count = BindItem.Count;
		Item.NextStageId = BindItem.NextStageId;

		Items[Item.Id] = Item;
	}

	return true;
}

const QuestStageItem *QuestStageMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<QuestStageItem> QuestStageMaster::GetAll() const
{
	std::vector<QuestStageItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const QuestStageItem &A, const QuestStageItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const QuestStageItem &A, const QuestStageItem &B)
{
	return (A.Id > B.Id);
}
