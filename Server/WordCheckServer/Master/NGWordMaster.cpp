#include "stdafx.h"
#include "NGWordMaster.h"
#include "MySQL/MySqlConnection.h"

bool NGWordMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from NGWord;");

	NGWordItem BindItem;

	Query.BindResultInt(&BindItem.AutoKey);
	

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		NGWordItem Item;
		Item.AutoKey = BindItem.AutoKey;
		Item.NGWord = BindItem.NGWord;

		Items[Item.AutoKey] = Item;
	}

	return true;
}



std::vector<NGWordItem> NGWordMaster::GetAll() const
{
	std::vector<NGWordItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const NGWordItem &A, const NGWordItem &B)
{
	return (A.NGWord < B.NGWord);
}

bool operator >(const NGWordItem &A, const NGWordItem &B)
{
	return (A.NGWord > B.NGWord);
}
