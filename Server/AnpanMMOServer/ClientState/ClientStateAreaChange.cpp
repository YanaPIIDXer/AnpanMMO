/**
 * @file ClientStateAreaChange.cpp
 * @brief �N���C�A���g�X�e�[�g�F�G���A�؂�ւ�
 * @author YanaP
 */
#include "stdafx.h"
#include "ClientStateAreaChange.h"
#include "Client.h"
#include "PlayerManager.h"
#include "Character/Player/PlayerCharacter.h"
#include "Area/AreaManager.h"
#include "ClientStateActive.h"
#include "Packet/PacketPing.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketAreaMove.h"

// �R���X�g���N�^
ClientStateAreaChange::ClientStateAreaChange(Client *pInParent, u32 InAreaId, const Vector3D &InPosition)
	: ClientStateBase(pInParent)
	, AreaId(InAreaId)
	, Position(InPosition)
{
	AddPacketFunction(PacketID::Ping, boost::bind(&ClientStateAreaChange::OnRecvPing, this, _2));
	AddPacketFunction(PacketID::GameReady, boost::bind(&ClientStateAreaChange::OnRecvGameReady, this, _2));
}


// Ping����M.
bool ClientStateAreaChange::OnRecvPing(MemoryStreamInterface *pStream)
{
	PacketPing Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	// ���̂܂ܓ����Ԃ��B
	GetParent()->SendPacket(&Packet);

	return true;
}

// �Q�[��������������M.
bool ClientStateAreaChange::OnRecvGameReady(MemoryStreamInterface *pStream)
{
	PacketGameReady Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	PlayerCharacterPtr pPlayerChara = GetParent()->GetCharacter();
	pPlayerChara.lock()->SetPosition(Position);
	AreaPtr pArea = AreaManager::GetInstance().Get(AreaId);
	pArea.lock()->AddPlayerCharacter(pPlayerChara);
	pPlayerChara.lock()->OnAreaChange();

	// �G���A�ړ����N���C�A���g�ɒʒm.
	PacketAreaMove AreaMovePacket(AreaId, Position.X, Position.Y, Position.Z);
	GetParent()->SendPacket(&AreaMovePacket);

	// �A�N�e�B�u��ԂցB
	ClientStateActive *pNewState = new ClientStateActive(GetParent());
	GetParent()->ChangeState(pNewState);

	return true;
}
