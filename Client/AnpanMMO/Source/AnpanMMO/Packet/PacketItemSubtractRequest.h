#ifndef __PACKETITEMSUBTRACTREQUEST_H__
#define __PACKETITEMSUBTRACTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketItemSubtractRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::ItemSubtractRequest; }

	

	u32 ItemId;
	u32 Count;
	

	PacketItemSubtractRequest()
	{
	}

	PacketItemSubtractRequest(u32 InItemId, u32 InCount)
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

#endif		// #ifndef __PACKETITEMSUBTRACTREQUEST_H__
