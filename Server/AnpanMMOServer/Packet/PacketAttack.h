#ifndef __PACKETATTACK_H__
#define __PACKETATTACK_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketAttack  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return Attack; }

	

	u32 TargetUuid;
	

	PacketAttack()
	{
	}

	PacketAttack(u32 InTargetUuid)
	{
		TargetUuid = InTargetUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TargetUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETATTACK_H__
