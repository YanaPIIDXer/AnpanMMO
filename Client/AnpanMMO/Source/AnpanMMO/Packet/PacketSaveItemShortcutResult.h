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
	

	PacketSaveItemShortcutResult()
	{
	}

	PacketSaveItemShortcutResult(u8 InResult)
	{
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVEITEMSHORTCUTRESULT_H__
