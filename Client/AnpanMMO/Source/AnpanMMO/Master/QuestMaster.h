#ifndef __QUESTMASTER_H__
#define __QUESTMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct QuestItem
{

public:



	u32 Id;
	FString Name;
	u32 StartStageId;
	u32 RewardId;
	u32 NextQuestId;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&Id)) { return false; }
		std::string StrName;
		if(!pStream->Serialize(&StrName)) { return false; }
		Name = UTF8_TO_TCHAR(StrName.c_str());
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

public:

	void Load();

	TArray<QuestItem> GetAll() const;

	const QuestItem *Get(u32 Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef __QUESTMASTER_H__
