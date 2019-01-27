#include "stdafx.h"
#include "LevelMaster.h"
#include "MySQL/MySqlConnection.h"

bool LevelMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Level;");

	LevelItem BindItem;
	s32 Sheet = 0;

	Query.BindResultInt(&Sheet);
	Query.BindResultInt(&BindItem.Level);
	Query.BindResultInt(&BindItem.MaxHP);
	Query.BindResultInt(&BindItem.STR);
	Query.BindResultInt(&BindItem.DEF);
	Query.BindResultInt(&BindItem.INT);
	Query.BindResultInt(&BindItem.MND);
	Query.BindResultInt(&BindItem.VIT);
	Query.BindResultInt(&BindItem.NextExp);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		LevelItem Item;
		Item.Level = BindItem.Level;
		Item.MaxHP = BindItem.MaxHP;
		Item.STR = BindItem.STR;
		Item.DEF = BindItem.DEF;
		Item.INT = BindItem.INT;
		Item.MND = BindItem.MND;
		Item.VIT = BindItem.VIT;
		Item.NextExp = BindItem.NextExp;

		Items[Sheet][Item.Level] = Item;

	}

	return true;
}

const LevelItem *LevelMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<LevelItem> LevelMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<LevelItem> AllItem;
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

std::vector<LevelItem> LevelMaster::GetAll() const
{
	std::vector<LevelItem> AllItem;
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

bool operator <(const LevelItem &A, const LevelItem &B)
{
	return (A.Level < B.Level);
}

bool operator >(const LevelItem &A, const LevelItem &B)
{
	return (A.Level > B.Level);
}
