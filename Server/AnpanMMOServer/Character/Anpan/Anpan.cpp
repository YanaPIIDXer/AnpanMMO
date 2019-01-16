/**
 * @file Anpan.cpp
 * @brief アンパンクラス
 * @author YanaP
 */
#include "stdafx.h"
#include "Anpan.h"
#include "Master/MasterData.h"
#include "Math/DamageCalcUnit.h"
#include "Packet/PacketStopAnpan.h"

const float Anpan::BaseRadius = 80.0f;

// コンストラクタ
Anpan::Anpan(const Vector3D &InPosition, u32 InMasterId)
	: AI(this)
	, MasterId(InMasterId)
{
	SetPosition(InPosition);
	SetRotate(Rotation(180.0f));
	const AnpanItem *pItem = MasterData::GetInstance().GetAnpanMaster().GetItem(InMasterId);
	SetParameter(1, pItem->Hp, pItem->Hp, pItem->Str, pItem->Def, pItem->Int, pItem->Mnd, pItem->Vit, false);
	Exp = pItem->Exp;
	ScaleRate = pItem->Scale;
	DropId = pItem->DropId;
}

// 攻撃.
void Anpan::AttackTo(CharacterPtr pTarget, u32 SkillId)
{
	Skill.Use(SkillId, pTarget);
}

// バフが追加された。
void Anpan::OnBuffAdded(u32 BuffId)
{
	const BuffItem *pItem = MasterData::GetInstance().GetBuffMaster().GetItem(BuffId);
	if (pItem == NULL) { return; }

	if (pItem->Type == BuffItem::PARALYSIS)
	{
		// 麻痺を貰ったらＡＩを止める。
		AI.Stop();
	}
}


// 毎フレームの処理.
void Anpan::Update(int DeltaTime)
{
	AI.Poll(DeltaTime);

	shared_ptr<AnpanMovePacketData> pMovePacketData = AI.SweepMovePacketData();
	if (pMovePacketData != NULL)
	{
		PacketMoveAnpan Packet = pMovePacketData->CreatePacket();
		GetArea().lock()->BroadcastPacket(&Packet);
	}

	shared_ptr<AnpanRotatePacketData> pRotatePacketData = AI.SweepRotatePacketData();
	if (pRotatePacketData != NULL)
	{
		PacketRotateAnpan Packet = pRotatePacketData->CreatePacket();
		GetArea().lock()->BroadcastPacket(&Packet);
	}

	if (AI.SweepSendStopPacketFlag())
	{
		const Vector3D Pos = GetPosition();
		PacketStopAnpan Packet(GetUuid(), Pos.X, Pos.Y, Pos.Z, GetRotation().Get());
		GetArea().lock()->BroadcastPacket(&Packet);
	}
}

// ダメージを受けた。
void Anpan::OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue)
{
	AI.OnDamaged(pAttacker, DamageValue);
}
