// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PartyInformation.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketPartyCreateResult.h"

// コンストラクタ
PartyInformation::PartyInformation()
	: PartyId(0)
	, pGameMode(nullptr)
{
}

// 作成結果を受信した。
void PartyInformation::OnRecvCreateResult(MemoryStreamInterface *pStream)
{
	PacketPartyCreateResult Packet;
	Packet.Serialize(pStream);
}
