#include "stdafx.h"
#include "AnpanPopAreaMaster.h"
#include "MySQL/MySqlConnection.h"

bool AnpanPopAreaMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from AnpanPopArea;");

	AnpanPopAreaItem BindItem;
	s32 Sheet = 0;

	Query.BindResultInt(&BindItem.AutoKey);
	Query.BindResultInt(&BindItem.AreaId);
	Query.BindResultFloat(&BindItem.X);
	Query.BindResultFloat(&BindItem.Y);
	Query.BindResultFloat(&BindItem.Z);
	Query.BindResultFloat(&BindItem.Range);
	Query.BindResultInt(&BindItem.PopInterval);
	Query.BindResultInt(&BindItem.MaxCount);
	Query.BindResultInt(&BindItem.PopId);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		AnpanPopAreaItem Item;
		Item.AutoKey = BindItem.AutoKey;
		Item.AreaId = BindItem.AreaId;
		Item.X = BindItem.X;
		Item.Y = BindItem.Y;
		Item.Z = BindItem.Z;
		Item.Range = BindItem.Range;
		Item.PopInterval = BindItem.PopInterval;
		Item.MaxCount = BindItem.MaxCount;
		Item.PopId = BindItem.PopId;

		Items[Sheet][Item.AutoKey] = Item;

	}

	return true;
}

std::vector<const AnpanPopAreaItem *> AnpanPopAreaMaster::CollectItems(u32 Key, s32 SheetIndex) const
{
	std::vector<const AnpanPopAreaItem *> Result;
	for(SheetMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		for(ItemMap::const_iterator It2 = It->second.begin(); It2 != It->second.end(); ++It2)
		{
			if(It2->second.AreaId == Key)
			{
				Result.push_back(&It2->second);
			}
		}
	}
	return Result;
}

std::vector<AnpanPopAreaItem> AnpanPopAreaMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<AnpanPopAreaItem> AllItem;
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It != Items.end())
	{
		for (ItemMap::const_iterator It2 = It->second.begin(); It2 != It->second.end(); ++It2)
		{
			AllItem.push_back(It2->second);
		}
	}

	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

std::vector<AnpanPopAreaItem> AnpanPopAreaMaster::GetAll() const
{
	std::vector<AnpanPopAreaItem> AllItem;
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

bool operator <(const AnpanPopAreaItem &A, const AnpanPopAreaItem &B)
{
	return (A.AreaId < B.AreaId);
}

bool operator >(const AnpanPopAreaItem &A, const AnpanPopAreaItem &B)
{
	return (A.AreaId > B.AreaId);
}
