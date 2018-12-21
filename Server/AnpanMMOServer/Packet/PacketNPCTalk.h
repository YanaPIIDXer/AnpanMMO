#ifndef __PACKETNPCTALK_H__
#define __PACKETNPCTALK_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketNPCTalk  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::NPCTalk; }

	

	u32 MasterId;
	

	PacketNPCTalk()
	{
	}

	PacketNPCTalk(u32 InMasterId)
	{
		MasterId = InMasterId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MasterId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETNPCTALK_H__
