#include "stdafx.h"
#include "World.h"
#include "Client.h"
#include "Math/DamageCalcUnit.h"
#include "Math/Random.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "TickManager.h"
#include "Packet/PacketSpawnAnpan.h"
#include "Packet/PacketAnpanList.h"
#include "Packet/PacketMovePlayer.h"
#include "Packet/PacketAttack.h"
#include "Packet/PacketDamage.h"
#include "Packet/PacketAddExp.h"

World World::Instance;

// �R���X�g���N�^
World::World()
{
}

// ������.
void World::Initialize()
{
	TickManager::GetInstance().Add(bind(&World::Poll, this, _1));
	AnpanMgr.SetSpawnCallback(bind(&World::OnSpawnAnpan, this, _1, _2));
}

// ���t���[���̏���.
void World::Poll(int DeltaTime)
{
	PlayerMgr.Poll();
	AnpanMgr.Poll(DeltaTime);
}

// �v���C���[�L�����̒ǉ�.
void World::AddPlayerCharacter(const PlayerCharacterPtr &pPlayer)
{
	PlayerMgr.Add(pPlayer.lock()->GetClient()->GetUuid(), pPlayer);
	
	// �A���p�����X�g��ʒm.
	PacketAnpanList Packet;
	AnpanMgr.MakeListPacket(Packet);

	pPlayer.lock()->GetClient()->SendPacket(&Packet);
}

// �p�P�b�g���u���[�h�L���X�g
void World::BroadcastPacket(PacketBase *pPacket)
{
	PlayerMgr.BroadcastPacket(pPacket);
}

// �v���C���[�ړ�����M�����B
void World::OnRecvMove(Client *pClient, MemoryStreamInterface *pStream)
{
	PacketMovePlayer Packet;
	Packet.Serialize(pStream);

	PlayerMgr.OnRecvMove(Packet.Uuid, Packet.X, Packet.Y, Packet.Rotation);
}

// �U������M�����B
void World::OnRecvAttack(Client *pClient, MemoryStreamInterface *pStream)
{
	PacketAttack Packet;
	Packet.Serialize(pStream);

	PlayerCharacterPtr pAttacker = pClient->GetCharacter();
	AnpanPtr pDefencer = AnpanMgr.Get(Packet.TargetUuid);

	// �_���[�W�v�Z.
	DamageCalcUnit DamageCalc(pAttacker.lock()->GetParameter(), pDefencer.lock()->GetParameter());
	int DamageValue = DamageCalc.Calc();
	pDefencer.lock()->ApplyDamage(DamageValue);

	// �_���[�W��ʒm.
	PacketDamage DamagePacket(PacketDamage::Enemy, Packet.TargetUuid, DamageValue, pDefencer.lock()->GetParameter().Hp);
	PlayerMgr.BroadcastPacket(&DamagePacket);
	
	if (pDefencer.lock()->IsDead())
	{
		int Exp = Random::Range<int>(10, 50);
		pAttacker.lock()->AddExp(Exp);

		PacketAddExp ExpPacket(pAttacker.lock()->GetExp());
		pAttacker.lock()->GetClient()->SendPacket(&ExpPacket);
	}
}


// �A���p�����������ꂽ�B
void World::OnSpawnAnpan(unsigned int Uuid, AnpanPtr pAnpan)
{
	const CharacterParameter &Param = pAnpan.lock()->GetParameter();
	const Vector2D &Position = pAnpan.lock()->GetPosition();
	AnpanData Data(Uuid, Position.X, Position.Y, pAnpan.lock()->GetRotation().Get(), Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	PlayerMgr.BroadcastPacket(&Packet);
}
