#ifndef __PACKETSCRIPTFLAG_H__
#define __PACKETSCRIPTFLAG_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketScriptFlag  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::ScriptFlag; }

	

	u32 BitField1;
	u32 BitField2;
	u32 BitField3;
	

	PacketScriptFlag()
	{
	}

	PacketScriptFlag(u32 InBitField1, u32 InBitField2, u32 InBitField3)
	{
		BitField1 = InBitField1;
		BitField2 = InBitField2;
		BitField3 = InBitField3;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&BitField1);
		pStream->Serialize(&BitField2);
		pStream->Serialize(&BitField3);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSCRIPTFLAG_H__
