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
	float X;
	float Y;
	

	PacketSpawnPlayer()
	{
	}

	PacketSpawnPlayer(u32 InUuid, s32 InHp, s32 InMaxHp, float InX, float InY)
	{
		Uuid = InUuid;
		Hp = InHp;
		MaxHp = InMaxHp;
		X = InX;
		Y = InY;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNPLAYER_H__
