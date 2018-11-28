#include "stdafx.h"
#include "WordCheckPacketReceiver.h"
#include "WordCheckServerConnection.h"
#include "ClientManager.h"

// コンストラクタ
WordCheckPacketReceiver::WordCheckPacketReceiver(WordCheckServerConnection *pInParent)
	: pParent(pInParent)
{
}

// パケット受信.
void WordCheckPacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// パケット受信関数を追加.
void WordCheckPacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
