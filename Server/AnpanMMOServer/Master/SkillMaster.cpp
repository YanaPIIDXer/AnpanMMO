#include "stdafx.h"
#include "SkillMaster.h"
#include "MySQL/MySqlConnection.h"

bool SkillMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Skill;");

	SkillItem BindItem;
	char NameBind[128];
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultString(NameBind);
	Query.BindResultChar(&BindItem.Type);
	Query.BindResultInt(&BindItem.Distance);
	Query.BindResultInt(&BindItem.RangeX);
	Query.BindResultInt(&BindItem.RangeY);
	Query.BindResultInt(&BindItem.CastTime);
	Query.BindResultInt(&BindItem.RecastTime);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		SkillItem Item;
		Item.ID = BindItem.ID;
		Item.Name = NameBind;
		Item.Type = BindItem.Type;
		Item.Distance = BindItem.Distance;
		Item.RangeX = BindItem.RangeX;
		Item.RangeY = BindItem.RangeY;
		Item.CastTime = BindItem.CastTime;
		Item.RecastTime = BindItem.RecastTime;

		Items[Item.ID] = Item;
	}

	return true;
}

const SkillItem *SkillMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<SkillItem> SkillMaster::GetAll() const
{
	std::vector<SkillItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
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
