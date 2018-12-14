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
#include "Time/TimeManager.h"
#include "CacheServer/CacheServerConnection.h"
#include "Packet/PacketPing.h"
#include "Packet/PacketMovePlayer.h"
#include "Packet/PacketSendChat.h"
#include "Packet/WordCheckPacketChatRequest.h"
#include "Packet/WordCheckPacketChatResult.h"
#include "Packet/PacketReceiveChat.h"
#include "Packet/PacketAreaMove.h"
#include "Packet/PacketAreaMoveRequest.h"
#include "Packet/PacketAreaMoveResponse.h"
#include "Packet/PacketRespawnRequest.h"
#include "Packet/PacketSkillUse.h"
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
#include "Packet/PacketTime.h"
#include "Packet/PacketNPCTalk.h"
#include "Packet/PacketNPCTalkSelection.h"
#include "Packet/PacketSaveSkillList.h"
#include "Packet/CachePacketSaveSkillListRequest.h"
#include "Packet/PacketSkillTreeOpenRequest.h"
#include "Packet/PacketSkillTreeOpenResult.h"
#include "Packet/CachePacketOpenSkillTree.h"

// コンストラクタ
ClientStateActive::ClientStateActive(Client *pInParent)
	: ClientStateBase(pInParent)
{
	AddPacketFunction(Ping, boost::bind(&ClientStateActive::OnRecvPing, this, _2));
	AddPacketFunction(MovePlayer, boost::bind(&ClientStateActive::OnRecvMove, this, _2));
	AddPacketFunction(SendChat, boost::bind(&ClientStateActive::OnRecvChat, this, _2));
	AddPacketFunction(WordCheckChatResult, boost::bind(&ClientStateActive::OnRecvChatWordCheckResult, this, _2));
	AddPacketFunction(AreaMoveRequest, boost::bind(&ClientStateActive::OnRecvAreaMoveRequest, this, _2));
	AddPacketFunction(RespawnRequest, boost::bind(&ClientStateActive::OnRecvRespawnRequest, this, _2));
	AddPacketFunction(SkillUse, boost::bind(&ClientStateActive::OnRecvSkillUse, this, _2));
	AddPacketFunction(PartyCreateRequest, boost::bind(&ClientStateActive::OnRecvPartyCraeteRequest, this, _2));
	AddPacketFunction(PartyDissolutionRequest, boost::bind(&ClientStateActive::OnRecvPartyDissolutionRequest, this, _2));
	AddPacketFunction(PartyExitRequest, boost::bind(&ClientStateActive::OnRecvPartyExitRequest, this, _2));
	AddPacketFunction(PartyKickRequest, boost::bind(&ClientStateActive::OnRecvPartyKickRequest, this, _2));
	AddPacketFunction(PartyInviteRequest, boost::bind(&ClientStateActive::OnRecvPartyInviteRequest, this, _2));
	AddPacketFunction(PartyInviteResponse, boost::bind(&ClientStateActive::OnRecvPartyInviteResponse, this, _2));
	AddPacketFunction(InstanceAreaTicketProcess, boost::bind(&ClientStateActive::OnRecvInstanceAreaTicketProcess, this, _2));
	AddPacketFunction(NPCTalk, boost::bind(&ClientStateActive::OnRecvNPCTalk, this, _2));
	AddPacketFunction(NPCTalkSelection, boost::bind(&ClientStateActive::OnRecvNPCTalkSelection, this, _2));
	AddPacketFunction(SaveSkillList, boost::bind(&ClientStateActive::OnRecvSaveSkillListRequest, this, _2));
	AddPacketFunction(SkillTreeOpenRequest, boost::bind(&ClientStateActive::OnRecvSkillTreeOpenRequest, this, _2));
}

// State開始時の処理.
void ClientStateActive::BeginState()
{
	// 時間を通知.
	u32 TimeMasterId = TimeManager::GetInstance().GetMasterId();
	PacketTime Packet(TimeMasterId);
	GetParent()->SendPacket(&Packet);
}


