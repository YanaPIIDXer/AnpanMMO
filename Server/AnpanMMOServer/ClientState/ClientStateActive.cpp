/**
 * @file ClientStateActive.cpp
 * @brief クライアントステート：ゲーム中
 * @author YanaP
 */
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
#include "GMCommand/GMCommandParser.h"
#include "GMCommand/GMCommandExecuter.h"
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
#include "Packet/PacketSaveSkillListRequest.h"
#include "Packet/PacketSaveSkillListResponse.h"
#include "Packet/CachePacketSaveSkillListRequest.h"
#include "Packet/CachePacketSaveSkillListResponse.h"
#include "Packet/PacketSkillTreeOpenRequest.h"
#include "Packet/PacketSkillTreeOpenResult.h"
#include "Packet/CachePacketOpenSkillTree.h"
#include "Packet/PacketItemUse.h"
#include "Packet/PacketItemSubtractRequest.h"
#include "Packet/PacketSaveItemShortcutRequest.h"
#include "Packet/CachePacketSaveItemShortcutRequest.h"
#include "Packet/CachePacketSaveItemShortcutResponse.h"
#include "Packet/PacketSaveItemShortcutResult.h"
#include "Packet/PacketQuestRetireRequest.h"
#include "Packet/PacketQuestRetireResponse.h"
#include "Packet/PacketSaveActiveQuest.h"
#include "Packet/CachePacketSaveActiveQuestRequest.h"
#include "Packet/PacketChangeEquipRequest.h"
#include "Packet/PacketChangeEquipResult.h"
#include "Packet/CachePacketSaveEquipRequest.h"
#include "Packet/CachePacketSaveEquipResponse.h"
#include "Packet/PacketBuyItemRequest.h"
#include "Packet/PacketBuyItemResult.h"
#include "Packet/PacketSellItemRequest.h"
#include "Packet/PacketSellItemResult.h"
#include "Packet/PacketExitShop.h"
#include "Packet/PacketMailListRequest.h"
#include "Packet/CachePacketMailListRequest.h"
#include "Packet/CachePacketMailListResponse.h"
#include "Packet/PacketMailList.h"
#include "Packet/PacketMailRead.h"
#include "Packet/CachePacketMailRead.h"
#include "Packet/PacketMailAttachmentRecvRequest.h"
#include "Packet/PacketMailAttachmentRecvResult.h"
#include "Packet/CachePacketMailAttachmentRecvRequest.h"
#include "Packet/CachePacketMailAttachmentRecvResult.h"

