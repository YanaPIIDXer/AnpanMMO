#include "stdafx.h"
#include "AreaMaster.h"
#include "MySQL/MySqlConnection.h"

bool AreaMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Area;");

	AreaItem BindItem;
	s32 Sheet = 0;
	char NameBind[128];	char LevelNameBind[128];
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultString(NameBind);
	Query.BindResultString(LevelNameBind);
	Query.BindResultChar(&BindItem.Type);
	Query.BindResultInt(&BindItem.InstanceInfoId);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		AreaItem Item;
		Item.ID = BindItem.ID;
		Item.Name = NameBind;
		Item.LevelName = LevelNameBind;
		Item.Type = BindItem.Type;
		Item.InstanceInfoId = BindItem.InstanceInfoId;

		Items[Sheet][Item.ID] = Item;

	}

	return true;
}

const AreaItem *AreaMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<AreaItem> AreaMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<AreaItem> AllItem;
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

std::vector<AreaItem> AreaMaster::GetAll() const
{
	std::vector<AreaItem> AllItem;
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

bool operator <(const AreaItem &A, const AreaItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const AreaItem &A, const AreaItem &B)
{
	return (A.ID > B.ID);
}
