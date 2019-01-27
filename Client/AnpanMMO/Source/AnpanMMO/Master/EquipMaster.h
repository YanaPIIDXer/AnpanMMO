#ifndef __EQUIPMASTER_H__
#define __EQUIPMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct EquipItem
{

public:



	u32 ID;
	FString Name;
	u32 Str;
	u32 Def;
	u32 Int;
	u32 Mnd;
	u32 Vit;
	u32 NormalAttackId;
	u32 BuyGold;
	u32 SellGold;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		std::string StrName;
		if(!pStream->Serialize(&StrName)) { return false; }
		Name = UTF8_TO_TCHAR(StrName.c_str());
		if(!pStream->Serialize(&Str)) { return false; }
		if(!pStream->Serialize(&Def)) { return false; }
		if(!pStream->Serialize(&Int)) { return false; }
		if(!pStream->Serialize(&Mnd)) { return false; }
		if(!pStream->Serialize(&Vit)) { return false; }
		if(!pStream->Serialize(&NormalAttackId)) { return false; }
		if(!pStream->Serialize(&BuyGold)) { return false; }
		if(!pStream->Serialize(&SellGold)) { return false; }

		return true;
	}

};

class EquipMaster
{

private:

	typedef TMap<u32, EquipItem> ItemMap;
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<EquipItem> GetAllSheetItem(int32 SheetIndex) const;

	TArray<EquipItem> GetAll() const;

	const EquipItem *Get(u32 Key, int32 SheetIndex = 0) const;

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef __EQUIPMASTER_H__
