#ifndef __ANPANMASTER_H__
#define __ANPANMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct AnpanItem
{

public:



	u32 ID;
	s32 Hp;
	s32 Atk;
	s32 Def;
	s32 Exp;
	float Scale;
	u32 DropId;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		if(!pStream->Serialize(&Hp)) { return false; }
		if(!pStream->Serialize(&Atk)) { return false; }
		if(!pStream->Serialize(&Def)) { return false; }
		if(!pStream->Serialize(&Exp)) { return false; }
		if(!pStream->Serialize(&Scale)) { return false; }
		if(!pStream->Serialize(&DropId)) { return false; }

		return true;
	}

};

class AnpanMaster
{

private:

	typedef TMap<u32, AnpanItem> ItemMap;

public:

	void Load();

	TArray<AnpanItem> GetAll() const;

	const AnpanItem *Get(u32 Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef __ANPANMASTER_H__
