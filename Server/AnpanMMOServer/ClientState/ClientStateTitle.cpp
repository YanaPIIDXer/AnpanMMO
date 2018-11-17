#include "stdafx.h"
#include "ClientStateTitle.h"
#include "Client.h"
#include "DBConnection.h"
#include "ClientStateAreaChange.h"
#include "ClientManager.h"
#include "CacheServerConnection.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInRequest.h"
#include "Packet/PacketLogInResult.h"
#include "Packet/PacketCharacterStatus.h"
#include "Packet/CachePacketLogInRequest.h"
#include "Packet/CachePacketLogInResult.h"
#include "Packet/CachePacketCharacterDataRequest.h"
#include "Packet/CachePacketCharacterDataResult.h"

// �R���X�g���N�^
ClientStateTitle::ClientStateTitle(Client *pInParent)
	: ClientStateBase(pInParent)
{
	AddPacketFunction(LogInRequest, boost::bind(&ClientStateTitle::OnRecvLogInRequest, this, _2));
	AddPacketFunction(CacheLogInResult, boost::bind(&ClientStateTitle::OnRecvCacheLogInResult, this, _2));
	AddPacketFunction(CacheCharacterDataResult, boost::bind(&ClientStateTitle::OnRecvCacheCharacterDataResult, this, _2));
}


// ���O�C�����N�G�X�g����M�����B
void ClientStateTitle::OnRecvLogInRequest(MemoryStreamInterface *pStream)
{
	PacketLogInRequest Packet;
	Packet.Serialize(pStream);

	CachePacketLogInRequest CachePacket(GetParent()->GetUuid(), Packet.UserCode);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);

	/*
	u32 AreaId = 1;
	float X = 0.0f;
	float Y = 0.0f;
	if (!DBConnection::GetInstance().ReadLastLogoutPosition(Id, AreaId, X, Y))
	{
		std::cout << "Read Last Logout Position Failed..." << std::endl;
	}

	ClientStateAreaChange *pNextState = new ClientStateAreaChange(pClient, AreaId, Vector2D(X, Y));
	pClient->ChangeState(pNextState);
	*/
}

// �L���b�V���T�[�o���烍�O�C�����ʂ���M�����B
void ClientStateTitle::OnRecvCacheLogInResult(MemoryStreamInterface *pStream)
{
	CachePacketLogInResult Packet;
	Packet.Serialize(pStream);

	PacketLogInResult::ResultCode ResultCode = PacketLogInResult::Success;
	if (Packet.Result != CachePacketLogInResult::Success)
	{
		ResultCode = PacketLogInResult::Error;
	}
	if (!ClientManager::GetInstance().GetFromCustomerId(Packet.Uuid).expired())
	{
		ResultCode = PacketLogInResult::DoubleLogIn;
	}

	Client *pClient = GetParent();
	PacketLogInResult ResultPacket(ResultCode, pClient->GetUuid());
	pClient->SendPacket(&ResultPacket);

	if (ResultCode != PacketLogInResult::Success) { return; }

	pClient->SetCustomerId(Packet.Uuid);

	CachePacketCharacterDataRequest CharaRequestPacket(pClient->GetUuid(), Packet.Uuid);
	CacheServerConnection::GetInstance()->SendPacket(&CharaRequestPacket);
}

// �L���b�V���T�[�o����L�����N�^�f�[�^����M�����B
void ClientStateTitle::OnRecvCacheCharacterDataResult(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataResult Packet;
	Packet.Serialize(pStream);

	if (Packet.Result != CachePacketCharacterDataResult::Success)
	{
		std::cout << "CharacterData Load Failed..." << std::endl;
		return;
	}

	Client *pClient = GetParent();
	pClient->CreateCharacter(Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp);
	PacketCharacterStatus StatusPacket(pClient->GetUuid(), Packet.MaxHp, Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp);
	pClient->SendPacket(&StatusPacket);
}
