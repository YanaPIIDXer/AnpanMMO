/**
 * @file ClientStateAreaChange.cpp
 * @brief クライアントステート：エリア切り替え
 * @author YanaP
 */
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
	AddPacketFunction(PacketID::Ping, boost::bind(&ClientStateAreaChange::OnRecvPing, this, _2));
	AddPacketFunction(PacketID::GameReady, boost::bind(&ClientStateAreaChange::OnRecvGameReady, this, _2));
}


// Pingを受信.
bool ClientStateAreaChange::OnRecvPing(MemoryStreamInterface *pStream)
{
	PacketPing Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	// そのまま投げ返す。
	GetParent()->SendPacket(&Packet);

	return true;
}

// ゲーム準備完了を受信.
bool ClientStateAreaChange::OnRecvGameReady(MemoryStreamInterface *pStream)
{
	PacketGameReady Packet;
	if (!Packet.Serialize(pStream)) { return false; }

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

	return true;
}
