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

// �R���X�g���N�^
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


// �ړ�����M�����B
void ClientStateActive::OnRecvMove(MemoryStreamInterface *pStream)
{
	PacketMovePlayer Packet;
	Packet.Serialize(pStream);

	AreaPtr pArea = GetParent()->GetCharacter().lock()->GetArea();
	pArea.lock()->OnRecvMove(GetParent()->GetUuid(), Packet.X, Packet.Y, Packet.Z, Packet.Rotation);
}

// �U������M�����B
void ClientStateActive::OnRecvAttack(MemoryStreamInterface *pStream)
{
	PacketAttack Packet;
	Packet.Serialize(pStream);

	AreaPtr pArea = GetParent()->GetCharacter().lock()->GetArea();
	pArea.lock()->OnRecvAttack(GetParent()->GetUuid(), Packet.TargetUuid);
}

// �`���b�g����M�����B
void ClientStateActive::OnRecvChat(MemoryStreamInterface *pStream)
{
	PacketSendChat Packet;
	Packet.Serialize(pStream);

	WordCheckPacketChatRequest WordCheckPacket(GetParent()->GetUuid(), Packet.Type, Packet.Message);
	WordCheckServerConnection::GetInstance()->SendPacket(&WordCheckPacket);
}

// �`���b�g�̃��[�h�`�F�b�N���ʂ���M�����B
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

// �G���A�ړ��v������M�����B
void ClientStateActive::OnRecvAreaMoveRequest(MemoryStreamInterface *pStream)
{
	PacketAreaMoveRequest Packet;
	Packet.Serialize(pStream);

	const WarpDataItem *pItem = MasterData::GetInstance().GetWarpDataMaster().GetItem(Packet.AreaMoveId);
	const AreaItem *pAreaItem = MasterData::GetInstance().GetAreaMaster().GetItem(pItem->AreaId);
	if (pAreaItem->Type != AreaItem::INSTANCE_AREA)
	{
		// �ʏ�}�b�v�ւ̈ړ��B
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
		// �C���X�^���X�}�b�v�ւ̈ړ������݂��B
		InstanceAreaTicket *pTicket = InstanceAreaTicketManager::GetInstance().Publish(pItem->AreaId);
		
		PartyPtr pParty = GetParent()->GetCharacter().lock()->GetParty();
		if (pParty.expired())
		{
			// �\��
			ClientPtr pSelf = ClientManager::GetInstance().Get(GetParent()->GetUuid());
			pTicket->AddClient(pSelf);
		}
		else
		{
			// �p�[�e�B�ɓ����Ă����ꍇ�̓����o�S�������ҁB
			std::vector<PlayerCharacterPtr> Players = pParty.lock()->GetMemberList();
			for (u32 i = 0; i < Players.size(); i++)
			{
				ClientPtr pClient = ClientManager::GetInstance().Get(Players[i].lock()->GetClient()->GetUuid());
				pTicket->AddClient(pClient);
			}
		}
		
		// ���s�`�P�b�g���o���T���B
		pTicket->BroadcastPublishPacket();
	}
}

// ���X�|���v������M�����B
void ClientStateActive::OnRecvRespawnRequest(MemoryStreamInterface *pStream)
{
	PacketRespawnRequest Packet;
	Packet.Serialize(pStream);

	PlayerCharacterPtr pChara = GetParent()->GetCharacter();
	pChara.lock()->Respawn();

	PacketPlayerRespawn RespawnPacket(pChara.lock()->GetUuid(), 0.0f, 0.0f, 0.0f);
	GetParent()->SendPacket(&RespawnPacket);

	// ���r�[�Ƀ��X�|������B
	PacketAreaMoveResponse AreaMovePacket(PacketAreaMoveResponse::Success);
	GetParent()->SendPacket(&AreaMovePacket);

	AreaPtr pArea = pChara.lock()->GetArea();
	pArea.lock()->RemovePlayerCharacter(pChara.lock()->GetUuid());

	ClientStateAreaChange *pNewState = new ClientStateAreaChange(GetParent(), 1, Vector3D(-1000.0f, 0.0f, 0.0f));
	GetParent()->ChangeState(pNewState);
}

