#ifndef __SHOPMASTER_H__
#define __SHOPMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct ShopItem
{

public:



	s32 AutoKey;
	u32 ID;
	u32 ItemId;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&AutoKey)) { return false; }
		if(!pStream->Serialize(&ID)) { return false; }
		if(!pStream->Serialize(&ItemId)) { return false; }

		return true;
	}

};

class ShopMaster
{

private:

	typedef TMap<s32, ShopItem> ItemMap;
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<ShopItem> GetAllSheetItem(int32 SheetIndex) const;

	TArray<ShopItem> GetAll() const;

	TArray<const ShopItem *> CollectItems(u32 Key, int SheetIndex = 0) const;

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef __SHOPMASTER_H__
