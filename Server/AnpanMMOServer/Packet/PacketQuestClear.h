#ifndef __PACKETQUESTCLEAR_H__
#define __PACKETQUESTCLEAR_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketQuestClear  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::QuestClear; }

	

	u32 QuestId;
	

	PacketQuestClear()
	{
	}

	PacketQuestClear(u32 InQuestId)
	{
		QuestId = InQuestId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTCLEAR_H__
