#include "stdafx.h"
#include "ClientStateTitle.h"
#include "Client.h"
#include "DBConnection.h"
#include "ClientStateAreaChange.h"
#include "ClientManager.h"
#include "CacheServerConnection.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInRequest.h"
#include "Packet/PacketLogInResult.h"
#include "Packet/PacketCharacterStatus.h"
#include "Packet/CachePacketLogInRequest.h"
#include "Packet/CachePacketLogInResult.h"

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

	CachePacketLogInRequest CachePacket(GetParent()->GetUuid(), Packet.UserCode);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);

	/*
	int Id = 0;
	PacketLogInResult::ResultCode ResultCode = PacketLogInResult::Success;
	char *pUserCode = const_cast<char *>(Packet.UserCode.c_str());
	if (!DBConnection::GetInstance().LoadUserData(pUserCode, Id))
	{
		ResultCode = PacketLogInResult::Error;
	}
	if (!ClientManager::GetInstance().GetFromCustomerId(Id).expired())
	{
		ResultCode = PacketLogInResult::DoubleLogIn;
	}
	Client *pClient = GetParent();
	PacketLogInResult ResultPacket(ResultCode, pClient->GetUuid());
	pClient->SendPacket(&ResultPacket);

	if (ResultCode != PacketLogInResult::Success) { return; }

	pClient->SetCustomerId(Id);

	LoadCharacter();

	u32 AreaId = 1;
	float X = 0.0f;
	float Y = 0.0f;
	if (!DBConnection::GetInstance().ReadLastLogoutPosition(Id, AreaId, X, Y))
	{
		std::cout << "Read Last Logout Position Failed..." << std::endl;
	}

	ClientStateAreaChange *pNextState = new ClientStateAreaChange(pClient, AreaId, Vector2D(X, Y));
	pClient->ChangeState(pNextState);
	*/
}

// キャッシュサーバからログイン結果を受信した。
void ClientStateTitle::OnRecvCacheLogInResult(MemoryStreamInterface *pStream)
{
	CachePacketLogInResult Packet;
	Packet.Serialize(pStream);

	PacketLogInResult::ResultCode ResultCode = PacketLogInResult::Success;
	if (Packet.Result != CachePacketLogInResult::Success)
	{
		ResultCode = PacketLogInResult::Error;
	}
	if (!ClientManager::GetInstance().GetFromCustomerId(Packet.Uuid).expired())
	{
		ResultCode = PacketLogInResult::DoubleLogIn;
	}

	PacketLogInResult ResultPacket(ResultCode, GetParent()->GetUuid());
	GetParent()->SendPacket(&ResultPacket);

	if (ResultCode != PacketLogInResult::Success) { return; }

}

// キャラクタロード
void ClientStateTitle::LoadCharacter()
{
	Client *pClient = GetParent();

	int MaxHp = 0;
	int Atk = 0;
	int Def = 0;
	int Exp = 0;
	if (!DBConnection::GetInstance().LoadCharacterParameter(pClient->GetCustomerId(), MaxHp, Atk, Def, Exp))
	{
		std::cout << "Character Status Load Failed..." << std::endl;
		return;
	}
	pClient->CreateCharacter(MaxHp, Atk, Def, Exp);

	PacketCharacterStatus Packet(pClient->GetUuid(), MaxHp, MaxHp, Atk, Def, Exp);
	pClient->SendPacket(&Packet);
}
