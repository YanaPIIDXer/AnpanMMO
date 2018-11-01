#include "stdafx.h"
#include "ClientStateTitle.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInRequest.h"

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

}