// コンストラクタ
ClientStateActive::ClientStateActive(Client *pInParent)
	: ClientStateBase(pInParent)
{
	AddPacketFunction(PacketID::Ping, boost::bind(&ClientStateActive::OnRecvPing, this, _2));
	AddPacketFunction(PacketID::MovePlayer, boost::bind(&ClientStateActive::OnRecvMove, this, _2));
	AddPacketFunction(PacketID::SendChat, boost::bind(&ClientStateActive::OnRecvChat, this, _2));
	AddPacketFunction(WordCheckPacketID::WordCheckChatResult, boost::bind(&ClientStateActive::OnRecvChatWordCheckResult, this, _2));
	AddPacketFunction(PacketID::AreaMoveRequest, boost::bind(&ClientStateActive::OnRecvAreaMoveRequest, this, _2));
	AddPacketFunction(PacketID::RespawnRequest, boost::bind(&ClientStateActive::OnRecvRespawnRequest, this, _2));
	AddPacketFunction(PacketID::SkillUse, boost::bind(&ClientStateActive::OnRecvSkillUse, this, _2));
	AddPacketFunction(PacketID::PartyCreateRequest, boost::bind(&ClientStateActive::OnRecvPartyCraeteRequest, this, _2));
	AddPacketFunction(PacketID::PartyDissolutionRequest, boost::bind(&ClientStateActive::OnRecvPartyDissolutionRequest, this, _2));
	AddPacketFunction(PacketID::PartyExitRequest, boost::bind(&ClientStateActive::OnRecvPartyExitRequest, this, _2));
	AddPacketFunction(PacketID::PartyKickRequest, boost::bind(&ClientStateActive::OnRecvPartyKickRequest, this, _2));
	AddPacketFunction(PacketID::PartyInviteRequest, boost::bind(&ClientStateActive::OnRecvPartyInviteRequest, this, _2));
	AddPacketFunction(PacketID::PartyInviteResponse, boost::bind(&ClientStateActive::OnRecvPartyInviteResponse, this, _2));
	AddPacketFunction(PacketID::InstanceAreaTicketProcess, boost::bind(&ClientStateActive::OnRecvInstanceAreaTicketProcess, this, _2));
	AddPacketFunction(PacketID::NPCTalk, boost::bind(&ClientStateActive::OnRecvNPCTalk, this, _2));
	AddPacketFunction(PacketID::NPCTalkSelection, boost::bind(&ClientStateActive::OnRecvNPCTalkSelection, this, _2));
	AddPacketFunction(PacketID::SaveSkillListRequest, boost::bind(&ClientStateActive::OnRecvSaveSkillListRequest, this, _2));
	AddPacketFunction(CachePacketID::CacheSaveSkillListResponse, boost::bind(&ClientStateActive::OnRecvCacheSaveSkillListResponse, this, _2));
	AddPacketFunction(PacketID::SkillTreeOpenRequest, boost::bind(&ClientStateActive::OnRecvSkillTreeOpenRequest, this, _2));
	AddPacketFunction(PacketID::ItemUse, boost::bind(&ClientStateActive::OnRecvItemUse, this, _2));
	AddPacketFunction(PacketID::ItemSubtractRequest, boost::bind(&ClientStateActive::OnRecvItemSubtractRequest, this, _2));
	AddPacketFunction(PacketID::SaveItemShortcutRequest, boost::bind(&ClientStateActive::OnRecvSaveItemShortcutRequest, this, _2));
	AddPacketFunction(CachePacketID::CacheSaveItemShortcutResponse, boost::bind(&ClientStateActive::OnRecvCacheSaveItemShortcutResponse, this, _2));
	AddPacketFunction(PacketID::QuestRetireRequest, boost::bind(&ClientStateActive::OnRecvQuestRetireRequest, this, _2));
	AddPacketFunction(PacketID::SaveActiveQuest, boost::bind(&ClientStateActive::OnRecvSaveActiveQuest, this, _2));
	AddPacketFunction(PacketID::ChangeEquipRequest, boost::bind(&ClientStateActive::OnRecvChangeEquipRequest, this, _2));
	AddPacketFunction(CachePacketID::CacheSaveEquipResponse, boost::bind(&ClientStateActive::OnRecvCacheSaveEquipResponse, this, _2));
	AddPacketFunction(PacketID::BuyItemRequest, boost::bind(&ClientStateActive::OnRecvBuyItemRequest, this, _2));
	AddPacketFunction(PacketID::SellItemRequest, boost::bind(&ClientStateActive::OnRecvSellItemRequest, this, _2));
	AddPacketFunction(PacketID::ExitShop, boost::bind(&ClientStateActive::OnRecvExitShop, this, _2));
	AddPacketFunction(PacketID::MailListRequest, boost::bind(&ClientStateActive::OnRecvMailListRequest, this, _2));
	AddPacketFunction(CachePacketID::CacheMailListResponse, boost::bind(&ClientStateActive::OnRecvCacheMailList, this, _2));
	AddPacketFunction(PacketID::MailRead, boost::bind(&ClientStateActive::OnRecvMailRead, this, _2));
	AddPacketFunction(PacketID::MailAttachmentRecvRequest, boost::bind(&ClientStateActive::OnRecvMailAttachmentRecvRequest, this, _2));
	AddPacketFunction(CachePacketID::CacheMailAttachmentRecvResult, boost::bind(&ClientStateActive::OnRecvCacheMailAttachmentRecvResult, this, _2));
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
bool ClientStateActive::OnRecvPing(MemoryStreamInterface *pStream)
{
	PacketPing Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	// そのまま投げ返す。
	GetParent()->SendPacket(&Packet);

	return true;
}

// 移動を受信した。
bool ClientStateActive::OnRecvMove(MemoryStreamInterface *pStream)
{
	PacketMovePlayer Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	AreaPtr pArea = GetParent()->GetCharacter().lock()->GetArea();
	pArea.lock()->OnRecvMove(GetParent()->GetUuid(), Packet.X, Packet.Y, Packet.Z, Packet.Rotation);
	return true;
}

// チャットを受信した。
bool ClientStateActive::OnRecvChat(MemoryStreamInterface *pStream)
{
	PacketSendChat Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	// メッセージが空の時は何もしない。
	if (Packet.Message == "") { return true; }

	// ＧＭコマンド
	if (GetParent()->GetCharacter().lock()->IsGM())
	{
		GMCommandParser Parser(Packet.Message);
		if (Parser.IsCommand())
		{
			std::string ResultMessage = "Invalid GM Command.";

			GMCommandExecuter Executer(GetParent(), Parser);
			u8 Result = Executer.Execute();
			switch (Result)
			{
				case GMCommandExecuter::Success:

					ResultMessage = "GMCommand Success!";
					break;

				case GMCommandExecuter::InvalidCommand:

					ResultMessage = "Invalid GM Command.";
					break;

				case GMCommandExecuter::InvalidArg:

					ResultMessage = "Invalid Arg.";
					break;

				case GMCommandExecuter::InvalidItem:

					ResultMessage = "Invalid Item.";
					break;
			}

			PacketReceiveChat ResultPacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetName(), ResultMessage);
			GetParent()->SendPacket(&ResultPacket);
			return true;
		}
	}

	// ワードチェックサーバに投げる。
	WordCheckPacketChatRequest WordCheckPacket(GetParent()->GetUuid(), Packet.Type, Packet.Message);
	WordCheckServerConnection::GetInstance()->SendPacket(&WordCheckPacket);

	return true;
}

