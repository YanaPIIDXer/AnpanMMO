// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PartyInformation.h"
#include "Active/ActiveGameMode.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "UI/SimpleDialog.h"
#include "Packet/PacketPartyCreateResult.h"
#include "Packet/PacketPartyDissolutionResult.h"

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

	switch (Packet.Result)
	{
		case PacketPartyCreateResult::AlreadyJoin:

			USimpleDialog::Show(pGameMode.Get(), "Already Joined...");
			break;

		case PacketPartyCreateResult::Error:

			USimpleDialog::Show(pGameMode.Get(), "Fatal Error...");
			break;
	}

	if (Packet.Result != PacketPartyCreateResult::Success) { return; }
	PartyId = Packet.PartyId;
}

// 離脱結果を受信した。
void PartyInformation::OnRecvDissolutionResult(MemoryStreamInterface *pStream)
{
	PacketPartyDissolutionResult Packet;
	Packet.Serialize(pStream);

	if (Packet.Result == PacketPartyDissolutionResult::Error)
	{
		USimpleDialog::Show(pGameMode.Get(), "Dissolution Error...");
		return;
	}

	PartyId = 0;
}
