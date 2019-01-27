#include "stdafx.h"
#include "AnpanPopDataMaster.h"
#include "MySQL/MySqlConnection.h"

bool AnpanPopDataMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from AnpanPopData;");

	AnpanPopDataItem BindItem;
	s32 Sheet = 0;

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

		Items[Sheet][Item.AutoKey] = Item;

	}

	return true;
}

std::vector<const AnpanPopDataItem *> AnpanPopDataMaster::CollectItems(u32 Key, s32 SheetIndex) const
{
	std::vector<const AnpanPopDataItem *> Result;
	for(SheetMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		for(ItemMap::const_iterator It2 = It->second.begin(); It2 != It->second.end(); ++It2)
		{
			if(It2->second.Id == Key)
			{
				Result.push_back(&It2->second);
			}
		}
	}
	return Result;
}

std::vector<AnpanPopDataItem> AnpanPopDataMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<AnpanPopDataItem> AllItem;
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

std::vector<AnpanPopDataItem> AnpanPopDataMaster::GetAll() const
{
	std::vector<AnpanPopDataItem> AllItem;
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

bool operator <(const AnpanPopDataItem &A, const AnpanPopDataItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const AnpanPopDataItem &A, const AnpanPopDataItem &B)
{
	return (A.Id > B.Id);
}
