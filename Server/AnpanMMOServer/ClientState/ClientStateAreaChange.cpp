#include "stdafx.h"
#include "ClientStateAreaChange.h"
#include "Client.h"
#include "PlayerManager.h"
#include "Character/Player/PlayerCharacter.h"
#include "Area/AreaManager.h"
#include "ClientStateActive.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketAreaMove.h"

// �R���X�g���N�^
ClientStateAreaChange::ClientStateAreaChange(Client *pInParent, u32 InAreaId, const Vector3D &InPosition)
	: ClientStateBase(pInParent)
	, AreaId(InAreaId)
	, Position(InPosition)
{
	AddPacketFunction(GameReady, boost::bind(&ClientStateAreaChange::OnRecvGameReady, this, _2));
}


// �Q�[��������������M.
void ClientStateAreaChange::OnRecvGameReady(MemoryStreamInterface *pStream)
{
	PacketGameReady Packet;
	Packet.Serialize(pStream);		// �Ԃ����Ⴏ����Ȃ��񂶂�ˁH

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
}
