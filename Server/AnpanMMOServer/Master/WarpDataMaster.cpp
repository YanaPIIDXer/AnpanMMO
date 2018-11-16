#include "stdafx.h"
#include "WarpDataMaster.h"
#include "MySQL/MySqlConnection.h"

bool WarpDataMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from WarpData;");

	WarpDataItem BindItem;

	Query.BindResultInt(&BindItem.AutoKey);
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultInt(&BindItem.AreaId);
	Query.BindResultFloat(&BindItem.X);
	Query.BindResultFloat(&BindItem.Y);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		WarpDataItem Item;
		Item.AutoKey = BindItem.AutoKey;
		Item.ID = BindItem.ID;
		Item.AreaId = BindItem.AreaId;
		Item.X = BindItem.X;
		Item.Y = BindItem.Y;

		Items[Item.AutoKey] = Item;
	}

	return true;
}

std::vector<const WarpDataItem *> WarpDataMaster::CollectItems(u32 Key) const
{
	std::vector<const WarpDataItem *> Result;
	for(ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		if(It->second.ID == Key)
		{
			Result.push_back(&It->second);
		}
	}
	return Result;
}

std::vector<WarpDataItem> WarpDataMaster::GetAll() const
{
	std::vector<WarpDataItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const WarpDataItem &A, const WarpDataItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const WarpDataItem &A, const WarpDataItem &B)
{
	return (A.ID > B.ID);
}
