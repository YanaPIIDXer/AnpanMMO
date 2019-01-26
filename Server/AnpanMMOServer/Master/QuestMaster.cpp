#include "stdafx.h"
#include "QuestMaster.h"
#include "MySQL/MySqlConnection.h"

bool QuestMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Quest;");

	QuestItem BindItem;
	s32 Sheet = 0;
	char NameBind[128];	char ExplainBind[128];
	Query.BindResultInt(&BindItem.Id);
	Query.BindResultString(NameBind);
	Query.BindResultString(ExplainBind);
	Query.BindResultChar(&BindItem.Type);
	Query.BindResultInt(&BindItem.StartStageId);
	Query.BindResultInt(&BindItem.RewardId);
	Query.BindResultInt(&BindItem.NextQuestId);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		QuestItem Item;
		Item.Id = BindItem.Id;
		Item.Name = NameBind;
		Item.Explain = ExplainBind;
		Item.Type = BindItem.Type;
		Item.StartStageId = BindItem.StartStageId;
		Item.RewardId = BindItem.RewardId;
		Item.NextQuestId = BindItem.NextQuestId;

		Items[Sheet][Item.Id] = Item;

	}

	return true;
}

const QuestItem *QuestMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<QuestItem> QuestMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<QuestItem> AllItem;
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

std::vector<QuestItem> QuestMaster::GetAll() const
{
	std::vector<QuestItem> AllItem;
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

bool operator <(const QuestItem &A, const QuestItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const QuestItem &A, const QuestItem &B)
{
	return (A.Id > B.Id);
}
