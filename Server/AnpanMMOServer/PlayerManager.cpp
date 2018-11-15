#include "stdafx.h"
#include "PlayerManager.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "Packet/PacketSpawnPlayer.h"
#include "Packet/PacketPlayerList.h"
#include "Packet/PacketMovePlayer.h"
#include "Packet/PacketExitPlayer.h"

// コンストラクタ
PlayerManager::PlayerManager()
{
}

// 毎フレームの処理.
void PlayerManager::Poll()
{
	PlayerMap::iterator It = PlayerList.begin();
	while (It != PlayerList.end())
	{
		if (It->second.expired())
		{
			u32 Uuid = It->first;
			It = PlayerList.erase(It);
			PacketExitPlayer Packet(Uuid);
			BroadcastPacket(&Packet);
		}
		else
		{
			++It;
		}
	}
}

// 追加.
void PlayerManager::Add(u32 Uuid, PlayerCharacterPtr pPlayer)
{
	// 生成を接続済みのクライアントにブロードキャスト
	const CharacterParameter &Param = pPlayer.lock()->GetParameter();
	PacketSpawnPlayer Packet(Uuid, Param.Hp, Param.MaxHp);
	BroadcastPacket(&Packet, pPlayer.lock()->GetClient());

	// プレイヤーリストを通知.
	PacketPlayerList ListPacket;
	MakeListPacket(ListPacket);
	pPlayer.lock()->GetClient()->SendPacket(&ListPacket);

	PlayerList[Uuid] = pPlayer;
}

// 削除.
void PlayerManager::Remove(u32 Uuid)
{
	PlayerList.erase(Uuid);

	// 他プレイヤーに通知.
	PacketExitPlayer Packet(Uuid);
	BroadcastPacket(&Packet);
}

// 取得.
PlayerCharacterPtr PlayerManager::Get(u32 Uuid) const
{
	PlayerMap::const_iterator It = PlayerList.find(Uuid);
	if (It == PlayerList.end()) { return PlayerCharacterPtr(); }
	return It->second;
}

// 移動を受信した。
void PlayerManager::OnRecvMove(u32 Uuid, float X, float Y, float Rot)
{
	PlayerCharacter *pChara = PlayerList[Uuid].lock().get();
	pChara->SetPosition(Vector2D(X, Y));
	pChara->SetRotate(Rotation(Rot));

	PacketMovePlayer Packet(Uuid, X, Y, Rot);
	BroadcastPacket(&Packet, PlayerList[Uuid].lock()->GetClient());
}

// パケットをブロードキャスト
void PlayerManager::BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient)
{
	for (PlayerMap::iterator It = PlayerList.begin(); It != PlayerList.end(); ++It)
	{
		Client *pClient = It->second.lock()->GetClient();
		if (pClient == pIgnoreClient) { continue; }
		pClient->SendPacket(pPacket);
	}
}


// プレイヤーリストパケットを生成.
void PlayerManager::MakeListPacket(PacketPlayerList &Packet)
{
	for (PlayerMap::iterator It = PlayerList.begin(); It != PlayerList.end(); ++It)
	{
		const Vector2D &Position = It->second.lock()->GetPosition();
		const Rotation &Rot = It->second.lock()->GetRotation();
		const CharacterParameter &Param = It->second.lock()->GetParameter();
		PlayerData Data(It->first, Position.X, Position.Y, Rot.Get(), Param.Hp, Param.MaxHp);
		Packet.List.PushBack(Data);
	}
}
