#include "stdafx.h"
#include "ClientStateBase.h"

// パケット解析.
void ClientStateBase::AnalyzePacket(u8 ID, MemoryStreamInterface *pStream)
{
	FunctionMap::iterator It = PacketFunctions.find(ID);
	if(It != PacketFunctions.end())
	{
		if (!It->second(pParent, pStream))
		{
			std::cout << "PacketID:" << (int)ID << " Serialize Error!" << std::endl;
		}
	}
}
