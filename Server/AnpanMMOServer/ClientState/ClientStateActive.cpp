#include "stdafx.h"
#include  "ClientStateActive.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Client.h"
#include "ClientManager.h"
#include "Config.h"
#include "Character/Player/PlayerCharacter.h"
#include "Area/AreaManager.h"
#include "Master/MasterData.h"
#include "WordCheckServer/WordCheckServerConnection.h"
#include "Party/PartyManager.h"
#include "ClientStateAreaChange.h"
#include "Area/InstanceAreaTicket.h"
#include "Area/InstanceAreaTicketManager.h"
#include "Packet/PacketMovePlayer.h"
#include "Packet/PacketAttack.h"
#include "Packet/PacketSendChat.h"
#include "Packet/WordCheckPacketChatRequest.h"
#include "Packet/WordCheckPacketChatResult.h"
#include "Packet/PacketReceiveChat.h"
#include "Packet/PacketAreaMove.h"
#include "Packet/PacketAreaMoveRequest.h"
#include "Packet/PacketAreaMoveResponse.h"
#include "Packet/PacketRespawnRequest.h"
#include "Packet/PacketPlayerRespawn.h"
#include "Packet/PacketPartyCreateRequest.h"
#include "Packet/PacketPartyCreateResult.h"
#include "Packet/PacketPartyDissolutionRequest.h"
#include "Packet/PacketPartyDissolutionResult.h"
#include "Packet/PacketPartyExitRequest.h"
#include "Packet/PacketPartyExitResult.h"
#include "Packet/PacketPartyExit.h"
#include "Packet/PacketPartyKickRequest.h"
#include "Packet/PacketPartyKickResult.h"
#include "Packet/PacketPartyKick.h"
#include "Packet/PacketPartyInviteRequest.h"
#include "Packet/PacketReceiveNotice.h"
#include "Packet/PacketPartyInviteResult.h"
#include "Packet/PacketPartyInviteResponse.h"
#include "Packet/PacketInstanceAreaTicketProcess.h"

// コンストラクタ
ClientStateActive::ClientStateActive(Client *pInParent)
	: ClientStateBase(pInParent)
{
	AddPacketFunction(MovePlayer, boost::bind(&ClientStateActive::OnRecvMove, this, _2));
	AddPacketFunction(Attack, boost::bind(&ClientStateActive::OnRecvAttack, this, _2));
	AddPacketFunction(SendChat, boost::bind(&ClientStateActive::OnRecvChat, this, _2));
	AddPacketFunction(WordCheckChatResult, boost::bind(&ClientStateActive::OnRecvChatWordCheckResult, this, _2));
	AddPacketFunction(AreaMoveRequest, boost::bind(&ClientStateActive::OnRecvAreaMoveRequest, this, _2));
	AddPacketFunction(RespawnRequest, boost::bind(&ClientStateActive::OnRecvRespawnRequest, this, _2));
	AddPacketFunction(PartyCreateRequest, boost::bind(&ClientStateActive::OnRecvPartyCraeteRequest, this, _2));
	AddPacketFunction(PartyDissolutionRequest, boost::bind(&ClientStateActive::OnRecvPartyDissolutionRequest, this, _2));
	AddPacketFunction(PartyExitRequest, boost::bind(&ClientStateActive::OnRecvPartyExitRequest, this, _2));
	AddPacketFunction(PartyKickRequest, boost::bind(&ClientStateActive::OnRecvPartyKickRequest, this, _2));
	AddPacketFunction(PartyInviteRequest, boost::bind(&ClientStateActive::OnRecvPartyInviteRequest, this, _2));
	AddPacketFunction(PartyInviteResponse, boost::bind(&ClientStateActive::OnRecvPartyInviteResponse, this, _2));
	AddPacketFunction(InstanceAreaTicketProcess, boost::bind(&ClientStateActive::OnRecvInstanceAreaTicketProcess, this, _2));
}


