#ifndef __PACKETSAVEITEMSHORTCUTRESULT_H__
#define __PACKETSAVEITEMSHORTCUTRESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSaveItemShortcutResult  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::SaveItemShortcutResult; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	u32 ItemId1;
	u32 ItemId2;
	

	PacketSaveItemShortcutResult()
	{
	}

	PacketSaveItemShortcutResult(u8 InResult, u32 InItemId1, u32 InItemId2)
	{
		Result = InResult;
		ItemId1 = InItemId1;
		ItemId2 = InItemId2;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&ItemId1);
		pStream->Serialize(&ItemId2);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVEITEMSHORTCUTRESULT_H__
