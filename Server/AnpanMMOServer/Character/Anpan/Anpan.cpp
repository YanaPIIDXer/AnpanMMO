#include "stdafx.h"
#include "Anpan.h"
#include "World.h"
#include "Math/DamageCalcUnit.h"
#include "Packet/PacketStopAnpan.h"

// コンストラクタ
Anpan::Anpan(const Vector2D &InPosition, int Hp, int Atk, int Def, int InExp)
	: AI(this)
	, Exp(InExp)
{
	SetPosition(InPosition);
	SetRotate(Rotation(180.0f));
	SetParameter(Hp, Hp, Atk, Def);
}

// 毎フレームの処理.
void Anpan::Poll(int DeltaTime)
{
	AI.Poll(DeltaTime);

	shared_ptr<AnpanMovePacketData> pMovePacketData = AI.SweepMovePacketData();
	if (pMovePacketData != NULL)
	{
		PacketMoveAnpan Packet = pMovePacketData->CreatePacket();
		World::GetInstance().BroadcastPacket(&Packet);
	}

	shared_ptr<AnpanRotatePacketData> pRotatePacketData = AI.SweepRotatePacketData();
	if (pRotatePacketData != NULL)
	{
		PacketRotateAnpan Packet = pRotatePacketData->CreatePacket();
		World::GetInstance().BroadcastPacket(&Packet);
	}

	if (AI.SweepSendStopPacketFlag())
	{
		const Vector2D Pos = GetPosition();
		PacketStopAnpan Packet(GetUuid(), Pos.X, Pos.Y, GetRotation().Get());
		World::GetInstance().BroadcastPacket(&Packet);
	}
}

// 攻撃.
void Anpan::AttackTo(CharacterBase *pTarget)
{
	DamageCalcUnit Calc(GetParameter(), pTarget->GetParameter());
	int Value = Calc.Calc();

	pTarget->ApplyDamage(shared_from_this(), Value);
}


// ダメージを受けた。
void Anpan::OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue)
{
	AI.OnDamaged(pAttacker, DamageValue);
}
