#ifndef __PACKETPARTYJOIN_H__
#define __PACKETPARTYJOIN_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PartyMemberData.h"
#include "FlexArray.h"


class PacketPartyJoin  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PartyJoin; }

	

	u32 Uuid;
	FlexArray<PartyMemberData> MemberList;
	

	PacketPartyJoin()
	{
	}

	PacketPartyJoin(u32 InUuid, FlexArray<PartyMemberData> InMemberList)
	{
		Uuid = InUuid;
		MemberList = InMemberList;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		MemberList.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYJOIN_H__
