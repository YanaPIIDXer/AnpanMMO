#ifndef __PACKETADDEXP_H__
#define __PACKETADDEXP_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class PacketAddExp  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::AddExp; }

	

	s32 Exp;
	

	PacketAddExp()
	{
	}

	PacketAddExp(s32 InExp)
	{
		Exp = InExp;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Exp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETADDEXP_H__
