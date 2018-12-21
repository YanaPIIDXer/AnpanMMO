#ifndef __PACKETITEMSHORTCUT_H__
#define __PACKETITEMSHORTCUT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketItemShortcut  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::ItemShortcut; }

	

	u32 ItemId1;
	u32 ItemId2;
	

	PacketItemShortcut()
	{
	}

	PacketItemShortcut(u32 InItemId1, u32 InItemId2)
	{
		ItemId1 = InItemId1;
		ItemId2 = InItemId2;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId1);
		pStream->Serialize(&ItemId2);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMSHORTCUT_H__
