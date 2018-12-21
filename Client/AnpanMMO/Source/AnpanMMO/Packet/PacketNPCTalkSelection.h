#ifndef __PACKETNPCTALKSELECTION_H__
#define __PACKETNPCTALKSELECTION_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketNPCTalkSelection  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::NPCTalkSelection; }

	

	s32 Index;
	

	PacketNPCTalkSelection()
	{
	}

	PacketNPCTalkSelection(s32 InIndex)
	{
		Index = InIndex;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Index);
		
		return true;
	}
};

#endif		// #ifndef __PACKETNPCTALKSELECTION_H__
