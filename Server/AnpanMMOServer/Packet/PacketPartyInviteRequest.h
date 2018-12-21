#ifndef __PACKETPARTYINVITEREQUEST_H__
#define __PACKETPARTYINVITEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketPartyInviteRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::PartyInviteRequest; }

	

	u32 TargetUuid;
	

	PacketPartyInviteRequest()
	{
	}

	PacketPartyInviteRequest(u32 InTargetUuid)
	{
		TargetUuid = InTargetUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TargetUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYINVITEREQUEST_H__
