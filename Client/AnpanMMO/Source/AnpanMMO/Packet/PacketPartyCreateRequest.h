#ifndef __PACKETPARTYCREATEREQUEST_H__
#define __PACKETPARTYCREATEREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketPartyCreateRequest  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyCreateRequest; }

	

	u32 MemberMax;
	

	PacketPartyCreateRequest()
	{
	}

	PacketPartyCreateRequest(u32 InMemberMax)
	{
		MemberMax = InMemberMax;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MemberMax);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYCREATEREQUEST_H__
