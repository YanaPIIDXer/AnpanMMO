#include "stdafx.h"
#include "AnpanAIMaster.h"
#include "MySQL/MySqlConnection.h"

bool AnpanAIMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from AnpanAI;");

	AnpanAIItem BindItem;
	s32 Sheet = 0;

	Query.BindResultInt(&Sheet);
	Query.BindResultInt(&BindItem.AutoKey);
	Query.BindResultChar(&BindItem.StageNo);
	Query.BindResultChar(&BindItem.Action);
	Query.BindResultInt(&BindItem.Value);

	if (!Query.ExecuteQuery()) { return false; }

	while (Query.Fetch())
	{
		AnpanAIItem Item;
		Item.AutoKey = BindItem.AutoKey;
		Item.StageNo = BindItem.StageNo;
		Item.Action = BindItem.Action;
		Item.Value = BindItem.Value;

		Items[Sheet][Item.AutoKey] = Item;

	}

	return true;
}

std::vector<const AnpanAIItem *> AnpanAIMaster::CollectItems(u8 Key, s32 SheetIndex) const
{
	std::vector<const AnpanAIItem *> Result;
	for(SheetMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		for(ItemMap::const_iterator It2 = It->second.begin(); It2 != It->second.end(); ++It2)
		{
			if(It2->second.StageNo == Key)
			{
				Result.push_back(&It2->second);
			}
		}
	}
	return Result;
}

std::vector<AnpanAIItem> AnpanAIMaster::GetAllSheetItem(s32 SheetIndex) const
{
	std::vector<AnpanAIItem> AllItem;
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

std::vector<AnpanAIItem> AnpanAIMaster::GetAll() const
{
	std::vector<AnpanAIItem> AllItem;
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

bool operator <(const AnpanAIItem &A, const AnpanAIItem &B)
{
	return (A.StageNo < B.StageNo);
}

bool operator >(const AnpanAIItem &A, const AnpanAIItem &B)
{
	return (A.StageNo > B.StageNo);
}