// チャットのワードチェック結果を受信した。
bool ClientStateActive::OnRecvChatWordCheckResult(MemoryStreamInterface *pStream)
{
	WordCheckPacketChatResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

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

	return true;
}

// エリア移動要求を受信した。
bool ClientStateActive::OnRecvAreaMoveRequest(MemoryStreamInterface *pStream)
{
	PacketAreaMoveRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

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

	return true;
}

// リスポン要求を受信した。
bool ClientStateActive::OnRecvRespawnRequest(MemoryStreamInterface *pStream)
{
	PacketRespawnRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

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

	return true;
}

// スキル使用を受信した。
bool ClientStateActive::OnRecvSkillUse(MemoryStreamInterface *pStream)
{
	PacketSkillUse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	AreaPtr pArea = GetParent()->GetCharacter().lock()->GetArea();
	pArea.lock()->OnRecvSkillUse(GetParent()->GetUuid(), Packet.SkillId, Packet.TargetType, Packet.TargetUuid);

	return true;
}

// パーティ作成要求を受信した。
bool ClientStateActive::OnRecvPartyCraeteRequest(MemoryStreamInterface *pStream)
{
	PacketPartyCreateRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

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

	return true;
}

// パーティ離脱要求を受信した。
bool ClientStateActive::OnRecvPartyDissolutionRequest(MemoryStreamInterface *pStream)
{
	PacketPartyDissolutionRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = PacketPartyDissolutionResult::Success;
	if (!PartyManager::GetInstance().Dissolution(GetParent()->GetUuid()))
	{
		Result = PacketPartyDissolutionResult::Error;
	}
	
	PacketPartyDissolutionResult ResultPacket(Result);
	GetParent()->SendPacket(&ResultPacket);

	return true;
}

// パーティ離脱要求を受信した。
bool ClientStateActive::OnRecvPartyExitRequest(MemoryStreamInterface *pStream)
{
	PacketPartyExitRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

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

	return true;
}

// パーティキック要求を受信した。
bool ClientStateActive::OnRecvPartyKickRequest(MemoryStreamInterface *pStream)
{
	PacketPartyKickRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

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

	return true;
}

// パーティ勧誘要求を受信した。
bool ClientStateActive::OnRecvPartyInviteRequest(MemoryStreamInterface *pStream)
{
	PacketPartyInviteRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

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

	return true;
}

