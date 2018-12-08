#ifndef __NPCRESOURCEMASTER_H__
#define __NPCRESOURCEMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct NPCResourceItem
{

public:



	u32 ID;
	FString DLCName;
	s32 Index;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		std::string StrDLCName;
		if(!pStream->Serialize(&StrDLCName)) { return false; }
		DLCName = UTF8_TO_TCHAR(StrDLCName.c_str());
		if(!pStream->Serialize(&Index)) { return false; }

		return true;
	}

};

class NPCResourceMaster
{

private:

	typedef TMap<u32, NPCResourceItem> ItemMap;

public:

	void Load();

	TArray<NPCResourceItem> GetAll() const;

	const NPCResourceItem *Get(u32 Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef __NPCRESOURCEMASTER_H__