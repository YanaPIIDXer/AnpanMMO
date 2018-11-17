#include "stdafx.h"
#include "PacketReceiver.h"
#include "GameServerConnection.h"
#include "DBConnection.h"
#include "Packet/CachePacketLogInRequest.h"
#include "Packet/CachePacketLogInResult.h"

// コンストラクタ
PacketReceiver::PacketReceiver(GameServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(CacheLogInRequest, bind(&PacketReceiver::OnRecvLogInRequest, this, _1));
}

// ログインリクエストを受信した。
void PacketReceiver::OnRecvLogInRequest(MemoryStreamInterface *pStream)
{
	CachePacketLogInRequest Packet;
	Packet.Serialize(pStream);

	u8 ResultCode = CachePacketLogInResult::Success;
	char *pUserCode = const_cast<char *>(Packet.UserCode.c_str());
	int Id = 0;
	if (!DBConnection::GetInstance().LoadUserData(pUserCode, Id))
	{
		ResultCode = CachePacketLogInResult::Error;
	}

	CachePacketLogInResult ResultPacket(Packet.ClientId, ResultCode, Id);
	pParent->SendPacket(&ResultPacket);
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
