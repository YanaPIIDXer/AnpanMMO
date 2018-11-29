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

	u32 TargetUuid;
	u8 Response;
	

	PacketPartyInviteResponse()
	{
	}

	PacketPartyInviteResponse(u32 InTargetUuid, u8 InResponse)
	{
		TargetUuid = InTargetUuid;
		Response = InResponse;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TargetUuid);
		pStream->Serialize(&Response);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYINVITERESPONSE_H__
