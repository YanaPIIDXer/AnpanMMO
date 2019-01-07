#include "stdafx.h"
#include "WarpDataMaster.h"
#include "MySQL/MySqlConnection.h"

bool WarpDataMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from WarpData;");

	WarpDataItem BindItem;
	s32 Sheet = 0;

	Query.BindResultInt(&BindItem.ID);
	Query.BindResultInt(&BindItem.WarpDataId);
	Query.BindResultInt(&BindItem.AreaId);
	Query.BindResultFloat(&BindItem.X);
	Query.BindResultFloat(&BindItem.Y);
	Query.BindResultFloat(&BindItem.Z);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		WarpDataItem Item;
		Item.ID = BindItem.ID;
		Item.WarpDataId = BindItem.WarpDataId;
		Item.AreaId = BindItem.AreaId;
		Item.X = BindItem.X;
		Item.Y = BindItem.Y;
		Item.Z = BindItem.Z;

		Items[Sheet][Item.ID] = Item;

	}

	return true;
}

const WarpDataItem *WarpDataMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<WarpDataItem> WarpDataMaster::GetAll() const
{
	std::vector<WarpDataItem> AllItem;
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

bool operator <(const WarpDataItem &A, const WarpDataItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const WarpDataItem &A, const WarpDataItem &B)
{
	return (A.ID > B.ID);
}
