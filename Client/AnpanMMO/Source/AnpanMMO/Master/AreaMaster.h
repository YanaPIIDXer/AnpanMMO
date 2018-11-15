#ifndef __AREAMASTER_H__
#define __AREAMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct AreaItem
{

public:

	u32 ID;
	std::string Name;
	u32 AnpanMax;
	s32 AnpanMinHp;
	s32 AnpanMaxHp;
	s32 AnpanMinAtk;
	s32 AnpanMaxAtk;
	s32 AnpanMinDef;
	s32 AnpanMaxDef;
	s32 AnpanMinExp;
	s32 AnpanMaxExp;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		if(!pStream->Serialize(&Name)) { return false; }
		if(!pStream->Serialize(&AnpanMax)) { return false; }
		if(!pStream->Serialize(&AnpanMinHp)) { return false; }
		if(!pStream->Serialize(&AnpanMaxHp)) { return false; }
		if(!pStream->Serialize(&AnpanMinAtk)) { return false; }
		if(!pStream->Serialize(&AnpanMaxAtk)) { return false; }
		if(!pStream->Serialize(&AnpanMinDef)) { return false; }
		if(!pStream->Serialize(&AnpanMaxDef)) { return false; }
		if(!pStream->Serialize(&AnpanMinExp)) { return false; }
		if(!pStream->Serialize(&AnpanMaxExp)) { return false; }

		return true;
	}

};

class AreaMaster
{

private:

	typedef TMap<u32, AreaItem> ItemMap;

public:

	void Load();

	TArray<AreaItem> GetAll() const;

	const AreaItem *Get(u32 Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef __AREAMASTER_H__
