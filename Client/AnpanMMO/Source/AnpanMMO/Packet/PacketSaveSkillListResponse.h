#ifndef __PACKETSAVESKILLLISTRESPONSE_H__
#define __PACKETSAVESKILLLISTRESPONSE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSaveSkillListResponse  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return SaveSkillListResponse; }

	enum ResultCode
	{
		Success,
		Error,
	};

	u8 Result;
	

	PacketSaveSkillListResponse()
	{
	}

	PacketSaveSkillListResponse(u8 InResult)
	{
		Result = InResult;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVESKILLLISTRESPONSE_H__
