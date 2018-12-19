#ifndef __PACKETQUESTANPANKILL_H__
#define __PACKETQUESTANPANKILL_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketQuestAnpanKill  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::QuestAnpanKill; }

	

	u32 QuestId;
	

	PacketQuestAnpanKill()
	{
	}

	PacketQuestAnpanKill(u32 InQuestId)
	{
		QuestId = InQuestId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTANPANKILL_H__
