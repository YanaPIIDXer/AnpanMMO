#ifndef __ITEMMASTER_H__
#define __ITEMMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct ItemItem
{

public:

	enum
	{
		CONSUME = 0,
		DELIVERY = 1,
	};


	u32 ID;
	FString Name;
	u8 Type;
	u32 BuyGold;
	u32 SellGold;
	u32 SkillId;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		std::string StrName;
		if(!pStream->Serialize(&StrName)) { return false; }
		Name = UTF8_TO_TCHAR(StrName.c_str());
		if(!pStream->Serialize(&Type)) { return false; }
		if(!pStream->Serialize(&BuyGold)) { return false; }
		if(!pStream->Serialize(&SellGold)) { return false; }
		if(!pStream->Serialize(&SkillId)) { return false; }

		return true;
	}

};

class ItemMaster
{

private:

	typedef TMap<u32, ItemItem> ItemMap;
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<ItemItem> GetAll() const;

	const ItemItem *Get(u32 Key, int32 SheetIndex = 0) const;

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef __ITEMMASTER_H__
