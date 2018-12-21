#ifndef __PACKETPARTYINVITERESULT_H__
#define __PACKETPARTYINVITERESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketPartyInviteResult  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::PartyInviteResult; }

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
