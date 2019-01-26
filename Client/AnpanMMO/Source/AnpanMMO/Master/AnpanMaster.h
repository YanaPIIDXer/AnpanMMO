#ifndef __ANPANMASTER_H__
#define __ANPANMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct AnpanItem
{

public:



	u32 ID;
	u32 Hp;
	u32 Str;
	u32 Def;
	u32 Int;
	u32 Mnd;
	u32 Vit;
	u32 Exp;
	float Scale;
	u8 AIId;
	u32 DropId;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		if(!pStream->Serialize(&Hp)) { return false; }
		if(!pStream->Serialize(&Str)) { return false; }
		if(!pStream->Serialize(&Def)) { return false; }
		if(!pStream->Serialize(&Int)) { return false; }
		if(!pStream->Serialize(&Mnd)) { return false; }
		if(!pStream->Serialize(&Vit)) { return false; }
		if(!pStream->Serialize(&Exp)) { return false; }
		if(!pStream->Serialize(&Scale)) { return false; }
		if(!pStream->Serialize(&AIId)) { return false; }
		if(!pStream->Serialize(&DropId)) { return false; }

		return true;
	}

};

class AnpanMaster
{

private:

	typedef TMap<u32, AnpanItem> ItemMap;
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<AnpanItem> GetAllSheetItem(int32 SheetIndex) const;

	TArray<AnpanItem> GetAll() const;

	const AnpanItem *Get(u32 Key, int32 SheetIndex = 0) const;

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef __ANPANMASTER_H__
