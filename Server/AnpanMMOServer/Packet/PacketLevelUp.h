#ifndef __PACKETLEVELUP_H__
#define __PACKETLEVELUP_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketLevelUp  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::LevelUp; }

	

	u32 Level;
	s32 MaxHp;
	s32 Atk;
	s32 Def;
	s32 ResultExp;
	

	PacketLevelUp()
	{
	}

	PacketLevelUp(u32 InLevel, s32 InMaxHp, s32 InAtk, s32 InDef, s32 InResultExp)
	{
		Level = InLevel;
		MaxHp = InMaxHp;
		Atk = InAtk;
		Def = InDef;
		ResultExp = InResultExp;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Level);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Atk);
		pStream->Serialize(&Def);
		pStream->Serialize(&ResultExp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETLEVELUP_H__
