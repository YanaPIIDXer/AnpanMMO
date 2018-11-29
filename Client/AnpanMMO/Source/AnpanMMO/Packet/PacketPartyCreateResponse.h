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
	

	PacketPartyCreateResponse()
	{
	}

	PacketPartyCreateResponse(u8 InResult)
	{
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYCREATERESPONSE_H__
