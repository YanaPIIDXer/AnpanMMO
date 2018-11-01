#include "stdafx.h"
#include "ClientStateTitle.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInRequest.h"

// コンストラクタ
ClientStateTitle::ClientStateTitle(Client *pInParent)
	: ClientStateBase(pInParent)
{
}

// パケット解析.
void ClientStateTitle::AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream)
{

}