// パーティ勧誘レスポンスを受けた。
bool ClientStateActive::OnRecvPartyInviteResponse(MemoryStreamInterface *pStream)
{
	PacketPartyInviteResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	ClientPtr pTargetClient = ClientManager::GetInstance().GetFromCustomerId(Packet.CustomerId);

	// レスポンス待ちの間に落ちた等のケース
	// @TODO:レスポンス投げたクライアントには何も通知しなくていいの？
	if (pTargetClient.expired()) { return true; }

	if (Packet.Response == PacketPartyInviteResponse::Refuse)
	{
		// @TODO:pTargetClientに対して通知を投げる。
		return true;
	}

	PartyPtr pParty = pTargetClient.lock()->GetCharacter().lock()->GetParty();

	// レスポンス待ちの間にパーティを解散した等のケース
	// @TODO:レスポンス投げたクライアントには何も通知しなくていいの？
	if (pParty.expired()) { return true; }

	// レスポンス待ちの間にメンバーが最大になった場合。
	// @TODO:レスポンス投げたクライアントには何も通知しなくていいの？
	if (pParty.lock()->IsMaximumMember()) { return true; }

	pParty.lock()->Join(GetParent()->GetCharacter());

	return true;
}

// インスタンスマップチケットの処理を受信した。
bool ClientStateActive::OnRecvInstanceAreaTicketProcess(MemoryStreamInterface *pStream)
{
	PacketInstanceAreaTicketProcess Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	InstanceAreaTicket *pTicket = InstanceAreaTicketManager::GetInstance().Get(Packet.TicketId);
	if (pTicket == NULL) { return true; }
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

	return true;
}

// NPCとの会話を受信した。
bool ClientStateActive::OnRecvNPCTalk(MemoryStreamInterface *pStream)
{
	PacketNPCTalk Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	const NPCItem *pItem = MasterData::GetInstance().GetNPCMaster().GetItem(Packet.MasterId);
	GetParent()->GetScript()->LoadAndRun(pItem->ScriptName);

	return true;
}

// NPCとの会話での選択肢を受信した。
bool ClientStateActive::OnRecvNPCTalkSelection(MemoryStreamInterface *pStream)
{
	PacketNPCTalkSelection Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	GetParent()->GetScript()->OnSelectedSelection(Packet.Index);

	return true;
}

// スキルリスト保存リクエストを受信した。
bool ClientStateActive::OnRecvSaveSkillListRequest(MemoryStreamInterface *pStream)
{
	PacketSaveSkillListRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CachePacketSaveSkillListRequest CachePacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId(), Packet.SkillId1, Packet.SkillId2, Packet.SkillId3, Packet.SkillId4);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);

	return true;
}

// キャッシュサーバからスキルリスト保存レスポンスを受信した。
bool ClientStateActive::OnRecvCacheSaveSkillListResponse(MemoryStreamInterface *pStream)
{
	CachePacketSaveSkillListResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = PacketSaveSkillListResponse::Success;
	if (Packet.Result != CachePacketSaveSkillListResponse::Success)
	{
		Result = PacketSaveSkillListResponse::Error;
	}

	PacketSaveSkillListResponse ResponsePacket(Result, Packet.SkillId1, Packet.SkillId2, Packet.SkillId3, Packet.SkillId4);
	GetParent()->SendPacket(&ResponsePacket);

	return true;
}

// スキルツリー開放要求を受信した。
bool ClientStateActive::OnRecvSkillTreeOpenRequest(MemoryStreamInterface *pStream)
{
	PacketSkillTreeOpenRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = GetParent()->GetCharacter().lock()->OpenSkillTree(Packet.NodeId);

	PacketSkillTreeOpenResult ResultPacket(Result, Packet.NodeId);
	GetParent()->SendPacket(&ResultPacket);

	if (Result == PacketSkillTreeOpenResult::Success)
	{
		CachePacketOpenSkillTree CachePacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId(), Packet.NodeId);
		CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
	}

	return true;
}

// アイテム使用を受信した。
bool ClientStateActive::OnRecvItemUse(MemoryStreamInterface *pStream)
{
	PacketItemUse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	GetParent()->GetCharacter().lock()->GetArea().lock()->OnRecvItemUse(GetParent()->GetUuid(), Packet.ItemId, Packet.TargetType, Packet.TargetUuid);

	return true;
}

// アイテム破棄リクエストを受信した。
bool ClientStateActive::OnRecvItemSubtractRequest(MemoryStreamInterface *pStream)
{
	PacketItemSubtractRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	GetParent()->GetCharacter().lock()->SubtractItem(Packet.ItemId, Packet.Count);

	return true;
}

