#include "stdafx.h"
#include "PacketReceiver.h"
#include "GameServerConnection.h"
#include "WordChecker.h"
#include "Packet/WordCheckPacketChatRequest.h"
#include "Packet/WordCheckPacketChatResult.h"

// コンストラクタ
PacketReceiver::PacketReceiver(GameServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(WordCheckPacketID::WordCheckChatRequest, boost::bind(&PacketReceiver::OnRecvChatWordCheckRequest, this, _1));
}


// パケット受信.
void PacketReceiver::RecvPacket(u8 ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// チャットのワードチェック要求を受信した。
void PacketReceiver::OnRecvChatWordCheckRequest(MemoryStreamInterface *pStream)
{
	WordCheckPacketChatRequest Packet;
	Packet.Serialize(pStream);

	std::string ResultMessage = WordChecker::GetInstance().ChatWordCheck(Packet.Message);
	WordCheckPacketChatResult ResultPacket(Packet.ClientId, Packet.Type, ResultMessage);
	pParent->SendPacket(&ResultPacket);
}


// パケット受信関数を追加.
void PacketReceiver::AddPacketFunc(u8 ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
