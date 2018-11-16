#include "stdafx.h"
#include  "ClientStateActive.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "DBConnection.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "Area/AreaManager.h"
#include "Master/MasterData.h"
#include "ClientStateAreaChange.h"
#include "Packet/PacketCharacterStatus.h"
#include "Packet/PacketAreaMove.h"
#include "Packet/PacketAreaMoveRequest.h"
#include "Packet/PacketAreaMoveResponse.h"
#include "Packet/PacketRespawnRequest.h"
#include "Packet/PacketPlayerRespawn.h"

// コンストラクタ
ClientStateActive::ClientStateActive(Client *pInParent)
	: ClientStateBase(pInParent)
{
	AddPacketFunction(MovePlayer, boost::bind(&AreaManager::OnRecvMove, &AreaManager::GetInstance(), _1, _2));
	AddPacketFunction(Attack, boost::bind(&AreaManager::OnRecvAttack, &AreaManager::GetInstance(), _1, _2));
	AddPacketFunction(AreaMoveRequest, boost::bind(&ClientStateActive::OnRecvAreaMoveRequest, this, _2));
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

// エリア移動要求を受信した。
void ClientStateActive::OnRecvAreaMoveRequest(MemoryStreamInterface *pStream)
{
	PacketAreaMoveRequest Packet;
	Packet.Serialize(pStream);

	const WarpDataItem *pItem = MasterData::GetInstance().GetWarpDataMaster().GetItem(Packet.AreaMoveId);
	PlayerCharacter *pPlayer = GetParent()->GetCharacter().lock().get();
	AreaPtr pArea = pPlayer->GetArea();
	pArea.lock()->RemovePlayerCharacter(pPlayer->GetUuid());

	ClientStateAreaChange *pNewState = new ClientStateAreaChange(GetParent(), pItem->AreaId, Vector2D(pItem->X, pItem->Y));
	GetParent()->ChangeState(pNewState);

	PacketAreaMoveResponse ResponsePacket(PacketAreaMoveResponse::Success);
	GetParent()->SendPacket(&ResponsePacket);
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
