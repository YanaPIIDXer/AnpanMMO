#include "stdafx.h"
#include "InstanceAreaTicket.h"
#include "Client.h"
#include "Packet/PacketInstanceAreaTicketPublish.h"

// コンストラクタ
InstanceAreaTicket::InstanceAreaTicket(u32 InUuid, u32 InAreaId)
	: Uuid(InUuid)
	, AreaId(InAreaId)
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
