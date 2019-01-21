#include "stdafx.h"
#include "ShopMaster.h"
#include "MySQL/MySqlConnection.h"

bool ShopMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Shop;");

	ShopItem BindItem;
	s32 Sheet = 0;

	Query.BindResultInt(&BindItem.AutoKey);
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultInt(&BindItem.ItemId);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		ShopItem Item;
		Item.AutoKey = BindItem.AutoKey;
		Item.ID = BindItem.ID;
		Item.ItemId = BindItem.ItemId;

		Items[Sheet][Item.AutoKey] = Item;

	}

	return true;
}

std::vector<const ShopItem *> ShopMaster::CollectItems(u32 Key, s32 SheetIndex) const
{
	std::vector<const ShopItem *> Result;
	for(SheetMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		for(ItemMap::const_iterator It2 = It->second.begin(); It2 != It->second.end(); ++It2)
		{
			if(It2->second.ID == Key)
			{
				Result.push_back(&It2->second);
			}
		}
	}
	return Result;
}

std::vector<ShopItem> ShopMaster::GetAll() const
{
	std::vector<ShopItem> AllItem;
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

bool operator <(const ShopItem &A, const ShopItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const ShopItem &A, const ShopItem &B)
{
	return (A.ID > B.ID);
}
