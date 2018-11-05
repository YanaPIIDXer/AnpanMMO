#include "stdafx.h"
#include "ClientStateBase.h"

// �p�P�b�g���.
void ClientStateBase::AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream)
{
	FunctionMap::iterator It = PacketFunctions.find(ID);
	if(It != PacketFunctions.end())
	{
		It->second(pParent, pStream);
	}
}
