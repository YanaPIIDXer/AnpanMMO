#ifndef __QUESTSTAGEMASTER_H__
#define __QUESTSTAGEMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct QuestStageItem
{

public:

	enum
	{
		NPC = 0,
		KILL_ANPAN_IN_AREA = 1,
		COLLECT_ITEM = 2,
	};


	u32 Id;
	u8 Condition;
	u32 TargetId;
	u32 Count;
	u32 NextStageId;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&Id)) { return false; }
		if(!pStream->Serialize(&Condition)) { return false; }
		if(!pStream->Serialize(&TargetId)) { return false; }
		if(!pStream->Serialize(&Count)) { return false; }
		if(!pStream->Serialize(&NextStageId)) { return false; }

		return true;
	}

};

class QuestStageMaster
{

private:

	typedef TMap<u32, QuestStageItem> ItemMap;
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<QuestStageItem> GetAll() const;

	const QuestStageItem *Get(u32 Key, int32 SheetIndex = 0) const;

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef __QUESTSTAGEMASTER_H__
