#include "stdafx.h"
#include "ClientStateTitle.h"
#include "MemoryStream/MemoryStreamInterface.h"

// コンストラクタ
ClientStateTitle::ClientStateTitle(Client *pInParent)
	: ClientStateBase(pInParent)
{
}

// パケット解析.
void ClientStateTitle::AnalyzePacket(MemoryStreamInterface *pStream)
{

}
