#ifndef __PACKETPARTYJOINMEMBER_H__
#define __PACKETPARTYJOINMEMBER_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PartyMemberData.h"


class PacketPartyJoinMember  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PartyJoinMember; }

	

	PartyMemberData MemberData;
	

	PacketPartyJoinMember()
	{
	}

	PacketPartyJoinMember(PartyMemberData InMemberData)
	{
		MemberData = InMemberData;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		MemberData.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYJOINMEMBER_H__
