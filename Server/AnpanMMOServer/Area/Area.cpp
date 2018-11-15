#include "stdafx.h"
#include "Area.h"
#include "Master/AreaMaster.h"
#include "Packet/PacketSpawnAnpan.h"

// �R���X�g���N�^
Area::Area(const AreaItem *pItem)
{
	AnpanMgr.Initialize(pItem->AnpanMinHp, pItem->AnpanMaxHp, pItem->AnpanMinAtk, pItem->AnpanMaxAtk, pItem->AnpanMinDef, pItem->AnpanMaxDef, pItem->AnpanMinExp, pItem->AnpanMaxExp);
	AnpanMgr.SetSpawnCallback(bind(&Area::OnSpawnAnpan, this, _1, _2));
}

// ���t���[���̏���.
void Area::Poll(int DeltaTime)
{
	PlayerMgr.Poll();
	AnpanMgr.Poll(DeltaTime);
}


// �A���p�����������ꂽ�B
void Area::OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan)
{
	const CharacterParameter &Param = pAnpan.lock()->GetParameter();
	const Vector2D &Position = pAnpan.lock()->GetPosition();
	AnpanData Data(Uuid, Position.X, Position.Y, pAnpan.lock()->GetRotation().Get(), Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	PlayerMgr.BroadcastPacket(&Packet);
}
