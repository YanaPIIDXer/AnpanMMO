#include "stdafx.h"
#include "InstanceInfoMaster.h"
#include "MySQL/MySqlConnection.h"

bool InstanceInfoMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from InstanceInfo;");

	InstanceInfoItem BindItem;

	Query.BindResultInt(&BindItem.Id);
	Query.BindResultInt(&BindItem.BossId);
	Query.BindResultInt(&BindItem.ExitWarpDataId);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		InstanceInfoItem Item;
		Item.Id = BindItem.Id;
		Item.BossId = BindItem.BossId;
		Item.ExitWarpDataId = BindItem.ExitWarpDataId;

		Items[Item.Id] = Item;
	}

	return true;
}

const InstanceInfoItem *InstanceInfoMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<InstanceInfoItem> InstanceInfoMaster::GetAll() const
{
	std::vector<InstanceInfoItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const InstanceInfoItem &A, const InstanceInfoItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const InstanceInfoItem &A, const InstanceInfoItem &B)
{
	return (A.Id > B.Id);
}
