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
	if (!PacketFuncs[ID](pStream))
	{
		std::cout << "PacketID:" << (int)ID << " Serialize Failed..." << std::endl;
	}
}


// チャットのワードチェック要求を受信した。
bool PacketReceiver::OnRecvChatWordCheckRequest(MemoryStreamInterface *pStream)
{
	WordCheckPacketChatRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	std::string ResultMessage = WordChecker::GetInstance().ChatWordCheck(Packet.Message);
	WordCheckPacketChatResult ResultPacket(Packet.ClientId, Packet.Type, ResultMessage);
	pParent->SendPacket(&ResultPacket);

	return true;
}


// パケット受信関数を追加.
void PacketReceiver::AddPacketFunc(u8 ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