// 移動を受信した。
void ClientStateActive::OnRecvMove(MemoryStreamInterface *pStream)
{
	PacketMovePlayer Packet;
	Packet.Serialize(pStream);

	AreaPtr pArea = GetParent()->GetCharacter().lock()->GetArea();
	pArea.lock()->OnRecvMove(GetParent()->GetUuid(), Packet.X, Packet.Y, Packet.Z, Packet.Rotation);
}

// 攻撃を受信した。
void ClientStateActive::OnRecvAttack(MemoryStreamInterface *pStream)
{
	PacketAttack Packet;
	Packet.Serialize(pStream);

	AreaPtr pArea = GetParent()->GetCharacter().lock()->GetArea();
	pArea.lock()->OnRecvAttack(GetParent()->GetUuid(), Packet.TargetUuid);
}

// チャットを受信した。
void ClientStateActive::OnRecvChat(MemoryStreamInterface *pStream)
{
	PacketSendChat Packet;
	Packet.Serialize(pStream);

	WordCheckPacketChatRequest WordCheckPacket(GetParent()->GetUuid(), Packet.Type, Packet.Message);
	WordCheckServerConnection::GetInstance()->SendPacket(&WordCheckPacket);
}

// チャットのワードチェック結果を受信した。
void ClientStateActive::OnRecvChatWordCheckResult(MemoryStreamInterface *pStream)
{
	WordCheckPacketChatResult Packet;
	Packet.Serialize(pStream);

	PlayerCharacterPtr pCharacter = GetParent()->GetCharacter();
	PacketReceiveChat RecvPacket(GetParent()->GetUuid(), pCharacter.lock()->GetName(), Packet.Message);
	AreaPtr pArea = pCharacter.lock()->GetArea();
	switch (Packet.Type)
	{
		case PacketSendChat::Say:

			pArea.lock()->BroadcastPacketWithRange(&RecvPacket, pCharacter.lock()->GetPosition(), Config::SayRange);
			break;

		case PacketSendChat::Shout:

			pArea.lock()->BroadcastPacket(&RecvPacket);
			break;

	}
}

// エリア移動要求を受信した。
void ClientStateActive::OnRecvAreaMoveRequest(MemoryStreamInterface *pStream)
{
	PacketAreaMoveRequest Packet;
	Packet.Serialize(pStream);

	const WarpDataItem *pItem = MasterData::GetInstance().GetWarpDataMaster().GetItem(Packet.AreaMoveId);
	const AreaItem *pAreaItem = MasterData::GetInstance().GetAreaMaster().GetItem(pItem->AreaId);
	if (pAreaItem->Type != AreaItem::INSTANCE_AREA)
	{
		// 通常マップへの移動。
		PlayerCharacter *pPlayer = GetParent()->GetCharacter().lock().get();
		AreaPtr pArea = pPlayer->GetArea();
		pArea.lock()->RemovePlayerCharacter(pPlayer->GetUuid());

		PacketAreaMoveResponse ResponsePacket(PacketAreaMoveResponse::Success);
		GetParent()->SendPacket(&ResponsePacket);

		ClientStateAreaChange *pNewState = new ClientStateAreaChange(GetParent(), pItem->AreaId, Vector3D(pItem->X, pItem->Y, pItem->Z));
		GetParent()->ChangeState(pNewState);
	}
	else
	{
		// インスタンスマップへの移動を試みた。
		InstanceAreaTicket *pTicket = InstanceAreaTicketManager::GetInstance().Publish(pItem->AreaId);
		
		PartyPtr pParty = GetParent()->GetCharacter().lock()->GetParty();
		if (pParty.expired())
		{
			// ソロ
			ClientPtr pSelf = ClientManager::GetInstance().Get(GetParent()->GetUuid());
			pTicket->AddClient(pSelf);
		}
		else
		{
			// パーティに入っていた場合はメンバ全員を招待。
			std::vector<PlayerCharacterPtr> Players = pParty.lock()->GetMemberList();
			for (u32 i = 0; i < Players.size(); i++)
			{
				ClientPtr pClient = ClientManager::GetInstance().Get(Players[i].lock()->GetClient()->GetUuid());
				pTicket->AddClient(pClient);
			}
		}
		
		// 発行チケットをバラ撒く。
		pTicket->BroadcastPublishPacket();
	}
}