// アイテムショートカット保存リクエストを受信した。
bool ClientStateActive::OnRecvSaveItemShortcutRequest(MemoryStreamInterface *pStream)
{
	PacketSaveItemShortcutRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CachePacketSaveItemShortcutRequest RequestPacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId(), Packet.ItemId1, Packet.ItemId2);
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);

	return true;
}

// キャッシュサーバからアイテムショートカット保存結果を受信した。
bool ClientStateActive::OnRecvCacheSaveItemShortcutResponse(MemoryStreamInterface *pStream)
{
	CachePacketSaveItemShortcutResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = PacketSaveItemShortcutResult::Success;
	if (Packet.Result != CachePacketSaveItemShortcutResponse::Success)
	{
		Result = PacketSaveItemShortcutResult::Error;
	}

	PacketSaveItemShortcutResult ResultPacket(Result, Packet.ItemId1, Packet.ItemId2);
	GetParent()->SendPacket(&ResultPacket);

	return true;
}

// クエスト破棄要求を受信した。
bool ClientStateActive::OnRecvQuestRetireRequest(MemoryStreamInterface *pStream)
{
	PacketQuestRetireRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = GetParent()->RetireQuest(Packet.QuestId);

	PacketQuestRetireResponse ResponsePacket(Packet.QuestId, Result);
	GetParent()->SendPacket(&ResponsePacket);

	return true;
}

// アクティブクエスト保存を受信した。
bool ClientStateActive::OnRecvSaveActiveQuest(MemoryStreamInterface *pStream)
{
	PacketSaveActiveQuest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CachePacketSaveActiveQuestRequest CachePacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId(), Packet.QuestId);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);

	return true;
}

// 装備変更リクエストを受信した。
bool ClientStateActive::OnRecvChangeEquipRequest(MemoryStreamInterface *pStream)
{
	PacketChangeEquipRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	// 右手装備チェック
	if (Packet.RightEquip == 0)
	{
		// 右手装備は外せない。
		PacketChangeEquipResult ResultPacket(PacketChangeEquipResult::CanNotRemoveRightEquip, 0, 0, 0);
		GetParent()->SendPacket(&ResultPacket);
		return true;
	}
	PlayerCharacter *pChara = GetParent()->GetCharacter().lock().get();
	const CharacterParameter &Param = pChara->GetParameter();

	s32 Count = pChara->GetItemList().GetCount(Packet.RightEquip);
	if (Param.GetRightEquip().GetEquipId() == Packet.RightEquip) { Count++; }
	if (Param.GetLeftEquip().GetEquipId() == Packet.RightEquip) { Count++; }
	if (Count <= 0)
	{
		// そもそも持ってない。
		PacketChangeEquipResult ResultPacket(PacketChangeEquipResult::NotPossession, 0, 0, 0);
		GetParent()->SendPacket(&ResultPacket);
		return true;
	}

	// 左手装備チェック
	if (Packet.LeftEquip != 0)
	{
		if (Packet.LeftEquip != Packet.RightEquip)
		{
			// カウントしなおし。
			Count = pChara->GetItemList().GetCount(Packet.LeftEquip);
			if (Param.GetRightEquip().GetEquipId() == Packet.LeftEquip) { Count++; }
			if (Param.GetLeftEquip().GetEquipId() == Packet.LeftEquip) { Count++; }
		}
		else
		{
			// 右手に装備する分減算する。
			Count--;
		}
		if (Count <= 0)
		{
			// そもそも持ってない。
			PacketChangeEquipResult ResultPacket(PacketChangeEquipResult::NotPossession, 0, 0, 0);
			GetParent()->SendPacket(&ResultPacket);
			return true;
		}
	}

	// 保存リクエスト送信.
	CachePacketSaveEquipRequest RequestPacket(GetParent()->GetUuid(), pChara->GetCharacterId(), Packet.RightEquip, Packet.LeftEquip);
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);

	return true;
}

