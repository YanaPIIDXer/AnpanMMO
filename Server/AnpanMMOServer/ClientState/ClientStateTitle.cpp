#include "stdafx.h"
#include "ClientStateTitle.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInRequest.h"
#include "Packet/PacketLogInResult.h"
#include "Client.h"
#include "DBConnection.h"

// コンストラクタ
ClientStateTitle::ClientStateTitle(Client *pInParent)
	: ClientStateBase(pInParent)
{
}

// パケット解析.
void ClientStateTitle::AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream)
{
	switch (ID)
	{
		case LogInRequest:

			OnRecvLogInRequest(pStream);
			break;

	}
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

	GetParent()->SetUuid(Id);

	PacketLogInResult ResultPacket(ResultCode, Id);
	GetParent()->SendPacket(&ResultPacket);
}
