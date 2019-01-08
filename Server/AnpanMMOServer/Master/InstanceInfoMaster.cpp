#include "stdafx.h"
#include "InstanceInfoMaster.h"
#include "MySQL/MySqlConnection.h"

bool InstanceInfoMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from InstanceInfo;");

	InstanceInfoItem BindItem;
	s32 Sheet = 0;

	Query.BindResultInt(&BindItem.Id);
	Query.BindResultInt(&BindItem.BossId);
	Query.BindResultFloat(&BindItem.BossX);
	Query.BindResultFloat(&BindItem.BossY);
	Query.BindResultFloat(&BindItem.BossZ);
	Query.BindResultInt(&BindItem.ExitWarpPointId);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		InstanceInfoItem Item;
		Item.Id = BindItem.Id;
		Item.BossId = BindItem.BossId;
		Item.BossX = BindItem.BossX;
		Item.BossY = BindItem.BossY;
		Item.BossZ = BindItem.BossZ;
		Item.ExitWarpPointId = BindItem.ExitWarpPointId;

		Items[Sheet][Item.Id] = Item;

	}

	return true;
}

const InstanceInfoItem *InstanceInfoMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<InstanceInfoItem> InstanceInfoMaster::GetAll() const
{
	std::vector<InstanceInfoItem> AllItem;
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

bool operator <(const InstanceInfoItem &A, const InstanceInfoItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const InstanceInfoItem &A, const InstanceInfoItem &B)
{
	return (A.Id > B.Id);
}
