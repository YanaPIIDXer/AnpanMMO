#include "stdafx.h"
#include  "ClientStateActive.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "DBConnection.h"
#include "Client.h"
#include "Packet/PacketCharacterStatus.h"

// コンストラクタ
ClientStateActive::ClientStateActive(Client *pInParent)
	: ClientStateBase(pInParent)
{
}

// 開始時の処理.
void ClientStateActive::BeginState()
{
	LoadCharacter();
}


// キャラクタロード
void ClientStateActive::LoadCharacter()
{
	Client *pClient = GetParent();

	int MaxHp = 0;
	int Atk = 0;
	int Def = 0;
	int Exp = 0;
	if (!DBConnection::GetInstance().LoadCharacterParameter(pClient->GetUuid(), MaxHp, Atk, Def, Exp))
	{
		std::cout << "Character Status Load Failed..." << std::endl;
		return;
	}
	pClient->CreateCharacter(MaxHp, Atk, Def);

	PacketCharacterStatus Packet(MaxHp, MaxHp, Atk, Def, Exp);
	pClient->SendPacket(&Packet);
}
