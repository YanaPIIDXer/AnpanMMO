#ifndef __PACKETITEMUSE_H__
#define __PACKETITEMUSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketItemUse  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::ItemUse; }

	

	u32 ItemId;
	

	PacketItemUse()
	{
	}

	PacketItemUse(u32 InItemId)
	{
		ItemId = InItemId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMUSE_H__
