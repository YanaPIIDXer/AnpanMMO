#include "stdafx.h"
#include "ClientStateAreaChange.h"
#include "Client.h"
#include "PlayerManager.h"
#include "Character/Player/PlayerCharacter.h"
#include "Area/AreaManager.h"
#include "ClientStateActive.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketAreaMove.h"

// コンストラクタ
ClientStateAreaChange::ClientStateAreaChange(Client *pInParent, u32 InAreaId, const Vector2D &InPosition)
	: ClientStateBase(pInParent)
	, AreaId(InAreaId)
	, Position(InPosition)
{
	AddPacketFunction(GameReady, boost::bind(&ClientStateAreaChange::OnRecvGameReady, this, _2));
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

	// エリア移動をクライアントに通知.
	PacketAreaMove AreaMovePacket(AreaId, Position.X, Position.Y);
	GetParent()->SendPacket(&AreaMovePacket);

	// アクティブ状態へ。
	ClientStateActive *pNewState = new ClientStateActive(GetParent());
	GetParent()->ChangeState(pNewState);
}
