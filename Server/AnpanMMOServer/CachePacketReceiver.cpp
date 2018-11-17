#include "stdafx.h"
#include "CachePacketReceiver.h"
#include "CacheServerConnection.h"
#include "Packet/CachePacketLogInResult.h"
#include "ClientManager.h"

// �R���X�g���N�^
CachePacketReceiver::CachePacketReceiver(CacheServerConnection *pInParent)
	: pParent(pInParent)
{
}

// �p�P�b�g��M.
void CachePacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// ���O�C�����ʂ���M�����B
void CachePacketReceiver::OnRecvLogInResult(MemoryStreamInterface *pStream)
{
	CachePacketLogInResult Packet;
	Packet.Serialize(pStream);

	ClientManager::GetInstance().Get(Packet.ClientId).lock()->RecvPacket(Packet.GetPacketID(), pStream);
}


// �p�P�b�g��M�֐���ǉ�.
void CachePacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
