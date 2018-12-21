#ifndef __PACKETSPAWNANPAN_H__
#define __PACKETSPAWNANPAN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "AnpanData.h"
#include "PacketID.h"


class PacketSpawnAnpan  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SpawnAnpan; }

	

	AnpanData Data;
	

	PacketSpawnAnpan()
	{
	}

	PacketSpawnAnpan(AnpanData InData)
	{
		Data = InData;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		Data.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNANPAN_H__
