#include "stdafx.h"
#include "AnpanMaster.h"
#include "MySQL/MySqlConnection.h"

bool AnpanMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Anpan;");

	AnpanItem BindItem;

	Query.BindResultInt(&BindItem.ID);
	Query.BindResultInt(&BindItem.Hp);
	Query.BindResultInt(&BindItem.Atk);
	Query.BindResultInt(&BindItem.Def);
	Query.BindResultInt(&BindItem.Exp);
	Query.BindResultFloat(&BindItem.Scale);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		AnpanItem Item;
		Item.ID = BindItem.ID;
		Item.Hp = BindItem.Hp;
		Item.Atk = BindItem.Atk;
		Item.Def = BindItem.Def;
		Item.Exp = BindItem.Exp;
		Item.Scale = BindItem.Scale;

		Items[Item.ID] = Item;
	}

	return true;
}

const AnpanItem *AnpanMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<AnpanItem> AnpanMaster::GetAll() const
{
	std::vector<AnpanItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const AnpanItem &A, const AnpanItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const AnpanItem &A, const AnpanItem &B)
{
	return (A.ID > B.ID);
}
