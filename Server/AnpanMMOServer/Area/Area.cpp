#include "stdafx.h"
#include "Area.h"
#include "Client.h"
#include "Master/AreaMaster.h"
#include "Packet/PacketSpawnAnpan.h"
#include "Packet/PacketAnpanList.h"

// コンストラクタ
Area::Area(const AreaItem *pItem)
{
	AnpanMgr.Initialize(pItem->AnpanMinHp, pItem->AnpanMaxHp, pItem->AnpanMinAtk, pItem->AnpanMaxAtk, pItem->AnpanMinDef, pItem->AnpanMaxDef, pItem->AnpanMinExp, pItem->AnpanMaxExp);
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

// パケットのブロードキャスト
void Area::BroadcastPacket(PacketBase *pPacket)
{
	PlayerMgr.BroadcastPacket(pPacket);
}


// アンパンが生成された。
void Area::OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan)
{
	const CharacterParameter &Param = pAnpan.lock()->GetParameter();
	const Vector2D &Position = pAnpan.lock()->GetPosition();
	AnpanData Data(Uuid, Position.X, Position.Y, pAnpan.lock()->GetRotation().Get(), Param.Hp, Param.MaxHp);
	PacketSpawnAnpan Packet(Data);
	PlayerMgr.BroadcastPacket(&Packet);
}