// リスポン要求を受信した。
void ClientStateActive::OnRecvRespawnRequest(MemoryStreamInterface *pStream)
{
	PacketRespawnRequest Packet;
	Packet.Serialize(pStream);

	PlayerCharacterPtr pChara = GetParent()->GetCharacter();
	pChara.lock()->Respawn();

	PacketPlayerRespawn RespawnPacket(pChara.lock()->GetUuid(), 0.0f, 0.0f, 0.0f);
	GetParent()->SendPacket(&RespawnPacket);

	// ロビーにリスポンする。
	PacketAreaMoveResponse AreaMovePacket(PacketAreaMoveResponse::Success);
	GetParent()->SendPacket(&AreaMovePacket);

	AreaPtr pArea = pChara.lock()->GetArea();
	pArea.lock()->RemovePlayerCharacter(pChara.lock()->GetUuid());

	ClientStateAreaChange *pNewState = new ClientStateAreaChange(GetParent(), 1, Vector3D(-1000.0f, 0.0f, 0.0f));
	GetParent()->ChangeState(pNewState);
}

// パーティ作成要求を受信した。
void ClientStateActive::OnRecvPartyCraeteRequest(MemoryStreamInterface *pStream)
{
	PacketPartyCreateRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = PacketPartyCreateResult::Success;
	if (PartyManager::GetInstance().IsAlreadyJoined(GetParent()->GetUuid()))
	{
		// 既にどこかのパーティに参加済み。
		Result = PacketPartyCreateResult::AlreadyJoin;
	}

	u32 PartyId = 0;
	if (Result == PacketPartyCreateResult::Success)
	{
		// パーティ作成.
		PartyManager::GetInstance().Create(GetParent()->GetCharacter());
		PartyId = GetParent()->GetCharacter().lock()->GetParty().lock()->GetUuid();
	}
	PacketPartyCreateResult ResultPacket(Result, PartyId);
	GetParent()->SendPacket(&ResultPacket);
}

// パーティ離脱要求を受信した。
void ClientStateActive::OnRecvPartyDissolutionRequest(MemoryStreamInterface *pStream)
{
	PacketPartyDissolutionRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = PacketPartyDissolutionResult::Success;
	if (!PartyManager::GetInstance().Dissolution(GetParent()->GetUuid()))
	{
		Result = PacketPartyDissolutionResult::Error;
	}
	
	PacketPartyDissolutionResult ResultPacket(Result);
	GetParent()->SendPacket(&ResultPacket);
}

// パーティ離脱要求を受信した。
void ClientStateActive::OnRecvPartyExitRequest(MemoryStreamInterface *pStream)
{
	PacketPartyExitRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = PacketPartyExitResult::Success;
	PartyPtr pParty = GetParent()->GetCharacter().lock()->GetParty();
	if (!pParty.expired())
	{
		pParty.lock()->Exit(GetParent()->GetUuid());

		// 離脱パケットをバラ撒く。
		PacketPartyExit Packet(GetParent()->GetUuid());
		pParty.lock()->BroadcastPacket(&Packet);
	}
	else
	{
		Result = PacketPartyExitResult::Error;
	}

	PacketPartyExitResult ResultPacket(Result);
	GetParent()->SendPacket(&ResultPacket);
}

// パーティキック要求を受信した。
void ClientStateActive::OnRecvPartyKickRequest(MemoryStreamInterface *pStream)
{
	PacketPartyKickRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = PacketPartyKickResult::Success;
	PartyPtr pParty = GetParent()->GetCharacter().lock()->GetParty();
	if (!pParty.expired())
	{
		// 実際に離脱させる前にキックパケットをバラ撒く.
		PacketPartyKick KickPacket(Packet.Uuid);
		pParty.lock()->BroadcastPacket(&KickPacket);

		pParty.lock()->Exit(Packet.Uuid);
	}
	else
	{
		Result = PacketPartyKickResult::Error;
	}

	PacketPartyKickResult ResultPacket(Result);
	GetParent()->SendPacket(&ResultPacket);
}

