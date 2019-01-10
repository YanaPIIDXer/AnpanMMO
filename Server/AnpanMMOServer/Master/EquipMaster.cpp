#include "stdafx.h"
#include "EquipMaster.h"
#include "MySQL/MySqlConnection.h"

bool EquipMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Equip;");

	EquipItem BindItem;
	s32 Sheet = 0;
	char NameBind[128];
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultString(NameBind);
	Query.BindResultInt(&BindItem.Str);
	Query.BindResultInt(&BindItem.Def);
	Query.BindResultInt(&BindItem.Int);
	Query.BindResultInt(&BindItem.Mnd);
	Query.BindResultInt(&BindItem.Vit);
	Query.BindResultInt(&BindItem.NormalAttackId);
	Query.BindResultInt(&BindItem.BuyGold);
	Query.BindResultInt(&BindItem.SellGold);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		EquipItem Item;
		Item.ID = BindItem.ID;
		Item.Name = NameBind;
		Item.Str = BindItem.Str;
		Item.Def = BindItem.Def;
		Item.Int = BindItem.Int;
		Item.Mnd = BindItem.Mnd;
		Item.Vit = BindItem.Vit;
		Item.NormalAttackId = BindItem.NormalAttackId;
		Item.BuyGold = BindItem.BuyGold;
		Item.SellGold = BindItem.SellGold;

		Items[Sheet][Item.ID] = Item;

	}

	return true;
}

const EquipItem *EquipMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<EquipItem> EquipMaster::GetAll() const
{
	std::vector<EquipItem> AllItem;
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

bool operator <(const EquipItem &A, const EquipItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const EquipItem &A, const EquipItem &B)
{
	return (A.ID > B.ID);
}
