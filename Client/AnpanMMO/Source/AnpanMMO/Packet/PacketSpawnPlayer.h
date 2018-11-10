#ifndef __PACKETSPAWNPLAYER_H__
#define __PACKETSPAWNPLAYER_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSpawnPlayer  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return SpawnPlayer; }

	

	u32 Uuid;
	s32 Hp;
	s32 MaxHp;
	

	PacketSpawnPlayer()
	{
	}

	PacketSpawnPlayer(u32 InUuid, s32 InHp, s32 InMaxHp)
	{
		Uuid = InUuid;
		Hp = InHp;
		MaxHp = InMaxHp;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNPLAYER_H__
