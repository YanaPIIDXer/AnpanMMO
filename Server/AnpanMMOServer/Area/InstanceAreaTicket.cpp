#include "stdafx.h"
#include "InstanceAreaTicket.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "ClientState/ClientStateAreaChange.h"
#include "Packet/PacketInstanceAreaTicketPublish.h"
#include "Packet/PacketInstanceAreaTicketDiscard.h"
#include "Packet/PacketAreaMoveResponse.h"

// �R���X�g���N�^
InstanceAreaTicket::InstanceAreaTicket(u32 InUuid, u32 InAreaId, const Vector3D &InStartPosition)
	: Uuid(InUuid)
	, AreaId(InAreaId)
	, StartPosition(InStartPosition)
{
}

// �N���C�A���g�ǉ�.
void InstanceAreaTicket::AddClient(ClientPtr pClient)
{
	InstanceAreaTicketInfo Info;
	Info.pClient = pClient;
	Info.State = TicketStateWait;
	InfoList[pClient.lock()->GetUuid()] = Info;
}

// ��������M�����B
void InstanceAreaTicket::RecvProcess(u32 Uuid, ETicketState Process)
{
	InfoList[Uuid].State = Process;
}

// �������������Ă��邩�H
bool InstanceAreaTicket::IsReady() const
{
	for (InfoMap::const_iterator It = InfoList.begin(); It != InfoList.end(); ++It)
	{
		if (It->second.State != TicketStateEnter) { return false; }
	}

	return true;
}

// �j������Ă��邩�H
bool InstanceAreaTicket::IsDiscard() const
{
	for (InfoMap::const_iterator It = InfoList.begin(); It != InfoList.end(); ++It)
	{
		if (It->second.State != TicketStateDiscard) { return false; }
	}

	return true;
}

// �ҋ@�����H
bool InstanceAreaTicket::IsWaiting() const
{
	for (InfoMap::const_iterator It = InfoList.begin(); It != InfoList.end(); ++It)
	{
		if (It->second.State == TicketStateWait) { return true; }
	}

	return false;
}

// ���s�`�P�b�g���o���T���B
void InstanceAreaTicket::BroadcastPublishPacket()
{
	PacketInstanceAreaTicketPublish Packet(AreaId, Uuid);
	for (InfoMap::iterator It = InfoList.begin(); It != InfoList.end(); ++It)
	{
		It->second.pClient.lock()->SendPacket(&Packet);
	}
}

// �j���`�P�b�g���o���T���B
void InstanceAreaTicket::BroadcastDiscardPacket()
{
	PacketInstanceAreaTicketDiscard Packet;
	for (InfoMap::iterator It = InfoList.begin(); It != InfoList.end(); ++It)
	{
		It->second.pClient.lock()->SendPacket(&Packet);
	}
}

// �C���X�^���X�G���A�ɓ˂����ށB
void InstanceAreaTicket::EnterToInstanceArea(AreaPtr pArea)
{
	// �ʏ�̃}�b�v�ړ��t���[�Ɠ��l�ɏ������s���Ă����B
	PacketAreaMoveResponse Packet(PacketAreaMoveResponse::Success);
	for (InfoMap::iterator It = InfoList.begin(); It != InfoList.end(); ++It)
	{
		PlayerCharacterPtr pCharacter = It->second.pClient.lock()->GetCharacter();
		AreaPtr pArea = pCharacter.lock()->GetArea();
		pArea.lock()->RemovePlayerCharacter(pCharacter.lock()->GetUuid());

		It->second.pClient.lock()->SendPacket(&Packet);
		
		ClientStateAreaChange *pNewState = new ClientStateAreaChange(It->second.pClient.lock().get(), pArea.lock()->GetId(), StartPosition);
		It->second.pClient.lock()->ChangeState(pNewState);
	}
}

