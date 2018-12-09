#include "stdafx.h"
#include "NPCMaster.h"
#include "MySQL/MySqlConnection.h"

bool NPCMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from NPC;");

	NPCItem BindItem;
	char NameBind[128];	char ScriptNameBind[128];
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultString(NameBind);
	Query.BindResultInt(&BindItem.AreaId);
	Query.BindResultFloat(&BindItem.X);
	Query.BindResultFloat(&BindItem.Y);
	Query.BindResultFloat(&BindItem.Z);
	Query.BindResultFloat(&BindItem.Rotation);
	Query.BindResultString(ScriptNameBind);
	Query.BindResultInt(&BindItem.AppearConditionId);
	Query.BindResultInt(&BindItem.EraseConditionId);
	Query.BindResultInt(&BindItem.ResourceId);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		NPCItem Item;
		Item.ID = BindItem.ID;
		Item.Name = NameBind;
		Item.AreaId = BindItem.AreaId;
		Item.X = BindItem.X;
		Item.Y = BindItem.Y;
		Item.Z = BindItem.Z;
		Item.Rotation = BindItem.Rotation;
		Item.ScriptName = ScriptNameBind;
		Item.AppearConditionId = BindItem.AppearConditionId;
		Item.EraseConditionId = BindItem.EraseConditionId;
		Item.ResourceId = BindItem.ResourceId;

		Items[Item.ID] = Item;
	}

	return true;
}

const NPCItem *NPCMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

std::vector<NPCItem> NPCMaster::GetAll() const
{
	std::vector<NPCItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const NPCItem &A, const NPCItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const NPCItem &A, const NPCItem &B)
{
	return (A.ID > B.ID);
}
