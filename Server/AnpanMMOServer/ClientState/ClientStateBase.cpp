#include "stdafx.h"
#include "ClientStateBase.h"

// パケット解析.
void ClientStateBase::AnalyzePacket(u8 ID, MemoryStreamInterface *pStream)
{
	FunctionMap::iterator It = PacketFunctions.find(ID);
	if(It != PacketFunctions.end())
	{
		It->second(pParent, pStream);
	}
}
