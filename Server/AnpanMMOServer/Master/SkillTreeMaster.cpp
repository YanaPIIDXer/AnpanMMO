#include "stdafx.h"
#include "SkillTreeMaster.h"
#include "MySQL/MySqlConnection.h"

bool SkillTreeMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from SkillTree;");

	SkillTreeItem BindItem;

	Query.BindResultInt(&BindItem.ID);
	Query.BindResultChar(&BindItem.Job);
	Query.BindResultInt(&BindItem.SkillId);
	Query.BindResultInt(&BindItem.NeedLevel);
	Query.BindResultInt(&BindItem.Cost);
	Query.BindResultInt(&BindItem.ParentNode);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		SkillTreeItem Item;
		Item.ID = BindItem.ID;
		Item.Job = BindItem.Job;
		Item.SkillId = BindItem.SkillId;
		Item.NeedLevel = BindItem.NeedLevel;
		Item.Cost = BindItem.Cost;
		Item.ParentNode = BindItem.ParentNode;

		Items[Item.ID] = Item;
	}

	return true;
}

const SkillTreeItem *SkillTreeMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<SkillTreeItem> SkillTreeMaster::GetAll() const
{
	std::vector<SkillTreeItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const SkillTreeItem &A, const SkillTreeItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const SkillTreeItem &A, const SkillTreeItem &B)
{
	return (A.ID > B.ID);
}
