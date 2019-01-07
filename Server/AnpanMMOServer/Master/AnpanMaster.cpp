#include "stdafx.h"
#include "AnpanMaster.h"
#include "MySQL/MySqlConnection.h"

bool AnpanMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Anpan;");

	AnpanItem BindItem;
	s32 Sheet = 0;

	Query.BindResultInt(&BindItem.ID);
	Query.BindResultInt(&BindItem.Hp);
	Query.BindResultInt(&BindItem.Atk);
	Query.BindResultInt(&BindItem.Def);
	Query.BindResultInt(&BindItem.Exp);
	Query.BindResultFloat(&BindItem.Scale);
	Query.BindResultInt(&BindItem.DropId);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		AnpanItem Item;
		Item.ID = BindItem.ID;
		Item.Hp = BindItem.Hp;
		Item.Atk = BindItem.Atk;
		Item.Def = BindItem.Def;
		Item.Exp = BindItem.Exp;
		Item.Scale = BindItem.Scale;
		Item.DropId = BindItem.DropId;

		Items[Sheet][Item.ID] = Item;

	}

	return true;
}

const AnpanItem *AnpanMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<AnpanItem> AnpanMaster::GetAll() const
{
	std::vector<AnpanItem> AllItem;
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

bool operator <(const AnpanItem &A, const AnpanItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const AnpanItem &A, const AnpanItem &B)
{
	return (A.ID > B.ID);
}
