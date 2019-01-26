#include "stdafx.h"
#include "SkillTreeMaster.h"
#include "MySQL/MySqlConnection.h"

bool SkillTreeMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from SkillTree;");

	SkillTreeItem BindItem;
	s32 Sheet = 0;

	Query.BindResultInt(&BindItem.ID);
	Query.BindResultChar(&BindItem.Job);
	Query.BindResultInt(&BindItem.SkillId);
	Query.BindResultInt(&BindItem.NeedLevel);
	Query.BindResultInt(&BindItem.Cost);
	Query.BindResultFloat(&BindItem.NodeX);
	Query.BindResultFloat(&BindItem.NodeY);
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
		Item.NodeX = BindItem.NodeX;
		Item.NodeY = BindItem.NodeY;
		Item.ParentNode = BindItem.ParentNode;

		Items[Sheet][Item.ID] = Item;

	}

	return true;
}

const SkillTreeItem *SkillTreeMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<SkillTreeItem> SkillTreeMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<SkillTreeItem> AllItem;
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

std::vector<SkillTreeItem> SkillTreeMaster::GetAll() const
{
	std::vector<SkillTreeItem> AllItem;
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

bool operator <(const SkillTreeItem &A, const SkillTreeItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const SkillTreeItem &A, const SkillTreeItem &B)
{
	return (A.ID > B.ID);
}
