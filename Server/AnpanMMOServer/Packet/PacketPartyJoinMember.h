#ifndef __PACKETPARTYJOINMEMBER_H__
#define __PACKETPARTYJOINMEMBER_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PartyMemberData.h"
#include "FlexArray.h"


class PacketPartyJoinMember  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyJoinMember; }

	

	FlexArray<PartyMemberData> MemberList;
	

	PacketPartyJoinMember()
	{
	}

	PacketPartyJoinMember(FlexArray<PartyMemberData> InMemberList)
	{
		MemberList = InMemberList;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		MemberList.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYJOINMEMBER_H__
