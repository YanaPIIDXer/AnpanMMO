#include "stdafx.h"
#include "World.h"
#include "Client.h"
#include "Math/DamageCalcUnit.h"
#include "Math/Random.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketSpawnAnpan.h"
#include "Packet/PacketAnpanList.h"
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
	AnpanMgr.SetSpawnCallback(bind(&World::OnSpawnAnpan, this, _1, _2));
}

// ���t���[���̏���.
void World::Poll()
{
	PlayerMgr.Poll();
	AnpanMgr.Poll();
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
	AnpanData Data(Uuid, Position.X, Position.Y, Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	PlayerMgr.BroadcastPacket(&Packet);
}
