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

// コンストラクタ
Area::Area(const AreaItem *pItem)
	: Id(pItem->ID)
{
	AnpanMgr.Initialize(pItem->AnpanMax, pItem->ID);
	AnpanMgr.SetSpawnCallback(bind(&Area::OnSpawnAnpan, this, _1, _2));
}

// 毎フレームの処理.
void Area::Poll(int DeltaTime)
{
	PlayerMgr.Poll();
	AnpanMgr.Poll(DeltaTime);
}

// プレイヤーキャラの追加.
void Area::AddPlayerCharacter(const PlayerCharacterPtr &pPlayer)
{
	pPlayer.lock()->SetArea(shared_from_this());

	PlayerMgr.Add(pPlayer.lock()->GetClient()->GetUuid(), pPlayer);

	// アンパンリストを通知.
	PacketAnpanList Packet;
	AnpanMgr.MakeListPacket(Packet);

	pPlayer.lock()->GetClient()->SendPacket(&Packet);
}

// プレイヤーキャラ削除.
void Area::RemovePlayerCharacter(u32 Uuid)
{
	PlayerMgr.Remove(Uuid);
}

// 移動を受信した。
void Area::OnRecvMove(u32 Uuid, float X, float Y, float Rotation)
{
	PlayerMgr.OnRecvMove(Uuid, X, Y, Rotation);
}

// 攻撃を受信した。
void Area::OnRecvAttack(u32 AttackerUuid, u32 DefencerUuid)
{
	PlayerCharacterPtr pAttacker = PlayerMgr.Get(AttackerUuid);
	AnpanPtr pDefencer = AnpanMgr.Get(DefencerUuid);

	// ダメージ計算.
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

// パケットのブロードキャスト
void Area::BroadcastPacket(PacketBase *pPacket)
{
	PlayerMgr.BroadcastPacket(pPacket);
}


// アンパンが生成された。
void Area::OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan)
{
	pAnpan.lock()->SetArea(shared_from_this());

	const CharacterParameter &Param = pAnpan.lock()->GetParameter();
	const Vector2D &Position = pAnpan.lock()->GetPosition();
	AnpanData Data(Uuid, Position.X, Position.Y, pAnpan.lock()->GetRotation().Get(), Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	PlayerMgr.BroadcastPacket(&Packet);
}
