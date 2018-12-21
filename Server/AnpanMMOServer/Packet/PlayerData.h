#ifndef __PLAYERDATA_H__
#define __PLAYERDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PlayerData 
{
public:
	

	

	u32 Uuid;
	float X;
	float Y;
	float Z;
	float Rotation;
	s32 Hp;
	s32 MaxHp;
	std::string Name;
	u8 Job;
	

	PlayerData()
	{
	}

	PlayerData(u32 InUuid, float InX, float InY, float InZ, float InRotation, s32 InHp, s32 InMaxHp, std::string InName, u8 InJob)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Z = InZ;
		Rotation = InRotation;
		Hp = InHp;
		MaxHp = InMaxHp;
		Name = InName;
		Job = InJob;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		pStream->Serialize(&Rotation);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Name);
		pStream->Serialize(&Job);
		
		return true;
	}
};

#endif		// #ifndef __PLAYERDATA_H__
