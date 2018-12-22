#include "stdafx.h"
#include "PacketReceiver.h"
#include "GameServerConnection.h"
#include "WordChecker.h"
#include "Packet/WordCheckPacketChatRequest.h"
#include "Packet/WordCheckPacketChatResult.h"

// �R���X�g���N�^
PacketReceiver::PacketReceiver(GameServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(WordCheckPacketID::WordCheckChatRequest, boost::bind(&PacketReceiver::OnRecvChatWordCheckRequest, this, _1));
}


// �p�P�b�g��M.
void PacketReceiver::RecvPacket(u8 ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	if (!PacketFuncs[ID](pStream))
	{
		std::cout << "PacketID:" << (int)ID << " Serialize Failed..." << std::endl;
	}
}


// �`���b�g�̃��[�h�`�F�b�N�v������M�����B
bool PacketReceiver::OnRecvChatWordCheckRequest(MemoryStreamInterface *pStream)
{
	WordCheckPacketChatRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	std::string ResultMessage = WordChecker::GetInstance().ChatWordCheck(Packet.Message);
	WordCheckPacketChatResult ResultPacket(Packet.ClientId, Packet.Type, ResultMessage);
	pParent->SendPacket(&ResultPacket);

	return true;
}


// �p�P�b�g��M�֐���ǉ�.
void PacketReceiver::AddPacketFunc(u8 ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