// キャッシュサーバから装備保存レスポンスを受信した。
bool ClientStateActive::OnRecvCacheSaveEquipResponse(MemoryStreamInterface *pStream)
{
	CachePacketSaveEquipResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = PacketChangeEquipResult::Success;
	if (Packet.Result != CachePacketSaveEquipResponse::Success)
	{
		Result = PacketChangeEquipResult::Error;
	}

	if (Result == PacketChangeEquipResult::Success)
	{
		GetParent()->GetCharacter().lock()->ChangeEquip(Packet.RightEquip, Packet.LeftEquip);
	}

	PacketChangeEquipResult ResultPacket(Result, Packet.RightEquip, Packet.LeftEquip, GetParent()->GetCharacter().lock()->GetParameter().GetMaxHp());
	GetParent()->SendPacket(&ResultPacket);

	return true;
}

// アイテム購入要求を受信した。
bool ClientStateActive::OnRecvBuyItemRequest(MemoryStreamInterface *pStream)
{
	PacketBuyItemRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = GetParent()->BuyItem(Packet.ShopId, Packet.ItemId, Packet.Count);
	PacketBuyItemResult ResultPacket(Result);
	GetParent()->SendPacket(&ResultPacket);

	return true;
}

// アイテム売却要求を受信した。
bool ClientStateActive::OnRecvSellItemRequest(MemoryStreamInterface *pStream)
{
	PacketSellItemRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = GetParent()->SellItem(Packet.ShopId, Packet.ItemId, Packet.Count);
	PacketSellItemResult ResultPacket(Result);
	GetParent()->SendPacket(&ResultPacket);

	return true;
}

// ショップ終了を受信した。
bool ClientStateActive::OnRecvExitShop(MemoryStreamInterface *pStream)
{
	PacketExitShop Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	GetParent()->ExitShop();

	return true;
}

// メールリストリクエストを受信した。
bool ClientStateActive::OnRecvMailListRequest(MemoryStreamInterface *pStream)
{
	PacketMailListRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CachePacketMailListRequest RequestPacket(GetParent()->GetUuid(), GetParent()->GetCustomerId());
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);

	return true;
}

// キャッシュサーバからメールリストを受信した。
bool ClientStateActive::OnRecvCacheMailList(MemoryStreamInterface *pStream)
{
	CachePacketMailListResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	PacketMailList ListPacket;
	for (int i = 0; i < Packet.List.GetCurrentSize(); i++)
	{
		ListPacket.List.PushBack(Packet.List[i]);
	}

	GetParent()->SendPacket(&ListPacket);
	return true;
}

// メール開封を受信した。
bool ClientStateActive::OnRecvMailRead(MemoryStreamInterface *pStream)
{
	PacketMailRead Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CachePacketMailRead ReadPacket(GetParent()->GetUuid(), Packet.Id);
	CacheServerConnection::GetInstance()->SendPacket(&ReadPacket);

	return true;
}

// メール添付物受信リクエストを受信した。
bool ClientStateActive::OnRecvMailAttachmentRecvRequest(MemoryStreamInterface *pStream)
{
	PacketMailAttachmentRecvRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CachePacketMailAttachmentRecvRequest RequestPacket(GetParent()->GetUuid(), Packet.Id);
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);

	return true;
}

// キャッシュサーバからメール添付物受信結果を受信した。
bool ClientStateActive::OnRecvCacheMailAttachmentRecvResult(MemoryStreamInterface *pStream)
{
	CachePacketMailAttachmentRecvResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = PacketMailAttachmentRecvResult::Success;
	if (Packet.Result == CachePacketMailAttachmentRecvResult::Success)
	{
		// 成功.
		switch (Packet.Type)
		{
			case MailData::Item:

				// アイテム
				GetParent()->GetCharacter().lock()->AddItem(Packet.AttachmentId, Packet.Count);
				break;

			case MailData::Gold:

				// ゴールド
				GetParent()->GetCharacter().lock()->AddGold(Packet.Count);
				break;
		}
	}
	else
	{
		// エラー
		switch (Packet.Result)
		{
			case CachePacketMailAttachmentRecvResult::AlreadyRecv:

				Result = PacketMailAttachmentRecvResult::AlreadyRecv;
				break;

			default:

				Result = PacketMailAttachmentRecvResult::Error;
				break;
		}
	}

	PacketMailAttachmentRecvResult ResultPacket(Packet.MailId, Result);
	GetParent()->SendPacket(&ResultPacket);
	return true;
}
