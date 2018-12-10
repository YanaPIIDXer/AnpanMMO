#include "stdafx.h"
#include "AreaBase.h"
#include "WeakPtrDefine.h"
#include "Client.h"
#include <math.h>
#include "Character/CharacterBase.h"
#include "Character/Player/PlayerCharacter.h"
#include "Character/Anpan/Anpan.h"
#include "Master/AreaMaster.h"
#include "Packet/CharacterType.h"
#include "Packet/PacketSpawnAnpan.h"
#include "Packet/PacketAnpanList.h"
#include "Packet/PacketAddExp.h"

// �R���X�g���N�^
AreaBase::AreaBase(const AreaItem *pItem)
{
	AnpanMgr.Initialize(pItem->ID);
	AnpanMgr.SetSpawnCallback(bind(&AreaBase::OnSpawnAnpan, this, _1, _2));
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
void AreaBase::Poll(int DeltaTime)
{
	PlayerMgr.Poll(DeltaTime);
	AnpanMgr.Poll(DeltaTime);
	Update();
}

// �v���C���[�L�����̒ǉ�.
void AreaBase::AddPlayerCharacter(const PlayerCharacterPtr &pPlayer)
{
	pPlayer.lock()->SetArea(shared_from_this());

	PlayerMgr.Add(pPlayer.lock()->GetClient()->GetUuid(), pPlayer);

	// �A���p�����X�g��ʒm.
	PacketAnpanList Packet;
	AnpanMgr.MakeListPacket(Packet);

	pPlayer.lock()->GetClient()->SendPacket(&Packet);
}

// �v���C���[�L�����폜.
void AreaBase::RemovePlayerCharacter(u32 Uuid)
{
	PlayerMgr.Remove(Uuid);
}

// �ړ�����M�����B
void AreaBase::OnRecvMove(u32 Uuid, float X, float Y, float Z, float Rotation)
{
	PlayerMgr.OnRecvMove(Uuid, X, Y, Z, Rotation);
}

// �X�L���g�p����M�����B
void AreaBase::OnRecvSkillUse(u32 Uuid, u32 SkillId, u8 TargetType, u32 TargetUuid)
{
	PlayerCharacterPtr pPlayer = PlayerMgr.Get(Uuid);
	CharacterBase *pTarget = NULL;
	switch (TargetType)
	{
		case CharacterType::Player:

			pTarget = PlayerMgr.Get(TargetUuid).lock().get();
			break;

		case CharacterType::Enemy:

			pTarget = AnpanMgr.Get(TargetUuid).lock().get();
			break;
	}

	pPlayer.lock()->UseSkill(SkillId, pTarget);
}

// �p�P�b�g�̃u���[�h�L���X�g
void AreaBase::BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient)
{
	PlayerMgr.BroadcastPacket(pPacket, pIgnoreClient);
}

// �͈͂��w�肵���p�P�b�g�̃u���[�h�L���X�g
void AreaBase::BroadcastPacketWithRange(PacketBase *pPacket, const Vector3D &Center, float Range, Client *pIgnoreClient)
{
	PlayerMgr.BroadcastPacketWithRange(pPacket, Center, Range, pIgnoreClient);
}

// �������擾.
float AreaBase::GetHeight(float X, float Y) const
{
	return HeightData.GetHeight(X, Y);
}

// �ړ��\���ǂ������`�F�b�N
bool AreaBase::CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const
{
	return HeightData.CheckMovable(Start, End, ClimbableHeight, OutHit);
}

// �~�`�Ń^�[�Q�b�g���擾.
void AreaBase::CollectCircle(const Vector3D &Center, float Radius, u8 TargetType, std::vector<CharacterBase *> &OutTargets)
{
	std::vector<CharacterPtr> Targets;
	switch (TargetType)
	{
		case CharacterType::Player:
			
			PlayerMgr.GetAllAsCharacterPtr(Targets);
			break;

		case CharacterType::Enemy:

			AnpanMgr.GetAllAsCharacterPtr(Targets);
			break;
	}

	for (u32 i = 0; i < Targets.size(); i++)
	{
		Vector3D TargetPos = Targets[i].lock()->GetPosition();
		if ((pow(TargetPos.X - Center.X, 2) + pow(TargetPos.Y - Center.Y, 2)) <= Radius * Radius)
		{
			OutTargets.push_back(Targets[i].lock().get());
		}
	}
}

// ��`�Ń^�[�Q�b�g���擾.
void AreaBase::CollectBox(const Vector3D &Center, float Width, float Height, u8 TargetType, std::vector<CharacterBase *> &OutTargets)
{
	std::vector<CharacterPtr> Targets;
	switch (TargetType)
	{
		case CharacterType::Player:

			PlayerMgr.GetAllAsCharacterPtr(Targets);
			break;

		case CharacterType::Enemy:

			AnpanMgr.GetAllAsCharacterPtr(Targets);
			break;
	}

	Vector3D Left = Center;
	Left.X -= Width * 0.5f;
	Left.Y -= Height * 0.5f;
	
	Vector3D Right = Center;
	Right.X += Width * 0.5f;
	Right.Y += Height * 0.5f;
	for (u32 i = 0; i < Targets.size(); i++)
	{
		Vector3D TargetPos = Targets[i].lock()->GetPosition();
		if ((TargetPos.X >= Left.X) && (TargetPos.X <= Right.X) && (TargetPos.Y >= Left.Y) && (TargetPos.Y <= Right.Y))
		{
			OutTargets.push_back(Targets[i].lock().get());
		}
	}
}


// �A���p�����������ꂽ�B
void AreaBase::OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan)
{
	pAnpan.lock()->SetArea(shared_from_this());

	const CharacterParameter &Param = pAnpan.lock()->GetParameter();
	const Vector3D &Position = pAnpan.lock()->GetPosition();
	AnpanData Data(Uuid, pAnpan.lock()->GetMasterId(), Position.X, Position.Y, Position.Z, pAnpan.lock()->GetRotation().Get(), Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	PlayerMgr.BroadcastPacket(&Packet);
}
