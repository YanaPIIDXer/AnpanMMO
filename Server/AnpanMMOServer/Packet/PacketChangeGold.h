#ifndef __PACKETCHANGEGOLD_H__
#define __PACKETCHANGEGOLD_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketChangeGold  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::ChangeGold; }

	

	u32 Gold;
	

	PacketChangeGold()
	{
	}

	PacketChangeGold(u32 InGold)
	{
		Gold = InGold;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Gold);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCHANGEGOLD_H__
