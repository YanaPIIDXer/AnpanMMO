#include "stdafx.h"
#include "CachePacketReceiver.h"
#include "CacheServerConnection.h"
#include "ClientManager.h"
#include "Packet/CachePacketLogInResult.h"
#include "Packet/CachePacketCreateCharacterResult.h"
#include "Packet/CachePacketCharacterDataResult.h"
#include "Packet/CachePacketScriptFlagResponse.h"

// �R���X�g���N�^
CachePacketReceiver::CachePacketReceiver(CacheServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(CacheLogInResult, bind(&CachePacketReceiver::OnRecvLogInResult, this, _1));
	AddPacketFunc(CacheCreateCharacterResult, bind(&CachePacketReceiver::OnRecvCreateCharacterResult, this, _1));
	AddPacketFunc(CacheCharacterDataResult, bind(&CachePacketReceiver::OnRecvCharacterDataResult, this, _1));
	AddPacketFunc(CacheScriptFlagResponse, bind(&CachePacketReceiver::OnRecvScriptFlagResponse, this, _1));
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

// �L�����N�^�쐬���ʂ���M�����B
void CachePacketReceiver::OnRecvCreateCharacterResult(MemoryStreamInterface *pStream)
{
	CachePacketCreateCharacterResult Packet;
	Packet.Serialize(pStream);

	ClientManager::GetInstance().Get(Packet.ClientId).lock()->RecvPacket(Packet.GetPacketID(), pStream);
}

// �L�����N�^���̌��ʂ���M�����B
void CachePacketReceiver::OnRecvCharacterDataResult(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataResult Packet;
	Packet.Serialize(pStream);

	ClientManager::GetInstance().Get(Packet.ClientId).lock()->RecvPacket(Packet.GetPacketID(), pStream);
}

// �X�N���v�g�t���O����M�����B
void CachePacketReceiver::OnRecvScriptFlagResponse(MemoryStreamInterface *pStream)
{
	CachePacketScriptFlagResponse Packet;
	Packet.Serialize(pStream);

	ClientManager::GetInstance().Get(Packet.ClientId).lock()->RecvPacket(Packet.GetPacketID(), pStream);
}


// �p�P�b�g��M�֐���ǉ�.
void CachePacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
