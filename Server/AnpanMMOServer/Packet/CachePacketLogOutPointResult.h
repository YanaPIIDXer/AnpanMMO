#ifndef __CACHEPACKETLOGOUTPOINTRESULT_H__
#define __CACHEPACKETLOGOUTPOINTRESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "CachePacketBase.h"


class CachePacketLogOutPointResult  : public CachePacketBase
{
public:
	virtual PacketID GetPacketID() const { return CacheLogOutPointResult; }

	

	u32 AreaId;
	float X;
	float Y;
	

	CachePacketLogOutPointResult()
	{
	}

	CachePacketLogOutPointResult(u32 InClientId, u32 InAreaId, float InX, float InY)
	{
		ClientId = InClientId;
		AreaId = InAreaId;
		X = InX;
		Y = InY;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		CachePacketBase::Serialize(pStream);
		pStream->Serialize(&AreaId);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGOUTPOINTRESULT_H__
