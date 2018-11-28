#include "stdafx.h"
#include "PacketReceiver.h"
#include "GameServerConnection.h"
#include "Packet/WordCheckPacketChatRequest.h"
#include "Packet/WordCheckPacketChatResult.h"

// �R���X�g���N�^
PacketReceiver::PacketReceiver(GameServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(WordCheckChatRequest, boost::bind(&PacketReceiver::OnRecvChatWordCheckRequest, this, _1));
}


// �p�P�b�g��M.
void PacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// �`���b�g�̃��[�h�`�F�b�N�v������M�����B
void PacketReceiver::OnRecvChatWordCheckRequest(MemoryStreamInterface *pStream)
{
	WordCheckPacketChatRequest Packet;
	Packet.Serialize(pStream);

	std::string ResultMessage = Packet.Message;
	std::string ReplaceWord = "fuck";
	u32 Index = ResultMessage.find(ReplaceWord);
	if (Index != std::string::npos)
	{
		ResultMessage = ResultMessage.replace(Index, ReplaceWord.length(), "****");
	}

	WordCheckPacketChatResult ResultPacket(Packet.ClientId, Packet.Type, ResultMessage);
	pParent->SendPacket(&ResultPacket);
}


// �p�P�b�g��M�֐���ǉ�.
void PacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
