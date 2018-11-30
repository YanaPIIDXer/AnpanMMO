#ifndef __PACKETPARTYINVITERESPONSE_H__
#define __PACKETPARTYINVITERESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyInviteResponse  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyInviteResponse; }

	enum ResponseCode
	{
		Accept,
		Refuse,
	};

	u32 CustomerId;
	u8 Response;
	

	PacketPartyInviteResponse()
	{
	}

	PacketPartyInviteResponse(u32 InCustomerId, u8 InResponse)
	{
		CustomerId = InCustomerId;
		Response = InResponse;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&Response);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYINVITERESPONSE_H__
