#include "stdafx.h"
#include "BuffMaster.h"
#include "MySQL/MySqlConnection.h"

bool BuffMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Buff;");

	BuffItem BindItem;
	s32 Sheet = 0;
	char NameBind[128];
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultString(NameBind);
	Query.BindResultChar(&BindItem.Type);
	Query.BindResultInt(&BindItem.TimeMilliSec);
	Query.BindResultFloat(&BindItem.Value);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		BuffItem Item;
		Item.ID = BindItem.ID;
		Item.Name = NameBind;
		Item.Type = BindItem.Type;
		Item.TimeMilliSec = BindItem.TimeMilliSec;
		Item.Value = BindItem.Value;

		Items[Sheet][Item.ID] = Item;

	}

	return true;
}

const BuffItem *BuffMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<BuffItem> BuffMaster::GetAll() const
{
	std::vector<BuffItem> AllItem;
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

bool operator <(const BuffItem &A, const BuffItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const BuffItem &A, const BuffItem &B)
{
	return (A.ID > B.ID);
}
