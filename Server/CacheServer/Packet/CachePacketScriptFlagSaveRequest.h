#ifndef __CACHEPACKETSCRIPTFLAGSAVEREQUEST_H__
#define __CACHEPACKETSCRIPTFLAGSAVEREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketScriptFlagSaveRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::CacheScriptFlagSaveRequest; }

	

	u32 CharacterId;
	u32 BitField1;
	u32 BitField2;
	u32 BitField3;
	

	CachePacketScriptFlagSaveRequest()
	{
	}

	CachePacketScriptFlagSaveRequest(u32 InClientId, u32 InCharacterId, u32 InBitField1, u32 InBitField2, u32 InBitField3)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		BitField1 = InBitField1;
		BitField2 = InBitField2;
		BitField3 = InBitField3;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&BitField1);
		pStream->Serialize(&BitField2);
		pStream->Serialize(&BitField3);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSCRIPTFLAGSAVEREQUEST_H__
