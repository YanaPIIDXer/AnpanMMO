#ifndef __PACKETSPAWNPLAYER_H__
#define __PACKETSPAWNPLAYER_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PlayerData.h"


class PacketSpawnPlayer  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SpawnPlayer; }

	

	PlayerData Data;
	

	PacketSpawnPlayer()
	{
	}

	PacketSpawnPlayer(PlayerData InData)
	{
		Data = InData;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		Data.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNPLAYER_H__
