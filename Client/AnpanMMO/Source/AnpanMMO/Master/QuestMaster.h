#ifndef __QUESTMASTER_H__
#define __QUESTMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct QuestItem
{

public:

	enum
	{
		MAIN_QUEST = 0,
		SUB_QUEST = 1,
	};


	u32 Id;
	FString Name;
	FString Explain;
	u8 Type;
	u32 StartStageId;
	u32 RewardId;
	u32 NextQuestId;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&Id)) { return false; }
		std::string StrName;
		if(!pStream->Serialize(&StrName)) { return false; }
		Name = UTF8_TO_TCHAR(StrName.c_str());
		std::string StrExplain;
		if(!pStream->Serialize(&StrExplain)) { return false; }
		Explain = UTF8_TO_TCHAR(StrExplain.c_str());
		if(!pStream->Serialize(&Type)) { return false; }
		if(!pStream->Serialize(&StartStageId)) { return false; }
		if(!pStream->Serialize(&RewardId)) { return false; }
		if(!pStream->Serialize(&NextQuestId)) { return false; }

		return true;
	}

};

class QuestMaster
{

private:

	typedef TMap<u32, QuestItem> ItemMap;
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<QuestItem> GetAllSheetItem(int32 SheetIndex) const;

	TArray<QuestItem> GetAll() const;

	const QuestItem *Get(u32 Key, int32 SheetIndex = 0) const;

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef __QUESTMASTER_H__
