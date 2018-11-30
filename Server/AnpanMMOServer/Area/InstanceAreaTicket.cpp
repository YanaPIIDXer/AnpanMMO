#include "stdafx.h"
#include "InstanceAreaTicket.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "ClientState/ClientStateAreaChange.h"
#include "Packet/PacketInstanceAreaTicketPublish.h"
#include "Packet/PacketInstanceAreaTicketDiscard.h"
#include "Packet/PacketAreaMoveResponse.h"

// コンストラクタ
InstanceAreaTicket::InstanceAreaTicket(u32 InUuid, u32 InAreaId, const Vector3D &InStartPosition)
	: Uuid(InUuid)
	, AreaId(InAreaId)
	, StartPosition(InStartPosition)
{
}

// クライアント追加.
void InstanceAreaTicket::AddClient(ClientPtr pClient)
{
	InstanceAreaTicketInfo Info;
	Info.pClient = pClient;
	Info.State = TicketStateWait;
	InfoList[pClient.lock()->GetUuid()] = Info;
}

// 処理を受信した。
void InstanceAreaTicket::RecvProcess(u32 Uuid, ETicketState Process)
{
	InfoList[Uuid].State = Process;
}

// 準備が完了しているか？
bool InstanceAreaTicket::IsReady() const
{
	for (InfoMap::const_iterator It = InfoList.begin(); It != InfoList.end(); ++It)
	{
		if (It->second.State != TicketStateEnter) { return false; }
	}

	return true;
}

// 破棄されているか？
bool InstanceAreaTicket::IsDiscard() const
{
	for (InfoMap::const_iterator It = InfoList.begin(); It != InfoList.end(); ++It)
	{
		if (It->second.State != TicketStateDiscard) { return false; }
	}

	return true;
}

// 待機中か？
bool InstanceAreaTicket::IsWaiting() const
{
	for (InfoMap::const_iterator It = InfoList.begin(); It != InfoList.end(); ++It)
	{
		if (It->second.State == TicketStateWait) { return true; }
	}

	return false;
}

// 発行チケットをバラ撒く。
void InstanceAreaTicket::BroadcastPublishPacket()
{
	PacketInstanceAreaTicketPublish Packet(AreaId, Uuid);
	for (InfoMap::iterator It = InfoList.begin(); It != InfoList.end(); ++It)
	{
		It->second.pClient.lock()->SendPacket(&Packet);
	}
}

// 破棄チケットをバラ撒く。
void InstanceAreaTicket::BroadcastDiscardPacket()
{
	PacketInstanceAreaTicketDiscard Packet;
	for (InfoMap::iterator It = InfoList.begin(); It != InfoList.end(); ++It)
	{
		It->second.pClient.lock()->SendPacket(&Packet);
	}
}

// インスタンスエリアに突っ込む。
void InstanceAreaTicket::EnterToInstanceArea(AreaPtr pArea)
{
	// 通常のマップ移動フローと同様に処理を行っていく。
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

