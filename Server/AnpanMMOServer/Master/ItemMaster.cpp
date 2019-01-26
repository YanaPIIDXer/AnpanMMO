#include "stdafx.h"
#include "ItemMaster.h"
#include "MySQL/MySqlConnection.h"

bool ItemMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Item;");

	ItemItem BindItem;
	s32 Sheet = 0;
	char NameBind[128];
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultString(NameBind);
	Query.BindResultChar(&BindItem.Type);
	Query.BindResultInt(&BindItem.BuyGold);
	Query.BindResultInt(&BindItem.SellGold);
	Query.BindResultInt(&BindItem.SkillId);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		ItemItem Item;
		Item.ID = BindItem.ID;
		Item.Name = NameBind;
		Item.Type = BindItem.Type;
		Item.BuyGold = BindItem.BuyGold;
		Item.SellGold = BindItem.SellGold;
		Item.SkillId = BindItem.SkillId;

		Items[Sheet][Item.ID] = Item;

	}

	return true;
}

const ItemItem *ItemMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<ItemItem> ItemMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<ItemItem> AllItem;
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

std::vector<ItemItem> ItemMaster::GetAll() const
{
	std::vector<ItemItem> AllItem;
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

bool operator <(const ItemItem &A, const ItemItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const ItemItem &A, const ItemItem &B)
{
	return (A.ID > B.ID);
}
