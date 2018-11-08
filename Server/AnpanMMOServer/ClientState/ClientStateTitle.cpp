#include "stdafx.h"
#include "ClientStateTitle.h"
#include "Client.h"
#include "DBConnection.h"
#include "ClientStateActive.h"
#include "ClientManager.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInRequest.h"
#include "Packet/PacketLogInResult.h"

// コンストラクタ
ClientStateTitle::ClientStateTitle(Client *pInParent)
	: ClientStateBase(pInParent)
{
	AddPacketFunction(LogInRequest, boost::bind(&ClientStateTitle::OnRecvLogInRequest, this, _2));
}


// ログインリクエストを受信した。
void ClientStateTitle::OnRecvLogInRequest(MemoryStreamInterface *pStream)
{
	PacketLogInRequest Packet;
	Packet.Serialize(pStream);

	int Id = 0;
	PacketLogInResult::ResultCode ResultCode = PacketLogInResult::Success;
	char *pUserCode = const_cast<char *>(Packet.UserCode.c_str());
	if (!DBConnection::GetInstance().LoadUserData(pUserCode, Id))
	{
		ResultCode = PacketLogInResult::Error;
	}
	Client *pClient = GetParent();
	PacketLogInResult ResultPacket(ResultCode, pClient->GetUuid());
	pClient->SendPacket(&ResultPacket);

	if (ResultCode != PacketLogInResult::Success) { return; }

	pClient->SetCustomerId(Id);

	ClientStateActive *pNextState = new ClientStateActive(pClient);
	pClient->ChangeState(pNextState);
}
