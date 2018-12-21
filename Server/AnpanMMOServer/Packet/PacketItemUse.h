#ifndef __PACKETITEMUSE_H__
#define __PACKETITEMUSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketItemUse  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::ItemUse; }

	

	u32 ItemId;
	u8 TargetType;
	u32 TargetUuid;
	

	PacketItemUse()
	{
	}

	PacketItemUse(u32 InItemId, u8 InTargetType, u32 InTargetUuid)
	{
		ItemId = InItemId;
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId);
		pStream->Serialize(&TargetType);
		pStream->Serialize(&TargetUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMUSE_H__
