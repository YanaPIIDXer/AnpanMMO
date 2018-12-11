#include "stdafx.h"
#include "ClientStateAreaChange.h"
#include "Client.h"
#include "PlayerManager.h"
#include "Character/Player/PlayerCharacter.h"
#include "Area/AreaManager.h"
#include "ClientStateActive.h"
#include "Packet/PacketPing.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketAreaMove.h"

// コンストラクタ
ClientStateAreaChange::ClientStateAreaChange(Client *pInParent, u32 InAreaId, const Vector3D &InPosition)
	: ClientStateBase(pInParent)
	, AreaId(InAreaId)
	, Position(InPosition)
{
	AddPacketFunction(Ping, boost::bind(&ClientStateAreaChange::OnRecvPing, this, _2));
	AddPacketFunction(GameReady, boost::bind(&ClientStateAreaChange::OnRecvGameReady, this, _2));
}


// Pingを受信.
void ClientStateAreaChange::OnRecvPing(MemoryStreamInterface *pStream)
{
	PacketPing Packet;
	Packet.Serialize(pStream);

	// そのまま投げ返す。
	GetParent()->SendPacket(&Packet);
}

// ゲーム準備完了を受信.
void ClientStateAreaChange::OnRecvGameReady(MemoryStreamInterface *pStream)
{
	PacketGameReady Packet;
	Packet.Serialize(pStream);		// ぶっちゃけいらないんじゃね？

	PlayerCharacterPtr pPlayerChara = GetParent()->GetCharacter();
	pPlayerChara.lock()->SetPosition(Position);
	AreaPtr pArea = AreaManager::GetInstance().Get(AreaId);
	pArea.lock()->AddPlayerCharacter(pPlayerChara);
	pPlayerChara.lock()->OnAreaChange();

	// エリア移動をクライアントに通知.
	PacketAreaMove AreaMovePacket(AreaId, Position.X, Position.Y, Position.Z);
	GetParent()->SendPacket(&AreaMovePacket);

	// アクティブ状態へ。
	ClientStateActive *pNewState = new ClientStateActive(GetParent());
	GetParent()->ChangeState(pNewState);
}
