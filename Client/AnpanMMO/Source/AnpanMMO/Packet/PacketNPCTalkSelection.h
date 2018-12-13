#ifndef __PACKETNPCTALKSELECTION_H__
#define __PACKETNPCTALKSELECTION_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketNPCTalkSelection  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return NPCTalkSelection; }

	

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
