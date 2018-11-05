#ifndef __PACKETDAMAGE_H__
#define __PACKETDAMAGE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketDamage  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return Damage; }

	enum DamageTypePlayer
	{
		,
	};enum DamageTypeEnemy
	{
		,
	};

	u32 TargetUuid;
	s32 DamageValue;
	s32 ResultHp;
	

	PacketDamage()
	{
	}

	PacketDamage(u32 InTargetUuid, s32 InDamageValue, s32 InResultHp)
	{
		TargetUuid = InTargetUuid;
		DamageValue = InDamageValue;
		ResultHp = InResultHp;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TargetUuid);
		pStream->Serialize(&DamageValue);
		pStream->Serialize(&ResultHp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETDAMAGE_H__
