#include "stdafx.h"
#include "WordCheckPacketReceiver.h"
#include "WordCheckServerConnection.h"
#include "ClientManager.h"
#include "Packet/WordCheckPacketChatResult.h"

// コンストラクタ
WordCheckPacketReceiver::WordCheckPacketReceiver(WordCheckServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(WordCheckChatResult, boost::bind(&WordCheckPacketReceiver::OnRecvChatWordCheckResult, this, _1));
}

// パケット受信.
void WordCheckPacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// チャットのワードチェック結果を受信した。
void WordCheckPacketReceiver::OnRecvChatWordCheckResult(MemoryStreamInterface *pStream)
{
	WordCheckPacketChatResult Packet;
	Packet.Serialize(pStream);

	ClientManager::GetInstance().Get(Packet.ClientId).lock()->RecvPacket(Packet.GetPacketID(), pStream);
}


// パケット受信関数を追加.
void WordCheckPacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
