#include "stdafx.h"
#include "TimeInfoMaster.h"
#include "MySQL/MySqlConnection.h"

bool TimeInfoMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from TimeInfo;");

	TimeInfoItem BindItem;

	Query.BindResultInt(&BindItem.Id);
	Query.BindResultChar(&BindItem.TimeType);
	Query.BindResultFloat(&BindItem.LightAngle);
	Query.BindResultFloat(&BindItem.CloudSpeed);
	Query.BindResultFloat(&BindItem.CloudOpacity);
	Query.BindResultFloat(&BindItem.StarsBrightness);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		TimeInfoItem Item;
		Item.Id = BindItem.Id;
		Item.TimeType = BindItem.TimeType;
		Item.LightAngle = BindItem.LightAngle;
		Item.CloudSpeed = BindItem.CloudSpeed;
		Item.CloudOpacity = BindItem.CloudOpacity;
		Item.StarsBrightness = BindItem.StarsBrightness;

		Items[Item.Id] = Item;
	}

	return true;
}

const TimeInfoItem *TimeInfoMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<TimeInfoItem> TimeInfoMaster::GetAll() const
{
	std::vector<TimeInfoItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const TimeInfoItem &A, const TimeInfoItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const TimeInfoItem &A, const TimeInfoItem &B)
{
	return (A.Id > B.Id);
}