// Pingを受信した。
void ClientStateActive::OnRecvPing(MemoryStreamInterface *pStream)
{
	PacketPing Packet;
	Packet.Serialize(pStream);

	// そのまま投げ返す。
	GetParent()->SendPacket(&Packet);
}

// 移動を受信した。
void ClientStateActive::OnRecvMove(MemoryStreamInterface *pStream)
{
	PacketMovePlayer Packet;
	Packet.Serialize(pStream);

	AreaPtr pArea = GetParent()->GetCharacter().lock()->GetArea();
	pArea.lock()->OnRecvMove(GetParent()->GetUuid(), Packet.X, Packet.Y, Packet.Z, Packet.Rotation);
}

// チャットを受信した。
void ClientStateActive::OnRecvChat(MemoryStreamInterface *pStream)
{
	PacketSendChat Packet;
	Packet.Serialize(pStream);

	// メッセージが空の時は何もしない。
	if (Packet.Message == "") { return; }

	// ワードチェックサーバに投げる。
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
		Vector3D StartPosition(pItem->X, pItem->Y, pItem->Z);
		InstanceAreaTicket *pTicket = InstanceAreaTicketManager::GetInstance().Publish(pItem->AreaId, StartPosition);
		
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

// スキル使用を受信した。
void ClientStateActive::OnRecvSkillUse(MemoryStreamInterface *pStream)
{
	PacketSkillUse Packet;
	Packet.Serialize(pStream);

	AreaPtr pArea = GetParent()->GetCharacter().lock()->GetArea();
	pArea.lock()->OnRecvSkillUse(GetParent()->GetUuid(), Packet.SkillId, Packet.TargetType, Packet.TargetUuid);
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
		AreaPtr pArea = AreaManager::GetInstance().CreateInstanceArea(pTicket->GetAreaId());
		pTicket->EnterToInstanceArea(pArea);

		// チケットは破棄。
		InstanceAreaTicketManager::GetInstance().Remove(Packet.TicketId);
	}
	else if (!pTicket->IsWaiting() && pTicket->IsDiscard())
	{
		// 一人でもチケットを破棄したクライアントがいれば破棄。
		pTicket->BroadcastDiscardPacket();
		InstanceAreaTicketManager::GetInstance().Remove(Packet.TicketId);
	}
}

// NPCとの会話を受信した。
void ClientStateActive::OnRecvNPCTalk(MemoryStreamInterface *pStream)
{
	PacketNPCTalk Packet;
	Packet.Serialize(pStream);

	const NPCItem *pItem = MasterData::GetInstance().GetNPCMaster().GetItem(Packet.MasterId);
	GetParent()->GetScript()->LoadAndRun(pItem->ScriptName);
}

// NPCとの会話での選択肢を受信した。
void ClientStateActive::OnRecvNPCTalkSelection(MemoryStreamInterface *pStream)
{
	PacketNPCTalkSelection Packet;
	Packet.Serialize(pStream);

	GetParent()->GetScript()->OnSelectedSelection(Packet.Index);
}

// スキルリスト保存リクエストを受信した。
void ClientStateActive::OnRecvSaveSkillListRequest(MemoryStreamInterface *pStream)
{
	PacketSaveSkillList Packet;
	Packet.Serialize(pStream);

	CachePacketSaveSkillListRequest CachePacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId(), Packet.Skill1, Packet.Skill2, Packet.Skill3, Packet.Skill4);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}

// スキルツリー開放要求を受信した。
void ClientStateActive::OnRecvSkillTreeOpenRequest(MemoryStreamInterface *pStream)
{
	PacketSkillTreeOpenRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = GetParent()->GetCharacter().lock()->OpenSkillTree(Packet.NodeId);

	PacketSkillTreeOpenResult ResultPacket(Result);
	GetParent()->SendPacket(&ResultPacket);

	if (Result == PacketSkillTreeOpenResult::Success)
	{
		CachePacketOpenSkillTree CachePacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId(), Packet.NodeId);
		CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
	}
}
