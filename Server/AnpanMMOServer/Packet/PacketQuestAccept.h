#ifndef __PACKETQUESTACCEPT_H__
#define __PACKETQUESTACCEPT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketQuestAccept  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::QuestAccept; }

	

	u32 QuestId;
	

	PacketQuestAccept()
	{
	}

	PacketQuestAccept(u32 InQuestId)
	{
		QuestId = InQuestId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTACCEPT_H__
