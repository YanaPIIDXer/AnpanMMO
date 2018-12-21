#ifndef __PACKETPARTYCREATERESULT_H__
#define __PACKETPARTYCREATERESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketPartyCreateResult  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::PartyCreateResult; }

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
