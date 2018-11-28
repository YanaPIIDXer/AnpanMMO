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
	AnpanMgr.Initialize(pItem->ID);
	AnpanMgr.SetSpawnCallback(bind(&Area::OnSpawnAnpan, this, _1, _2));
	std::string HeightMapPath = "../../HeightMap/HeightMaps/" + pItem->LevelName + ".bmp";
	if (!HeightData.Load(HeightMapPath))
	{
		std::cout << "HeightMap Load Failed... Path:" << HeightMapPath << std::endl;
	}
	else
	{
		std::cout << pItem->LevelName << " HeightMap Load Success!!" << std::endl;
	}
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
void Area::OnRecvMove(u32 Uuid, float X, float Y, float Z, float Rotation)
{
	PlayerMgr.OnRecvMove(Uuid, X, Y, Z, Rotation);
}

// �U������M�����B
void Area::OnRecvAttack(u32 AttackerUuid, u32 DefencerUuid)
{
	PlayerCharacterPtr pAttacker = PlayerMgr.Get(AttackerUuid);
	AnpanPtr pDefencer = AnpanMgr.Get(DefencerUuid);

	// �A�ł������ȂǁA�T�[�o��ł͊��Ɏ���ł���A���p�������낤�Ƃ��鎖������B
	if (pDefencer.expired()) { return; }

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
void Area::BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient)
{
	PlayerMgr.BroadcastPacket(pPacket, pIgnoreClient);
}

// �������擾.
float Area::GetHeight(float X, float Y) const
{
	return HeightData.GetHeight(X, Y);
}

// �ړ��\���ǂ������`�F�b�N
bool Area::CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const
{
	return HeightData.CheckMovable(Start, End, ClimbableHeight, OutHit);
}


// �A���p�����������ꂽ�B
void Area::OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan)
{
	pAnpan.lock()->SetArea(shared_from_this());

	const CharacterParameter &Param = pAnpan.lock()->GetParameter();
	const Vector3D &Position = pAnpan.lock()->GetPosition();
	AnpanData Data(Uuid, Position.X, Position.Y, Position.Z, pAnpan.lock()->GetRotation().Get(), Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	PlayerMgr.BroadcastPacket(&Packet);
}
