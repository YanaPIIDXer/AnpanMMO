#ifndef __PACKETITEMSUBTRACT_H__
#define __PACKETITEMSUBTRACT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketItemSubtract  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::ItemSubtract; }

	

	u32 ItemId;
	u32 Count;
	

	PacketItemSubtract()
	{
	}

	PacketItemSubtract(u32 InItemId, u32 InCount)
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

#endif		// #ifndef __PACKETITEMSUBTRACT_H__
