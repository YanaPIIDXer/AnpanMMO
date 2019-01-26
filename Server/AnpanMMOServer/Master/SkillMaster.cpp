#include "stdafx.h"
#include "SkillMaster.h"
#include "MySQL/MySqlConnection.h"

bool SkillMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Skill;");

	SkillItem BindItem;
	s32 Sheet = 0;
	char NameBind[128];
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultString(NameBind);
	Query.BindResultChar(&BindItem.SkillType);
	Query.BindResultChar(&BindItem.RangeType);
	Query.BindResultChar(&BindItem.CalcType);
	Query.BindResultInt(&BindItem.Distance);
	Query.BindResultInt(&BindItem.RangeX);
	Query.BindResultInt(&BindItem.RangeY);
	Query.BindResultInt(&BindItem.CastTime);
	Query.BindResultInt(&BindItem.RecastTime);
	Query.BindResultInt(&BindItem.BonusStr);
	Query.BindResultInt(&BindItem.BonusInt);
	Query.BindResultInt(&BindItem.BonusMnd);
	Query.BindResultInt(&BindItem.BonusVit);
	Query.BindResultInt(&BindItem.VolatileHate);
	Query.BindResultInt(&BindItem.AccumulateHate);
	Query.BindResultInt(&BindItem.BuffId);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		SkillItem Item;
		Item.ID = BindItem.ID;
		Item.Name = NameBind;
		Item.SkillType = BindItem.SkillType;
		Item.RangeType = BindItem.RangeType;
		Item.CalcType = BindItem.CalcType;
		Item.Distance = BindItem.Distance;
		Item.RangeX = BindItem.RangeX;
		Item.RangeY = BindItem.RangeY;
		Item.CastTime = BindItem.CastTime;
		Item.RecastTime = BindItem.RecastTime;
		Item.BonusStr = BindItem.BonusStr;
		Item.BonusInt = BindItem.BonusInt;
		Item.BonusMnd = BindItem.BonusMnd;
		Item.BonusVit = BindItem.BonusVit;
		Item.VolatileHate = BindItem.VolatileHate;
		Item.AccumulateHate = BindItem.AccumulateHate;
		Item.BuffId = BindItem.BuffId;

		Items[Sheet][Item.ID] = Item;

	}

	return true;
}

const SkillItem *SkillMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<SkillItem> SkillMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<SkillItem> AllItem;
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

std::vector<SkillItem> SkillMaster::GetAll() const
{
	std::vector<SkillItem> AllItem;
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

bool operator <(const SkillItem &A, const SkillItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const SkillItem &A, const SkillItem &B)
{
	return (A.ID > B.ID);
}
