#include "stdafx.h"
#include "CachePacketReceiver.h"
#include "CacheServerConnection.h"
#include "Packet/CachePacketLogInResult.h"
#include "ClientManager.h"

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


// ログイン結果を受信した。
void CachePacketReceiver::OnRecvLogInResult(MemoryStreamInterface *pStream)
{
	CachePacketLogInResult Packet;
	Packet.Serialize(pStream);

	ClientManager::GetInstance().Get(Packet.ClientId).lock()->RecvPacket(Packet.GetPacketID(), pStream);
}


// パケット受信関数を追加.
void CachePacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
