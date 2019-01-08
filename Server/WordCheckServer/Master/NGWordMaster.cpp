#include "stdafx.h"
#include "NGWordMaster.h"
#include "MySQL/MySqlConnection.h"

bool NGWordMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from NGWord;");

	NGWordItem BindItem;
	s32 Sheet = 0;
	char NGWordBind[128];
	Query.BindResultInt(&BindItem.AutoKey);
	Query.BindResultString(NGWordBind);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		NGWordItem Item;
		Item.AutoKey = BindItem.AutoKey;
		Item.NGWord = NGWordBind;

		Items[Sheet][Item.AutoKey] = Item;

	}

	return true;
}



std::vector<NGWordItem> NGWordMaster::GetAll() const
{
	std::vector<NGWordItem> AllItem;
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

bool operator <(const NGWordItem &A, const NGWordItem &B)
{
	return (A.NGWord < B.NGWord);
}

bool operator >(const NGWordItem &A, const NGWordItem &B)
{
	return (A.NGWord > B.NGWord);
}
