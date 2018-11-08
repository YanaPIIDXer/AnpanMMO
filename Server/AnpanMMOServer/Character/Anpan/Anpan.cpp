#include "stdafx.h"
#include "Anpan.h"
#include "World.h"

// コンストラクタ
Anpan::Anpan(const Vector2D &InPosition, int Hp, int Atk, int Def)
	: AI(this)
	, Uuid(0)
{
	SetPosition(InPosition);
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
}
