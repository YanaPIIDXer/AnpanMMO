#include "stdafx.h"
#include "AreaMaster.h"
#include "MySQL/MySqlConnection.h"

bool AreaMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Area;");

	AreaItem BindItem;
	char NameBind[128];	char LevelNameBind[128];
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultString(NameBind);
	Query.BindResultString(LevelNameBind);
	Query.BindResultChar(&BindItem.Type);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		AreaItem Item;
		Item.ID = BindItem.ID;
		Item.Name = NameBind;
		Item.LevelName = LevelNameBind;
		Item.Type = BindItem.Type;

		Items[Item.ID] = Item;
	}

	return true;
}

const AreaItem *AreaMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<AreaItem> AreaMaster::GetAll() const
{
	std::vector<AreaItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
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
