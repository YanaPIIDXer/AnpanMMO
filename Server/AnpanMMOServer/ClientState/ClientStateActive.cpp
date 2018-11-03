#include "stdafx.h"
#include  "ClientStateActive.h"

// コンストラクタ
ClientStateActive::ClientStateActive(Client *pInParent)
	: ClientStateBase(pInParent)
{
}

// 開始時の処理.
void ClientStateActive::BeginState()
{
}

// パケット解析.
void ClientStateActive::AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream)
{

}
