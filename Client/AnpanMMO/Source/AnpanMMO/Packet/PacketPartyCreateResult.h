#ifndef __PACKETPARTYCREATERESULT_H__
#define __PACKETPARTYCREATERESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyCreateResult  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyCreateResult; }

	enum ResultCode
	{
		Success,
		AlreadyJoin,
		Error,
	};

	u8 Result;
	u32 PartyId;
	

	PacketPartyCreateResult()
	{
	}

	PacketPartyCreateResult(u8 InResult, u32 InPartyId)
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

#endif		// #ifndef __PACKETPARTYCREATERESULT_H__
