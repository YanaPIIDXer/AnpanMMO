#ifndef __QUESTREWARDMASTER_H__
#define __QUESTREWARDMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct QuestRewardItem
{

public:

	enum
	{
		NONE = 0,
		ITEM = 1,
		GOLD = 2,
	};


	u32 ID;
	u8 Type;
	u32 ItemId;
	u32 Count;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		if(!pStream->Serialize(&Type)) { return false; }
		if(!pStream->Serialize(&ItemId)) { return false; }
		if(!pStream->Serialize(&Count)) { return false; }

		return true;
	}

};

class QuestRewardMaster
{

private:

	typedef TMap<u32, QuestRewardItem> ItemMap;

public:

	void Load();

	TArray<QuestRewardItem> GetAll() const;

	const QuestRewardItem *Get(u32 Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef __QUESTREWARDMASTER_H__
