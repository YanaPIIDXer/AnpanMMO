#ifndef __PACKETSAVEITEMSHORTCUTREQUEST_H__
#define __PACKETSAVEITEMSHORTCUTREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSaveItemShortcutRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SaveItemShortcutRequest; }

	

	u32 ItemId1;
	u32 ItemId2;
	

	PacketSaveItemShortcutRequest()
	{
	}

	PacketSaveItemShortcutRequest(u32 InItemId1, u32 InItemId2)
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

#endif		// #ifndef __PACKETSAVEITEMSHORTCUTREQUEST_H__
