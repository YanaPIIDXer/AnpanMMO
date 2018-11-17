#include "stdafx.h"
#include "CachePacketReceiver.h"
#include "CacheServerConnection.h"

// コンストラクタ
CachePacketReceiver::CachePacketReceiver(CacheServerConnection *pInParent)
	: pParent(pInParent)
{
}

// パケット受信.
void CachePacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// パケット受信関数を追加.
void CachePacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
