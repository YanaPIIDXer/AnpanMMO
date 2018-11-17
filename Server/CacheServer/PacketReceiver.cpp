#include "stdafx.h"
#include "PacketReceiver.h"
#include "GameServerConnection.h"

// コンストラクタ
PacketReceiver::PacketReceiver(GameServerConnection *pInParent)
	: pParent(pInParent)
{
}

// パケット受信.
void PacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// パケット受信関数を追加.
void PacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
