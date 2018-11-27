#include "stdafx.h"
#include "ClientStateTitle.h"
#include "Client.h"
#include "ClientStateAreaChange.h"
#include "ClientManager.h"
#include "CacheServerConnection.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInRequest.h"
#include "Packet/PacketLogInResult.h"
#include "Packet/PacketCreateCharacterRequest.h"
#include "Packet/PacketCreateCharacterResult.h"
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
	AddPacketFunction(CreateCharacterRequest, boost::bind(&ClientStateTitle::OnRecvCreateCharacterRequest, this, _2));
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
}

// �L�����N�^�쐬���N�G�X�g����M�����B
void ClientStateTitle::OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream)
{
	PacketCreateCharacterRequest Packet;
	Packet.Serialize(pStream);
}

// �L���b�V���T�[�o���烍�O�C�����ʂ���M�����B
void ClientStateTitle::OnRecvCacheLogInResult(MemoryStreamInterface *pStream)
{
	CachePacketLogInResult Packet;
	Packet.Serialize(pStream);

	PacketLogInResult::ResultCode ResultCode = PacketLogInResult::Success;
	switch (Packet.Result)
	{
		case CachePacketLogInResult::NoCharacter:

			ResultCode = PacketLogInResult::NoCharacter;
			break;

		case CachePacketLogInResult::Error:

			ResultCode = PacketLogInResult::Error;
			break;
	}

	if (Packet.Result == CachePacketLogInResult::Success)
	{
		// �_�u�����O�C���`�F�b�N�̓��U���g�R�[�h��Success�������ꍇ�̂ݍs���B
		if (!ClientManager::GetInstance().GetFromCustomerId(Packet.CustomerId).expired())
		{
			ResultCode = PacketLogInResult::DoubleLogIn;
		}
	}

	Client *pClient = GetParent();
	PacketLogInResult ResultPacket(ResultCode, pClient->GetUuid(), Packet.LastAreaId);
	pClient->SendPacket(&ResultPacket);

	if (ResultCode != PacketLogInResult::Success && ResultCode != PacketLogInResult::NoCharacter) { return; }

	// �L�����N�^�����݂��Ȃ������ꍇ�ł��J�X�^�}�h�c�͓o�^���Ă����B
	pClient->SetCustomerId(Packet.CustomerId);

	if (ResultCode != PacketLogInResult::Success) { return; }

	CachePacketCharacterDataRequest CharaRequestPacket(pClient->GetUuid(), Packet.CustomerId);
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

	ClientStateAreaChange *pNextState = new ClientStateAreaChange(pClient, Packet.LastAreaId, Vector3D(Packet.LastX, Packet.LastY, 0.0f));
	pClient->ChangeState(pNextState);
}
