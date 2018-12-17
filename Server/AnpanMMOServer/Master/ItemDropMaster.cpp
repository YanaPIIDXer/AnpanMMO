#include "stdafx.h"
#include "ItemDropMaster.h"
#include "MySQL/MySqlConnection.h"

bool ItemDropMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from ItemDrop;");

	ItemDropItem BindItem;

	Query.BindResultInt(&BindItem.ID);
	Query.BindResultChar(&BindItem.Type1);
	Query.BindResultInt(&BindItem.Id1);
	Query.BindResultInt(&BindItem.Count1);
	Query.BindResultChar(&BindItem.Type2);
	Query.BindResultInt(&BindItem.Id2);
	Query.BindResultInt(&BindItem.Count2);
	Query.BindResultChar(&BindItem.Type3);
	Query.BindResultInt(&BindItem.Id3);
	Query.BindResultInt(&BindItem.Count3);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		ItemDropItem Item;
		Item.ID = BindItem.ID;
		Item.Type1 = BindItem.Type1;
		Item.Id1 = BindItem.Id1;
		Item.Count1 = BindItem.Count1;
		Item.Type2 = BindItem.Type2;
		Item.Id2 = BindItem.Id2;
		Item.Count2 = BindItem.Count2;
		Item.Type3 = BindItem.Type3;
		Item.Id3 = BindItem.Id3;
		Item.Count3 = BindItem.Count3;

		Items[Item.ID] = Item;
	}

	return true;
}

const ItemDropItem *ItemDropMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<ItemDropItem> ItemDropMaster::GetAll() const
{
	std::vector<ItemDropItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const ItemDropItem &A, const ItemDropItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const ItemDropItem &A, const ItemDropItem &B)
{
	return (A.ID > B.ID);
}
