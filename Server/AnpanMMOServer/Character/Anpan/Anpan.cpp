#include "stdafx.h"
#include "Anpan.h"
#include "Math/DamageCalcUnit.h"
#include "Packet/PacketStopAnpan.h"

const float Anpan::BaseRadius = 80.0f;

// コンストラクタ
Anpan::Anpan(const Vector3D &InPosition, u32 InMasterId, int Hp, int Atk, int Def, int InExp, float InScaleRate)
	: AI(this)
	, MasterId(InMasterId)
	, Exp(InExp)
	, ScaleRate(InScaleRate)
{
	SetPosition(InPosition);
	SetRotate(Rotation(180.0f));
	SetParameter(Hp, Hp, Atk, Def);
}

// 攻撃.
void Anpan::AttackTo(CharacterPtr pTarget, u32 SkillId)
{
	Skill.Use(SkillId, pTarget);
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
