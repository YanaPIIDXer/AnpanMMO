#include "stdafx.h"
#include "AnpanPopDataMaster.h"
#include "MySQL/MySqlConnection.h"

bool AnpanPopDataMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from AnpanPopData;");

	AnpanPopDataItem BindItem;

	Query.BindResultInt(&BindItem.AutoKey);
	Query.BindResultInt(&BindItem.Id);
	Query.BindResultInt(&BindItem.AnpanId);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		AnpanPopDataItem Item;
		Item.AutoKey = BindItem.AutoKey;
		Item.Id = BindItem.Id;
		Item.AnpanId = BindItem.AnpanId;

		Items[Item.AutoKey] = Item;
	}

	return true;
}

std::vector<const AnpanPopDataItem *> AnpanPopDataMaster::CollectItems(u32 Key) const
{
	std::vector<const AnpanPopDataItem *> Result;
	for(ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		if(It->second.Id == Key)
		{
			Result.push_back(&It->second);
		}
	}
	return Result;
}

std::vector<AnpanPopDataItem> AnpanPopDataMaster::GetAll() const
{
	std::vector<AnpanPopDataItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const AnpanPopDataItem &A, const AnpanPopDataItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const AnpanPopDataItem &A, const AnpanPopDataItem &B)
{
	return (A.Id > B.Id);
}
