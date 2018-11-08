#include "stdafx.h"
#include "World.h"
#include "Client.h"
#include "Math/DamageCalcUnit.h"
#include "Math/Random.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "TickManager.h"
#include "Packet/PacketSpawnAnpan.h"
#include "Packet/PacketAnpanList.h"
#include "Packet/PacketMovePlayer.h"
#include "Packet/PacketAttack.h"
#include "Packet/PacketDamage.h"
#include "Packet/PacketAddExp.h"

World World::Instance;

// コンストラクタ
World::World()
{
}

// 初期化.
void World::Initialize()
{
	TickManager::GetInstance().Add(bind(&World::Poll, this, _1));
	AnpanMgr.SetSpawnCallback(bind(&World::OnSpawnAnpan, this, _1, _2));
}

// 毎フレームの処理.
void World::Poll(int DeltaTime)
{
	PlayerMgr.Poll();
	AnpanMgr.Poll(DeltaTime);
}

// プレイヤーキャラの追加.
void World::AddPlayerCharacter(const PlayerCharacterPtr &pPlayer)
{
	PlayerMgr.Add(pPlayer.lock()->GetClient()->GetUuid(), pPlayer);
	
	// アンパンリストを通知.
	PacketAnpanList Packet;
	AnpanMgr.MakeListPacket(Packet);

	pPlayer.lock()->GetClient()->SendPacket(&Packet);
}

// パケットをブロードキャスト
void World::BroadcastPacket(PacketBase *pPacket)
{
	PlayerMgr.BroadcastPacket(pPacket);
}

// プレイヤー移動を受信した。
void World::OnRecvMove(Client *pClient, MemoryStreamInterface *pStream)
{
	PacketMovePlayer Packet;
	Packet.Serialize(pStream);

	PlayerMgr.OnRecvMove(Packet.Uuid, Packet.X, Packet.Y, Packet.Rotation);
}

// 攻撃を受信した。
void World::OnRecvAttack(Client *pClient, MemoryStreamInterface *pStream)
{
	PacketAttack Packet;
	Packet.Serialize(pStream);

	PlayerCharacterPtr pAttacker = pClient->GetCharacter();
	AnpanPtr pDefencer = AnpanMgr.Get(Packet.TargetUuid);

	// ダメージ計算.
	DamageCalcUnit DamageCalc(pAttacker.lock()->GetParameter(), pDefencer.lock()->GetParameter());
	int DamageValue = DamageCalc.Calc();
	pDefencer.lock()->ApplyDamage(DamageValue);

	// ダメージを通知.
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


// アンパンが生成された。
void World::OnSpawnAnpan(unsigned int Uuid, AnpanPtr pAnpan)
{
	const CharacterParameter &Param = pAnpan.lock()->GetParameter();
	const Vector2D &Position = pAnpan.lock()->GetPosition();
	AnpanData Data(Uuid, Position.X, Position.Y, pAnpan.lock()->GetRotation().Get(), Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	PlayerMgr.BroadcastPacket(&Packet);
}
