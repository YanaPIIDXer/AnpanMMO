#include "stdafx.h"
#include  "ClientStateActive.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "DBConnection.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "Area/AreaManager.h"
#include "Packet/PacketCharacterStatus.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketRespawnRequest.h"
#include "Packet/PacketPlayerRespawn.h"

// コンストラクタ
ClientStateActive::ClientStateActive(Client *pInParent)
	: ClientStateBase(pInParent)
{
	AddPacketFunction(GameReady, boost::bind(&ClientStateActive::OnRecvGameReady, this, _2));
	AddPacketFunction(MovePlayer, boost::bind(&AreaManager::OnRecvMove, &AreaManager::GetInstance(), _1, _2));
	AddPacketFunction(Attack, boost::bind(&AreaManager::OnRecvAttack, &AreaManager::GetInstance(), _1, _2));
	AddPacketFunction(RespawnRequest, boost::bind(&ClientStateActive::OnRecvRespawnRequest, this, _2));
}

// 開始時の処理.
void ClientStateActive::BeginState()
{
	LoadCharacter();
}


// キャラクタロード
void ClientStateActive::LoadCharacter()
{
	Client *pClient = GetParent();

	int MaxHp = 0;
	int Atk = 0;
	int Def = 0;
	int Exp = 0;
	if (!DBConnection::GetInstance().LoadCharacterParameter(pClient->GetCustomerId(), MaxHp, Atk, Def, Exp))
	{
		std::cout << "Character Status Load Failed..." << std::endl;
		return;
	}
	pClient->CreateCharacter(MaxHp, Atk, Def, Exp);

	PacketCharacterStatus Packet(pClient->GetUuid(), MaxHp, MaxHp, Atk, Def, Exp);
	pClient->SendPacket(&Packet);
}

// ゲーム準備完了を受信.
void ClientStateActive::OnRecvGameReady(MemoryStreamInterface *pStream)
{
	PacketGameReady Packet;
	Packet.Serialize(pStream);		// ぶっちゃけいらないんじゃね？

	// プレイヤーキャラをWorldにブチ込む。
	PlayerCharacterPtr pPlayerChara = GetParent()->GetCharacter();
	AreaPtr pArea = AreaManager::GetInstance().Get(1);
	pArea.lock()->AddPlayerCharacter(pPlayerChara);
}

// リスポン要求を受信した。
void ClientStateActive::OnRecvRespawnRequest(MemoryStreamInterface *pStream)
{
	PacketRespawnRequest Packet;
	Packet.Serialize(pStream);

	PlayerCharacterPtr pChara = GetParent()->GetCharacter();
	pChara.lock()->Respawn();

	// @TODO:ロビーにリスポンさせたい。
	Vector2D Pos = pChara.lock()->GetPosition();
	PacketPlayerRespawn RespawnPacket(pChara.lock()->GetUuid(), Pos.X, Pos.Y);
	AreaPtr pArea = pChara.lock()->GetArea();
	pArea.lock()->BroadcastPacket(&RespawnPacket);
}
