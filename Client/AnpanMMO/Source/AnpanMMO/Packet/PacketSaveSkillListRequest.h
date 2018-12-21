#ifndef __PACKETSAVESKILLLISTREQUEST_H__
#define __PACKETSAVESKILLLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketSaveSkillListRequest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SaveSkillListRequest; }

	

	u32 SkillId1;
	u32 SkillId2;
	u32 SkillId3;
	u32 SkillId4;
	

	PacketSaveSkillListRequest()
	{
	}

	PacketSaveSkillListRequest(u32 InSkillId1, u32 InSkillId2, u32 InSkillId3, u32 InSkillId4)
	{
		SkillId1 = InSkillId1;
		SkillId2 = InSkillId2;
		SkillId3 = InSkillId3;
		SkillId4 = InSkillId4;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId1);
		pStream->Serialize(&SkillId2);
		pStream->Serialize(&SkillId3);
		pStream->Serialize(&SkillId4);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVESKILLLISTREQUEST_H__
