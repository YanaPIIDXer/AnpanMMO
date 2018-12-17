#include "stdafx.h"
#include "ItemMaster.h"
#include "MySQL/MySqlConnection.h"

bool ItemMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Item;");

	ItemItem BindItem;
	char NameBind[128];
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultString(NameBind);
	Query.BindResultChar(&BindItem.Type);
	Query.BindResultInt(&BindItem.BuyGold);
	Query.BindResultInt(&BindItem.SellGold);
	Query.BindResultInt(&BindItem.SkillId);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		ItemItem Item;
		Item.ID = BindItem.ID;
		Item.Name = NameBind;
		Item.Type = BindItem.Type;
		Item.BuyGold = BindItem.BuyGold;
		Item.SellGold = BindItem.SellGold;
		Item.SkillId = BindItem.SkillId;

		Items[Item.ID] = Item;
	}

	return true;
}

const ItemItem *ItemMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<ItemItem> ItemMaster::GetAll() const
{
	std::vector<ItemItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const ItemItem &A, const ItemItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const ItemItem &A, const ItemItem &B)
{
	return (A.ID > B.ID);
}
