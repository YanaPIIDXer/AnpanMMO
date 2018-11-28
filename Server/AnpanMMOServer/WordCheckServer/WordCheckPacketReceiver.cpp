#include "stdafx.h"
#include "WordCheckPacketReceiver.h"
#include "WordCheckServerConnection.h"
#include "ClientManager.h"
#include "Packet/WordCheckPacketChatResult.h"

// �R���X�g���N�^
WordCheckPacketReceiver::WordCheckPacketReceiver(WordCheckServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(WordCheckChatResult, boost::bind(&WordCheckPacketReceiver::OnRecvChatWordCheckResult, this, _1));
}

// �p�P�b�g��M.
void WordCheckPacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// �`���b�g�̃��[�h�`�F�b�N���ʂ���M�����B
void WordCheckPacketReceiver::OnRecvChatWordCheckResult(MemoryStreamInterface *pStream)
{
	WordCheckPacketChatResult Packet;
	Packet.Serialize(pStream);

	ClientManager::GetInstance().Get(Packet.ClientId).lock()->RecvPacket(Packet.GetPacketID(), pStream);
}


// �p�P�b�g��M�֐���ǉ�.
void WordCheckPacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
