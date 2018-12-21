#ifndef __PACKETQUESTRETIRERESPONSE_H__
#define __PACKETQUESTRETIRERESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketQuestRetireResponse  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::QuestRetireResponse; }

	enum ResultCode
	{
		Success,
		MainQuest,
		Error,
	};

	u32 QuestId;
	u8 Result;
	

	PacketQuestRetireResponse()
	{
	}

	PacketQuestRetireResponse(u32 InQuestId, u8 InResult)
	{
		QuestId = InQuestId;
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTRETIRERESPONSE_H__
