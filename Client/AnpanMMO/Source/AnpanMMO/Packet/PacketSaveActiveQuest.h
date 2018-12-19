#ifndef __PACKETSAVEACTIVEQUEST_H__
#define __PACKETSAVEACTIVEQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSaveActiveQuest  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SaveActiveQuest; }

	

	u32 QuestId;
	

	PacketSaveActiveQuest()
	{
	}

	PacketSaveActiveQuest(u32 InQuestId)
	{
		QuestId = InQuestId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVEACTIVEQUEST_H__
