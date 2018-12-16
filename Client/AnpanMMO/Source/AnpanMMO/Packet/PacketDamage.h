#ifndef __PACKETDAMAGE_H__
#define __PACKETDAMAGE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketDamage  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::Damage; }

	

	u8 TargetType;
	u32 TargetUuid;
	s32 DamageValue;
	s32 ResultHp;
	

	PacketDamage()
	{
	}

	PacketDamage(u8 InTargetType, u32 InTargetUuid, s32 InDamageValue, s32 InResultHp)
	{
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		DamageValue = InDamageValue;
		ResultHp = InResultHp;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TargetType);
		pStream->Serialize(&TargetUuid);
		pStream->Serialize(&DamageValue);
		pStream->Serialize(&ResultHp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETDAMAGE_H__
