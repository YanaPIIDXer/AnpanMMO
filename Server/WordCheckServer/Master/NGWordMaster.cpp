#include "stdafx.h"
#include "NGWordMaster.h"
#include "MySQL/MySqlConnection.h"

bool NGWordMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from NGWord;");

	NGWordItem BindItem;
	char NGWordBind[128];
	Query.BindResultInt(&BindItem.AutoKey);
	Query.BindResultString(NGWordBind);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		NGWordItem Item;
		Item.AutoKey = BindItem.AutoKey;
		Item.NGWord = NGWordBind;

		Items[Item.AutoKey] = Item;
	}

	return true;
}

std::vector<const NGWordItem *> NGWordMaster::CollectItems(std::string Key) const
{
	std::vector<const NGWordItem *> Result;
	for(ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		if(It->second.NGWord == Key)
		{
			Result.push_back(&It->second);
		}
	}
	return Result;
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
