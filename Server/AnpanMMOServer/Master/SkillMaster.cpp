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
	Query.BindResultInt(&BindItem.BonusMnd);
	Query.BindResultInt(&BindItem.BonusVit);

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
		Item.BonusMnd = BindItem.BonusMnd;
		Item.BonusVit = BindItem.BonusVit;

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
