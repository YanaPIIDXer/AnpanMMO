#ifndef __PACKETITEMLIST_H__
#define __PACKETITEMLIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ItemData.h"
#include "FlexArray.h"
#include "PacketID.h"


class PacketItemList  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::ItemList; }

	

	FlexArray<ItemData> Items;
	

	PacketItemList()
	{
	}

	PacketItemList(FlexArray<ItemData> InItems)
	{
		Items = InItems;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		Items.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMLIST_H__
