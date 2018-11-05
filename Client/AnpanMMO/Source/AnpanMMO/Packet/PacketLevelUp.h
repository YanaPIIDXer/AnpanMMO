#ifndef __PACKETLEVELUP_H__
#define __PACKETLEVELUP_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketLevelUp  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return LevelUp; }

	

	s32 MaxHp;
	s32 Atk;
	s32 Def;
	s32 ResultExp;
	

	PacketLevelUp()
	{
	}

	PacketLevelUp(s32 InMaxHp, s32 InAtk, s32 InDef, s32 InResultExp)
	{
		MaxHp = InMaxHp;
		Atk = InAtk;
		Def = InDef;
		ResultExp = InResultExp;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Atk);
		pStream->Serialize(&Def);
		pStream->Serialize(&ResultExp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETLEVELUP_H__
