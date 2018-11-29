#ifndef __PACKETPARTYINVITERESULT_H__
#define __PACKETPARTYINVITERESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyInviteResult  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyInviteResult; }

	enum ResultCode
	{
		Success,
		AlreadyJoinOtherParty,
		Error,
	};

	u8 Result;
	

	PacketPartyInviteResult()
	{
	}

	PacketPartyInviteResult(u8 InResult)
	{
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYINVITERESULT_H__
