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
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<NPCConditionItem> GetAllSheetItem(int32 SheetIndex) const;

	TArray<NPCConditionItem> GetAll() const;

	const NPCConditionItem *Get(u32 Key, int32 SheetIndex = 0) const;

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef __NPCCONDITIONMASTER_H__
