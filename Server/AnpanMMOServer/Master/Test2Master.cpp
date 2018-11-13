#include "stdafx.h"
#include "Test2Master.h"
#include "MySQL/MySqlConnection.h"

bool Test2Master::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Test2;");

	Test2Item BindItem;

	Query.BindResultInt(&BindItem.ID);
	Query.BindResultInt(&BindItem.Hp);
	Query.BindResultInt(&BindItem.Mp);
	Query.BindResultInt(&BindItem.Exp);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		Test2Item Item;
		Item.ID = BindItem.ID;
		Item.Hp = BindItem.Hp;
		Item.Mp = BindItem.Mp;
		Item.Exp = BindItem.Exp;

		Items[Item.ID] = Item;
	}

	return true;
}

const Test2Item *Test2Master::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<Test2Item> Test2Master::GetAll() const
{
	std::vector<Test2Item> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const Test2Item &A, const Test2Item &B)
{
	return (A.ID < B.ID);
}

bool operator >(const Test2Item &A, const Test2Item &B)
{
	return (A.ID > B.ID);
}
