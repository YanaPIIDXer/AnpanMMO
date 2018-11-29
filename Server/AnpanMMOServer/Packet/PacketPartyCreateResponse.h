#ifndef __PACKETPARTYCREATERESPONSE_H__
#define __PACKETPARTYCREATERESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyCreateResponse  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyCreateResponse; }

	enum ResultCode
	{
		Success,
		AlreadyJoin,
		Error,
	};

	u8 Result;
	u32 PartyId;
	

	PacketPartyCreateResponse()
	{
	}

	PacketPartyCreateResponse(u8 InResult, u32 InPartyId)
	{
		Result = InResult;
		PartyId = InPartyId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&PartyId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYCREATERESPONSE_H__
