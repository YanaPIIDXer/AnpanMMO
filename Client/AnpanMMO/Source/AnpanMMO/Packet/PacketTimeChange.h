#ifndef __PACKETTIMECHANGE_H__
#define __PACKETTIMECHANGE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketTimeChange  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return TimeChange; }

	

	u32 MasterId;
	

	PacketTimeChange()
	{
	}

	PacketTimeChange(u32 InMasterId)
	{
		MasterId = InMasterId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MasterId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETTIMECHANGE_H__
