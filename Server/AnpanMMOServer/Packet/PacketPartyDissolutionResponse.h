#ifndef __PACKETPARTYDISSOLUTIONRESPONSE_H__
#define __PACKETPARTYDISSOLUTIONRESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyDissolutionResponse  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyDissolutionResponse; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	

	PacketPartyDissolutionResponse()
	{
	}

	PacketPartyDissolutionResponse(u8 InResult)
	{
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYDISSOLUTIONRESPONSE_H__
