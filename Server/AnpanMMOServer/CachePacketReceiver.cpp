#include "stdafx.h"
#include "CachePacketReceiver.h"
#include "CacheServerConnection.h"
#include "ClientManager.h"
#include "Packet/CachePacketLogInResult.h"
#include "Packet/CachePacketCharacterDataResult.h"

// コンストラクタ
CachePacketReceiver::CachePacketReceiver(CacheServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(CacheLogInResult, bind(&CachePacketReceiver::OnRecvLogInResult, this, _1));
	AddPacketFunc(CacheCharacterDataResult, bind(&CachePacketReceiver::OnRecvCharacterDataResult, this, _1));
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

// キャラクタ情報の結果を受信した。
void CachePacketReceiver::OnRecvCharacterDataResult(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataResult Packet;
	Packet.Serialize(pStream);

	ClientManager::GetInstance().Get(Packet.ClientId).lock()->RecvPacket(Packet.GetPacketID(), pStream);
}


// パケット受信関数を追加.
void CachePacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
