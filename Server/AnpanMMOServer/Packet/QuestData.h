#ifndef __QUESTDATA_H__
#define __QUESTDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class QuestData 
{
public:
	

	enum StateType
	{
		Active,
		Cleared,
	};

	u32 QuestId;
	u32 StageNo;
	u32 KillCount;
	u8 State;
	

	QuestData()
	{
	}

	QuestData(u32 InQuestId, u32 InStageNo, u32 InKillCount, u8 InState)
	{
		QuestId = InQuestId;
		StageNo = InStageNo;
		KillCount = InKillCount;
		State = InState;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		pStream->Serialize(&StageNo);
		pStream->Serialize(&KillCount);
		pStream->Serialize(&State);
		
		return true;
	}
};

#endif		// #ifndef __QUESTDATA_H__
