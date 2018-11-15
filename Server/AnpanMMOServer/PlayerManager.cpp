#include "stdafx.h"
#include "PlayerManager.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "Packet/PacketSpawnPlayer.h"
#include "Packet/PacketPlayerList.h"
#include "Packet/PacketMovePlayer.h"
#include "Packet/PacketExitPlayer.h"

// �R���X�g���N�^
PlayerManager::PlayerManager()
{
}

// ���t���[���̏���.
void PlayerManager::Poll()
{
	PlayerMap::iterator It = PlayerList.begin();
	while (It != PlayerList.end())
	{
		if (It->second.expired())
		{
			u32 Uuid = It->first;
			It = PlayerList.erase(It);
			PacketExitPlayer Packet(Uuid);
			BroadcastPacket(&Packet);
		}
		else
		{
			++It;
		}
	}
}

// �ǉ�.
void PlayerManager::Add(u32 Uuid, PlayerCharacterPtr pPlayer)
{
	// ������ڑ��ς݂̃N���C�A���g�Ƀu���[�h�L���X�g
	const CharacterParameter &Param = pPlayer.lock()->GetParameter();
	PacketSpawnPlayer Packet(Uuid, Param.Hp, Param.MaxHp);
	BroadcastPacket(&Packet, pPlayer.lock()->GetClient());

	// �v���C���[���X�g��ʒm.
	PacketPlayerList ListPacket;
	MakeListPacket(ListPacket);
	pPlayer.lock()->GetClient()->SendPacket(&ListPacket);

	PlayerList[Uuid] = pPlayer;
}

// �폜.
void PlayerManager::Remove(u32 Uuid)
{
	PlayerList.erase(Uuid);

	// ���v���C���[�ɒʒm.
	PacketExitPlayer Packet(Uuid);
	BroadcastPacket(&Packet);
}

// �擾.
PlayerCharacterPtr PlayerManager::Get(u32 Uuid) const
{
	PlayerMap::const_iterator It = PlayerList.find(Uuid);
	if (It == PlayerList.end()) { return PlayerCharacterPtr(); }
	return It->second;
}

// �ړ�����M�����B
void PlayerManager::OnRecvMove(u32 Uuid, float X, float Y, float Rot)
{
	PlayerCharacter *pChara = PlayerList[Uuid].lock().get();
	pChara->SetPosition(Vector2D(X, Y));
	pChara->SetRotate(Rotation(Rot));

	PacketMovePlayer Packet(Uuid, X, Y, Rot);
	BroadcastPacket(&Packet, PlayerList[Uuid].lock()->GetClient());
}

// �p�P�b�g���u���[�h�L���X�g
void PlayerManager::BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient)
{
	for (PlayerMap::iterator It = PlayerList.begin(); It != PlayerList.end(); ++It)
	{
		Client *pClient = It->second.lock()->GetClient();
		if (pClient == pIgnoreClient) { continue; }
		pClient->SendPacket(pPacket);
	}
}


// �v���C���[���X�g�p�P�b�g�𐶐�.
void PlayerManager::MakeListPacket(PacketPlayerList &Packet)
{
	for (PlayerMap::iterator It = PlayerList.begin(); It != PlayerList.end(); ++It)
	{
		const Vector2D &Position = It->second.lock()->GetPosition();
		const Rotation &Rot = It->second.lock()->GetRotation();
		const CharacterParameter &Param = It->second.lock()->GetParameter();
		PlayerData Data(It->first, Position.X, Position.Y, Rot.Get(), Param.Hp, Param.MaxHp);
		Packet.List.PushBack(Data);
	}
}