// �p�[�e�B�쐬�v������M�����B
void ClientStateActive::OnRecvPartyCraeteRequest(MemoryStreamInterface *pStream)
{
	PacketPartyCreateRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = PacketPartyCreateResult::Success;
	if (PartyManager::GetInstance().IsAlreadyJoined(GetParent()->GetUuid()))
	{
		// ���ɂǂ����̃p�[�e�B�ɎQ���ς݁B
		Result = PacketPartyCreateResult::AlreadyJoin;
	}

	u32 PartyId = 0;
	if (Result == PacketPartyCreateResult::Success)
	{
		// �p�[�e�B�쐬.
		PartyManager::GetInstance().Create(GetParent()->GetCharacter());
		PartyId = GetParent()->GetCharacter().lock()->GetParty().lock()->GetUuid();
	}
	PacketPartyCreateResult ResultPacket(Result, PartyId);
	GetParent()->SendPacket(&ResultPacket);
}

// �p�[�e�B���E�v������M�����B
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

// �p�[�e�B���E�v������M�����B
void ClientStateActive::OnRecvPartyExitRequest(MemoryStreamInterface *pStream)
{
	PacketPartyExitRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = PacketPartyExitResult::Success;
	PartyPtr pParty = GetParent()->GetCharacter().lock()->GetParty();
	if (!pParty.expired())
	{
		pParty.lock()->Exit(GetParent()->GetUuid());

		// ���E�p�P�b�g���o���T���B
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

// �p�[�e�B�L�b�N�v������M�����B
void ClientStateActive::OnRecvPartyKickRequest(MemoryStreamInterface *pStream)
{
	PacketPartyKickRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = PacketPartyKickResult::Success;
	PartyPtr pParty = GetParent()->GetCharacter().lock()->GetParty();
	if (!pParty.expired())
	{
		// ���ۂɗ��E������O�ɃL�b�N�p�P�b�g���o���T��.
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

// �p�[�e�B���U�v������M�����B
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

// �p�[�e�B���U���X�|���X���󂯂��B
void ClientStateActive::OnRecvPartyInviteResponse(MemoryStreamInterface *pStream)
{
	PacketPartyInviteResponse Packet;
	Packet.Serialize(pStream);

	ClientPtr pTargetClient = ClientManager::GetInstance().GetFromCustomerId(Packet.CustomerId);

	// ���X�|���X�҂��̊Ԃɗ��������̃P�[�X
	// @TODO:���X�|���X�������N���C�A���g�ɂ͉����ʒm���Ȃ��Ă����́H
	if (pTargetClient.expired()) { return; }

	if (Packet.Response == PacketPartyInviteResponse::Refuse)
	{
		// @TODO:pTargetClient�ɑ΂��Ēʒm�𓊂���B
		return;
	}

	PartyPtr pParty = pTargetClient.lock()->GetCharacter().lock()->GetParty();

	// ���X�|���X�҂��̊ԂɃp�[�e�B�����U�������̃P�[�X
	// @TODO:���X�|���X�������N���C�A���g�ɂ͉����ʒm���Ȃ��Ă����́H
	if (pParty.expired()) { return; }

	// ���X�|���X�҂��̊ԂɃ����o�[���ő�ɂȂ����ꍇ�B
	// @TODO:���X�|���X�������N���C�A���g�ɂ͉����ʒm���Ȃ��Ă����́H
	if (pParty.lock()->IsMaximumMember()) { return; }

	pParty.lock()->Join(GetParent()->GetCharacter());
}

// �C���X�^���X�}�b�v�`�P�b�g�̏�������M�����B
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
		// ���������������̂ŃC���X�^���X�}�b�v�𐶐����ă����o�S�����΂��B


		// �`�P�b�g�͔j���B
		InstanceAreaTicketManager::GetInstance().Remove(Packet.TicketId);
	}
	else if (!pTicket->IsWaiting() && pTicket->IsDiscard())
	{
		// ��l�ł��`�P�b�g��j�������N���C�A���g������Δj���B
		InstanceAreaTicketManager::GetInstance().Remove(Packet.TicketId);
		// @TODO:�ʒm.
	}
}
