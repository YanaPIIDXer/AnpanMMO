#ifndef __NPCCONDITIONMASTER_H__
#define __NPCCONDITIONMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct NPCConditionItem
{

public:



	u32 ID;
	u32 QuestId;
	u32 StageNo;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		if(!pStream->Serialize(&QuestId)) { return false; }
		if(!pStream->Serialize(&StageNo)) { return false; }

		return true;
	}

};

class NPCConditionMaster
{

private:

	typedef TMap<u32, NPCConditionItem> ItemMap;

public:

	void Load();

	TArray<NPCConditionItem> GetAll() const;

	const NPCConditionItem *Get(u32 Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef __NPCCONDITIONMASTER_H__
