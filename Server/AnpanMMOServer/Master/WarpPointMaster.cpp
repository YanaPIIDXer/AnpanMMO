#include "stdafx.h"
#include "WarpPointMaster.h"
#include "MySQL/MySqlConnection.h"

bool WarpPointMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from WarpPoint;");

	WarpPointItem BindItem;
	s32 Sheet = 0;

	Query.BindResultInt(&BindItem.Id);
	Query.BindResultInt(&BindItem.AreaId);
	Query.BindResultFloat(&BindItem.X);
	Query.BindResultFloat(&BindItem.Y);
	Query.BindResultFloat(&BindItem.Z);
	Query.BindResultInt(&BindItem.WarpDataId);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		WarpPointItem Item;
		Item.Id = BindItem.Id;
		Item.AreaId = BindItem.AreaId;
		Item.X = BindItem.X;
		Item.Y = BindItem.Y;
		Item.Z = BindItem.Z;
		Item.WarpDataId = BindItem.WarpDataId;

		Items[Sheet][Item.Id] = Item;

	}

	return true;
}

const WarpPointItem *WarpPointMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<WarpPointItem> WarpPointMaster::GetAll() const
{
	std::vector<WarpPointItem> AllItem;
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

bool operator <(const WarpPointItem &A, const WarpPointItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const WarpPointItem &A, const WarpPointItem &B)
{
	return (A.Id > B.Id);
}
