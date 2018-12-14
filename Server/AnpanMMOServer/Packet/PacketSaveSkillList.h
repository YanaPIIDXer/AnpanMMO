#ifndef __PACKETSAVESKILLLIST_H__
#define __PACKETSAVESKILLLIST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSaveSkillList  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return SaveSkillList; }

	

	u32 Skill1;
	u32 Skill2;
	u32 Skill3;
	u32 Skill4;
	

	PacketSaveSkillList()
	{
	}

	PacketSaveSkillList(u32 InSkill1, u32 InSkill2, u32 InSkill3, u32 InSkill4)
	{
		Skill1 = InSkill1;
		Skill2 = InSkill2;
		Skill3 = InSkill3;
		Skill4 = InSkill4;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Skill1);
		pStream->Serialize(&Skill2);
		pStream->Serialize(&Skill3);
		pStream->Serialize(&Skill4);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVESKILLLIST_H__
