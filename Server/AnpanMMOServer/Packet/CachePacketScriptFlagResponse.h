#ifndef __CACHEPACKETSCRIPTFLAGRESPONSE_H__
#define __CACHEPACKETSCRIPTFLAGRESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class CachePacketScriptFlagResponse  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheScriptFlagResponse; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	u32 BitField1;
	u32 BitField2;
	u32 BitField3;
	

	CachePacketScriptFlagResponse()
	{
	}

	CachePacketScriptFlagResponse(u32 InClientId, u8 InResult, u32 InBitField1, u32 InBitField2, u32 InBitField3)
	{
		ClientId = InClientId;
		Result = InResult;
		BitField1 = InBitField1;
		BitField2 = InBitField2;
		BitField3 = InBitField3;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		pStream->Serialize(&BitField1);
		pStream->Serialize(&BitField2);
		pStream->Serialize(&BitField3);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSCRIPTFLAGRESPONSE_H__
