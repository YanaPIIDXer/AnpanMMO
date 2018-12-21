#ifndef __PACKETQUESTSTAGECHANGE_H__
#define __PACKETQUESTSTAGECHANGE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketQuestStageChange  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::QuestStageChange; }

	

	u32 QuestId;
	u32 StageNo;
	

	PacketQuestStageChange()
	{
	}

	PacketQuestStageChange(u32 InQuestId, u32 InStageNo)
	{
		QuestId = InQuestId;
		StageNo = InStageNo;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		pStream->Serialize(&StageNo);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTSTAGECHANGE_H__
