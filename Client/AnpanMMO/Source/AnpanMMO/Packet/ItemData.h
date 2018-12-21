#ifndef __ITEMDATA_H__
#define __ITEMDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class ItemData 
{
public:
	

	

	u32 ItemId;
	u32 Count;
	

	ItemData()
	{
	}

	ItemData(u32 InItemId, u32 InCount)
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

#endif		// #ifndef __ITEMDATA_H__
