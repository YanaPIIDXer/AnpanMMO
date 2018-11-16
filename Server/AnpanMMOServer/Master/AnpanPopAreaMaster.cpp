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
	Query.BindResultInt(&BindItem.PopInterval);
	Query.BindResultInt(&BindItem.MaxCount);
	Query.BindResultInt(&BindItem.MinHp);
	Query.BindResultInt(&BindItem.MaxHp);
	Query.BindResultInt(&BindItem.MinAtk);
	Query.BindResultInt(&BindItem.MaxAtk);
	Query.BindResultInt(&BindItem.MinDef);
	Query.BindResultInt(&BindItem.MaxDef);
	Query.BindResultInt(&BindItem.MinExp);
	Query.BindResultInt(&BindItem.MaxExp);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		AnpanPopAreaItem Item;
		Item.AutoKey = BindItem.AutoKey;
		Item.AreaId = BindItem.AreaId;
		Item.X = BindItem.X;
		Item.Y = BindItem.Y;
		Item.Range = BindItem.Range;
		Item.PopInterval = BindItem.PopInterval;
		Item.MaxCount = BindItem.MaxCount;
		Item.MinHp = BindItem.MinHp;
		Item.MaxHp = BindItem.MaxHp;
		Item.MinAtk = BindItem.MinAtk;
		Item.MaxAtk = BindItem.MaxAtk;
		Item.MinDef = BindItem.MinDef;
		Item.MaxDef = BindItem.MaxDef;
		Item.MinExp = BindItem.MinExp;
		Item.MaxExp = BindItem.MaxExp;

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
