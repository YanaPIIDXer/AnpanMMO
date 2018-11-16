#include "stdafx.h"
#include "WarpDataMaster.h"
#include "MySQL/MySqlConnection.h"

bool WarpDataMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from WarpData;");

	WarpDataItem BindItem;

	Query.BindResultInt(&BindItem.ID);
	Query.BindResultInt(&BindItem.WarpDataId);
	Query.BindResultInt(&BindItem.AreaId);
	Query.BindResultFloat(&BindItem.X);
	Query.BindResultFloat(&BindItem.Y);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		WarpDataItem Item;
		Item.ID = BindItem.ID;
		Item.WarpDataId = BindItem.WarpDataId;
		Item.AreaId = BindItem.AreaId;
		Item.X = BindItem.X;
		Item.Y = BindItem.Y;

		Items[Item.ID] = Item;
	}

	return true;
}

const WarpDataItem *WarpDataMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
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
