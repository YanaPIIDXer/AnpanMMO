#include "stdafx.h"
#include "AnpanPopAreaMaster.h"
#include "MySQL/MySqlConnection.h"

bool AnpanPopAreaMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from AnpanPopArea;");

	AnpanPopAreaItem BindItem;

	Query.BindResultInt(&BindItem.AutoKey);
	Query.BindResultInt(&BindItem.AreaId);
	Query.BindResultFloat(&BindItem.X);
	Query.BindResultFloat(&BindItem.Y);
	Query.BindResultFloat(&BindItem.Range);
	Query.BindResultInt(&BindItem.AnpanMinHp);
	Query.BindResultInt(&BindItem.AnpanMaxHp);
	Query.BindResultInt(&BindItem.AnpanMinAtk);
	Query.BindResultInt(&BindItem.AnpanMaxAtk);
	Query.BindResultInt(&BindItem.AnpanMinDef);
	Query.BindResultInt(&BindItem.AnpanMaxDef);
	Query.BindResultInt(&BindItem.AnpanMinExp);
	Query.BindResultInt(&BindItem.AnpanMaxExp);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		AnpanPopAreaItem Item;
		Item.AutoKey = BindItem.AutoKey;
		Item.AreaId = BindItem.AreaId;
		Item.X = BindItem.X;
		Item.Y = BindItem.Y;
		Item.Range = BindItem.Range;
		Item.AnpanMinHp = BindItem.AnpanMinHp;
		Item.AnpanMaxHp = BindItem.AnpanMaxHp;
		Item.AnpanMinAtk = BindItem.AnpanMinAtk;
		Item.AnpanMaxAtk = BindItem.AnpanMaxAtk;
		Item.AnpanMinDef = BindItem.AnpanMinDef;
		Item.AnpanMaxDef = BindItem.AnpanMaxDef;
		Item.AnpanMinExp = BindItem.AnpanMinExp;
		Item.AnpanMaxExp = BindItem.AnpanMaxExp;

		Items[Item.AutoKey] = Item;
	}

	return true;
}

std::vector<const AnpanPopAreaItem *> AnpanPopAreaMaster::CollectItems(u32 Key) const
{
	std::vector<const AnpanPopAreaItem *> Result;
	for(ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		if(It->second.AreaId == Key)
		{
			Result.push_back(&It->second);
		}
	}
	return Result;
}

std::vector<AnpanPopAreaItem> AnpanPopAreaMaster::GetAll() const
{
	std::vector<AnpanPopAreaItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
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
