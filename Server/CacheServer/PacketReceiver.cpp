#include "stdafx.h"
#include "PacketReceiver.h"
#include "GameServerConnection.h"
#include "DBConnection.h"
#include "Packet/CachePacketLogInRequest.h"
#include "Packet/CachePacketLogInResult.h"
#include "Packet/CachePacketCharacterDataRequest.h"
#include "Packet/CachePacketCharacterDataResult.h"

// �R���X�g���N�^
PacketReceiver::PacketReceiver(GameServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(CacheLogInRequest, bind(&PacketReceiver::OnRecvLogInRequest, this, _1));
	AddPacketFunc(CacheCharacterDataRequest, bind(&PacketReceiver::OnRecvCharacterDataRequest, this, _1));
}

// ���O�C�����N�G�X�g����M�����B
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

// �L�����N�^��񃊃N�G�X�g����M�����B
void PacketReceiver::OnRecvCharacterDataRequest(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataRequest Packet;
	Packet.Serialize(pStream);

	s32 MaxHp = 0;
	s32 Atk = 0;
	s32 Def = 0;
	s32 Exp = 0;
	CachePacketCharacterDataResult::ResultCode ResultCode = CachePacketCharacterDataResult::Success;
	if (!DBConnection::GetInstance().LoadCharacterParameter(Packet.CustomerId, MaxHp, Atk, Def, Exp))
	{
		ResultCode = CachePacketCharacterDataResult::Error;
	}

	u32 LastAreaId = 0;
	float LastX = 0.0f;
	float LastY = 0.0f;
	if (!DBConnection::GetInstance().ReadLastLogoutPosition(Packet.CustomerId, LastAreaId, LastX, LastY))
	{
		ResultCode = CachePacketCharacterDataResult::Error;
	}

	CachePacketCharacterDataResult ResultPacket(Packet.ClientId, ResultCode, MaxHp, Atk, Def, Exp, LastAreaId, LastX, LastY);
	pParent->SendPacket(&ResultPacket);
}


// �p�P�b�g��M.
void PacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// �p�P�b�g��M�֐���ǉ�.
void PacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
