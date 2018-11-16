#include "stdafx.h"
#include "WarpPointMaster.h"
#include "MySQL/MySqlConnection.h"

bool WarpPointMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from WarpPoint;");

	WarpPointItem BindItem;

	Query.BindResultInt(&BindItem.Id);
	Query.BindResultInt(&BindItem.AreaId);
	Query.BindResultFloat(&BindItem.X);
	Query.BindResultFloat(&BindItem.Y);
	Query.BindResultInt(&BindItem.WarpDataId);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		WarpPointItem Item;
		Item.Id = BindItem.Id;
		Item.AreaId = BindItem.AreaId;
		Item.X = BindItem.X;
		Item.Y = BindItem.Y;
		Item.WarpDataId = BindItem.WarpDataId;

		Items[Item.Id] = Item;
	}

	return true;
}

const WarpPointItem *WarpPointMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<WarpPointItem> WarpPointMaster::GetAll() const
{
	std::vector<WarpPointItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const WarpPointItem &A, const WarpPointItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const WarpPointItem &A, const WarpPointItem &B)
{
	return (A.Id > B.Id);
}
