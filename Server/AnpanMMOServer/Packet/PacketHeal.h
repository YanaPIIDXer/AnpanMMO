#ifndef __PACKETHEAL_H__
#define __PACKETHEAL_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketHeal  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::Heal; }

	

	u8 TargetType;
	u32 TargetUuid;
	s32 HealValue;
	s32 ResultHp;
	

	PacketHeal()
	{
	}

	PacketHeal(u8 InTargetType, u32 InTargetUuid, s32 InHealValue, s32 InResultHp)
	{
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		HealValue = InHealValue;
		ResultHp = InResultHp;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TargetType);
		pStream->Serialize(&TargetUuid);
		pStream->Serialize(&HealValue);
		pStream->Serialize(&ResultHp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETHEAL_H__