// パーティ勧誘要求を受信した。
void ClientStateActive::OnRecvPartyInviteRequest(MemoryStreamInterface *pStream)
{
	PacketPartyInviteRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = PacketPartyInviteResult::Success;
	ClientPtr pTargetClient = ClientManager::GetInstance().Get(Packet.TargetUuid);
	if (!pTargetClient.expired())
	{
		if (pTargetClient.lock()->GetCharacter().lock()->GetParty().expired())
		{
			NoticeData Notice(NoticeData::PartyInvide, GetParent()->GetCustomerId(), GetParent()->GetCharacter().lock()->GetName());
			PacketReceiveNotice NoticePacket(Notice);
			pTargetClient.lock()->SendPacket(&NoticePacket);
		}
		else
		{
			Result = PacketPartyInviteResult::AlreadyJoinOtherParty;
		}
	}
	else
	{
		Result = PacketPartyInviteResult::Error;
	}

	PacketPartyInviteResult ResultPacket(Result);
	GetParent()->SendPacket(&ResultPacket);
}

// パーティ勧誘レスポンスを受けた。
void ClientStateActive::OnRecvPartyInviteResponse(MemoryStreamInterface *pStream)
{
	PacketPartyInviteResponse Packet;
	Packet.Serialize(pStream);

	ClientPtr pTargetClient = ClientManager::GetInstance().GetFromCustomerId(Packet.CustomerId);

	// レスポンス待ちの間に落ちた等のケース
	// @TODO:レスポンス投げたクライアントには何も通知しなくていいの？
	if (pTargetClient.expired()) { return; }

	if (Packet.Response == PacketPartyInviteResponse::Refuse)
	{
		// @TODO:pTargetClientに対して通知を投げる。
		return;
	}

	PartyPtr pParty = pTargetClient.lock()->GetCharacter().lock()->GetParty();

	// レスポンス待ちの間にパーティを解散した等のケース
	// @TODO:レスポンス投げたクライアントには何も通知しなくていいの？
	if (pParty.expired()) { return; }

	// レスポンス待ちの間にメンバーが最大になった場合。
	// @TODO:レスポンス投げたクライアントには何も通知しなくていいの？
	if (pParty.lock()->IsMaximumMember()) { return; }

	pParty.lock()->Join(GetParent()->GetCharacter());
}

// インスタンスマップチケットの処理を受信した。
void ClientStateActive::OnRecvInstanceAreaTicketProcess(MemoryStreamInterface *pStream)
{
	PacketInstanceAreaTicketProcess Packet;
	Packet.Serialize(pStream);

	InstanceAreaTicket *pTicket = InstanceAreaTicketManager::GetInstance().Get(Packet.TicketId);
	if (pTicket == NULL) { return; }
	ETicketState State;
	switch (Packet.Process)
	{
		case PacketInstanceAreaTicketProcess::Enter:

			State = TicketStateEnter;
			break;

		case PacketInstanceAreaTicketProcess::Discard:

			State = TicketStateDiscard;
			break;
	}
	pTicket->RecvProcess(GetParent()->GetUuid(), State);

	if (pTicket->IsReady())
	{
		// 準備が完了したのでインスタンスマップを生成してメンバ全員を飛ばす。


		// チケットは破棄。
		InstanceAreaTicketManager::GetInstance().Remove(Packet.TicketId);
	}
	else if (!pTicket->IsWaiting() && pTicket->IsDiscard())
	{
		// 一人でもチケットを破棄したクライアントがいれば破棄。
		InstanceAreaTicketManager::GetInstance().Remove(Packet.TicketId);
		// @TODO:通知.
	}
}
