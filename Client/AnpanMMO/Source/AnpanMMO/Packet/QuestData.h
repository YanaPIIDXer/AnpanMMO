#ifndef __QUESTDATA_H__
#define __QUESTDATA_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


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
	u32 State;
	

	QuestData()
	{
	}

	QuestData(u32 InQuestId, u32 InStageNo, u32 InState)
	{
		QuestId = InQuestId;
		StageNo = InStageNo;
		State = InState;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		pStream->Serialize(&StageNo);
		pStream->Serialize(&State);
		
		return true;
	}
};

#endif		// #ifndef __QUESTDATA_H__
