#ifndef __PACKETPARTYMEMBERLIST_H__
#define __PACKETPARTYMEMBERLIST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PartyMemberData.h"
#include "FlexArray.h"


class PacketPartyMemberList  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return PartyMemberLIst; }

	

	FlexArray<PartyMemberData> MemberList;
	

	PacketPartyMemberList()
	{
	}

	PacketPartyMemberList(FlexArray<PartyMemberData> InMemberList)
	{
		MemberList = InMemberList;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		MemberList.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYMEMBERLIST_H__
