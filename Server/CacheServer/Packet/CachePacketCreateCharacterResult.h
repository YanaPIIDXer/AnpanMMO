#ifndef __CACHEPACKETCREATECHARACTERRESULT_H__
#define __CACHEPACKETCREATECHARACTERRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


class CachePacketCreateCharacterResult  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return CachePacketID::CacheCreateCharacterResult; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	

	CachePacketCreateCharacterResult()
	{
	}

	CachePacketCreateCharacterResult(u32 InClientId, u8 InResult)
	{
		ClientId = InClientId;
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCREATECHARACTERRESULT_H__
