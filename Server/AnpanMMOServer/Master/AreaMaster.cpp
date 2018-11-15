#include "stdafx.h"
#include "AreaMaster.h"
#include "MySQL/MySqlConnection.h"

bool AreaMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Area;");

	AreaItem BindItem;
	char NameBind[128];
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultString(NameBind);
	Query.BindResultChar(&BindItem.bSpawnAnpan);
	Query.BindResultInt(&BindItem.AnpanMinHp);
	Query.BindResultInt(&BindItem.AnpanMaxHp);
	Query.BindResultInt(&BindItem.AnpanMinAtk);
	Query.BindResultInt(&BindItem.AnpanMaxAtk);
	Query.BindResultInt(&BindItem.AnpanMinDef);
	Query.BindResultInt(&BindItem.AnpanMaxDef);
	Query.BindResultInt(&BindItem.AnpanMinExp);
	Query.BindResultInt(&BindItem.AnpanMaxExp);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		AreaItem Item;
		Item.ID = BindItem.ID;
		Item.Name = NameBind;
		Item.bSpawnAnpan = BindItem.bSpawnAnpan;
		Item.AnpanMinHp = BindItem.AnpanMinHp;
		Item.AnpanMaxHp = BindItem.AnpanMaxHp;
		Item.AnpanMinAtk = BindItem.AnpanMinAtk;
		Item.AnpanMaxAtk = BindItem.AnpanMaxAtk;
		Item.AnpanMinDef = BindItem.AnpanMinDef;
		Item.AnpanMaxDef = BindItem.AnpanMaxDef;
		Item.AnpanMinExp = BindItem.AnpanMinExp;
		Item.AnpanMaxExp = BindItem.AnpanMaxExp;

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
