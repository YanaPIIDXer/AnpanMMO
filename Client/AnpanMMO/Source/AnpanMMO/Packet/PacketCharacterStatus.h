#ifndef __PACKETCHARACTERSTATUS_H__
#define __PACKETCHARACTERSTATUS_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketCharacterStatus  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return CharacterStatus; }

	

	u32 Uuid;
	std::string Name;
	u8 Job;
	s32 Hp;
	s32 MaxHp;
	s32 Atk;
	s32 Def;
	s32 Exp;
	u32 Gold;
	

	PacketCharacterStatus()
	{
	}

	PacketCharacterStatus(u32 InUuid, std::string InName, u8 InJob, s32 InHp, s32 InMaxHp, s32 InAtk, s32 InDef, s32 InExp, u32 InGold)
	{
		Uuid = InUuid;
		Name = InName;
		Job = InJob;
		Hp = InHp;
		MaxHp = InMaxHp;
		Atk = InAtk;
		Def = InDef;
		Exp = InExp;
		Gold = InGold;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&Name);
		pStream->Serialize(&Job);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Atk);
		pStream->Serialize(&Def);
		pStream->Serialize(&Exp);
		pStream->Serialize(&Gold);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCHARACTERSTATUS_H__
