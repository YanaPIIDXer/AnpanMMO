#ifndef __PACKETQUESTRETIREREQUEST_H__
#define __PACKETQUESTRETIREREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketQuestRetireRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::QuestRetireRequest; }

	

	u32 QuestId;
	

	PacketQuestRetireRequest()
	{
	}

	PacketQuestRetireRequest(u32 InQuestId)
	{
		QuestId = InQuestId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTRETIREREQUEST_H__
