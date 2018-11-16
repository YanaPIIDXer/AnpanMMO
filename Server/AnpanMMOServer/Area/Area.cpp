#include "stdafx.h"
#include "Area.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "Character/Anpan/Anpan.h"
#include "Master/AreaMaster.h"
#include "Math/DamageCalcUnit.h"
#include "Packet/PacketSpawnAnpan.h"
#include "Packet/PacketAnpanList.h"
#include "Packet/PacketAddExp.h"

// �R���X�g���N�^
Area::Area(const AreaItem *pItem)
	: Id(pItem->ID)
{
	AnpanMgr.Initialize(pItem->AnpanMax, pItem->ID);
	AnpanMgr.SetSpawnCallback(bind(&Area::OnSpawnAnpan, this, _1, _2));
}

// ���t���[���̏���.
void Area::Poll(int DeltaTime)
{
	PlayerMgr.Poll();
	AnpanMgr.Poll(DeltaTime);
}

// �v���C���[�L�����̒ǉ�.
void Area::AddPlayerCharacter(const PlayerCharacterPtr &pPlayer)
{
	pPlayer.lock()->SetArea(shared_from_this());

	PlayerMgr.Add(pPlayer.lock()->GetClient()->GetUuid(), pPlayer);

	// �A���p�����X�g��ʒm.
	PacketAnpanList Packet;
	AnpanMgr.MakeListPacket(Packet);

	pPlayer.lock()->GetClient()->SendPacket(&Packet);
}

// �v���C���[�L�����폜.
void Area::RemovePlayerCharacter(u32 Uuid)
{
	PlayerMgr.Remove(Uuid);
}

// �ړ�����M�����B
void Area::OnRecvMove(u32 Uuid, float X, float Y, float Rotation)
{
	PlayerMgr.OnRecvMove(Uuid, X, Y, Rotation);
}

// �U������M�����B
void Area::OnRecvAttack(u32 AttackerUuid, u32 DefencerUuid)
{
	PlayerCharacterPtr pAttacker = PlayerMgr.Get(AttackerUuid);
	AnpanPtr pDefencer = AnpanMgr.Get(DefencerUuid);

	// �_���[�W�v�Z.
	DamageCalcUnit DamageCalc(pAttacker.lock()->GetParameter(), pDefencer.lock()->GetParameter());
	int DamageValue = DamageCalc.Calc();
	pDefencer.lock()->ApplyDamage(pAttacker, DamageValue);

	if (pDefencer.lock()->IsDead())
	{
		int Exp = pDefencer.lock()->GetExp();
		pAttacker.lock()->AddExp(Exp);

		PacketAddExp ExpPacket(pAttacker.lock()->GetExp());
		pAttacker.lock()->GetClient()->SendPacket(&ExpPacket);
	}
}

// �p�P�b�g�̃u���[�h�L���X�g
void Area::BroadcastPacket(PacketBase *pPacket)
{
	PlayerMgr.BroadcastPacket(pPacket);
}


// �A���p�����������ꂽ�B
void Area::OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan)
{
	pAnpan.lock()->SetArea(shared_from_this());

	const CharacterParameter &Param = pAnpan.lock()->GetParameter();
	const Vector2D &Position = pAnpan.lock()->GetPosition();
	AnpanData Data(Uuid, Position.X, Position.Y, pAnpan.lock()->GetRotation().Get(), Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	PlayerMgr.BroadcastPacket(&Packet);
}
