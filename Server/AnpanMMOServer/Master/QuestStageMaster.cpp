#include "stdafx.h"
#include "QuestStageMaster.h"
#include "MySQL/MySqlConnection.h"

bool QuestStageMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from QuestStage;");

	QuestStageItem BindItem;
	s32 Sheet = 0;

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

		Items[Sheet][Item.Id] = Item;

	}

	return true;
}

const QuestStageItem *QuestStageMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<QuestStageItem> QuestStageMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<QuestStageItem> AllItem;
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

std::vector<QuestStageItem> QuestStageMaster::GetAll() const
{
	std::vector<QuestStageItem> AllItem;
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

bool operator <(const QuestStageItem &A, const QuestStageItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const QuestStageItem &A, const QuestStageItem &B)
{
	return (A.Id > B.Id);
}
