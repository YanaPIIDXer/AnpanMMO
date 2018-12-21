#ifndef __PACKETITEMADD_H__
#define __PACKETITEMADD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketItemAdd  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::ItemAdd; }

	

	u32 ItemId;
	u32 Count;
	

	PacketItemAdd()
	{
	}

	PacketItemAdd(u32 InItemId, u32 InCount)
	{
		ItemId = InItemId;
		Count = InCount;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMADD_H__
