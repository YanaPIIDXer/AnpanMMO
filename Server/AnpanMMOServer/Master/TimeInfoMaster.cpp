#include "stdafx.h"
#include "TimeInfoMaster.h"
#include "MySQL/MySqlConnection.h"

bool TimeInfoMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from TimeInfo;");

	TimeInfoItem BindItem;
	s32 Sheet = 0;

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

		Items[Sheet][Item.Id] = Item;

	}

	return true;
}

const TimeInfoItem *TimeInfoMaster::GetItem(u32 Key, s32 SheetIndex) const
{
	SheetMap::const_iterator It = Items.find(SheetIndex);
	if (It == Items.end()) { return NULL; }
	ItemMap::const_iterator It2 = It->second.find(Key);
	if(It2 == It->second.end()) { return NULL; }
	return &It2->second;
}

std::vector<TimeInfoItem> TimeInfoMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<TimeInfoItem> AllItem;
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

std::vector<TimeInfoItem> TimeInfoMaster::GetAll() const
{
	std::vector<TimeInfoItem> AllItem;
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

bool operator <(const TimeInfoItem &A, const TimeInfoItem &B)
{
	return (A.Id < B.Id);
}

bool operator >(const TimeInfoItem &A, const TimeInfoItem &B)
{
	return (A.Id > B.Id);
}
