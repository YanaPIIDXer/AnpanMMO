// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "PartyInformation.h"
#include "Active/ActiveGameMode.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "UI/SimpleDialog.h"
#include "Packet/PacketPartyCreateResult.h"
#include "Packet/PacketPartyDissolutionResult.h"
#include "Packet/PacketPartyExitResult.h"
#include "Packet/PacketPartyJoin.h"
#include "Packet/PacketPartyJoinMember.h"
#include "Packet/PacketPartyDissolution.h"
#include "Packet/PacketPartyExit.h"
#include "Packet/PacketPartyKick.h"

// コンストラクタ
PartyInformation::PartyInformation()
	: PartyId(0)
	, bIsLeader(false)
	, pGameMode(nullptr)
{
}

// メンバリストを取得.
TArray<PartyMemberData> PartyInformation::GetMemberList() const
{
	TArray<PartyMemberData> List;

	for (const auto KeyValue : MemberList)
	{
		if (KeyValue.Value.Uuid == PartyId)
		{
			// リーダーは先頭に。
			List.Insert(KeyValue.Value, 0);
		}
		else
		{
			List.Add(KeyValue.Value);
		}
	}

	return List;
}

// 作成結果を受信した。
bool PartyInformation::OnRecvCreateResult(MemoryStreamInterface *pStream)
{
	PacketPartyCreateResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	switch (Packet.Result)
	{
		case PacketPartyCreateResult::AlreadyJoin:

			USimpleDialog::Show(pGameMode.Get(), "Already Joined...");
			break;

		case PacketPartyCreateResult::Error:

			USimpleDialog::Show(pGameMode.Get(), "Fatal Error...");
			break;
	}

	if (Packet.Result != PacketPartyCreateResult::Success) { return true; }
	PartyId = Packet.PartyId;

	// 自分自身を登録.
	AGameCharacter *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(pGameMode.Get(), 0));
	check(pCharacter != nullptr);

	PartyMemberData Data(pCharacter->GetUuid(), TCHAR_TO_UTF8(*pCharacter->GetCharacterName()));
	MemberList.Add(Data.Uuid, Data);

	bIsLeader = true;

	USimpleDialog::Show(pGameMode.Get(), "Party Create Success!!");

	return true;
}

// 解散結果を受信した。
bool PartyInformation::OnRecvDissolutionResult(MemoryStreamInterface *pStream)
{
	PacketPartyDissolutionResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result == PacketPartyDissolutionResult::Error)
	{
		USimpleDialog::Show(pGameMode.Get(), "Dissolution Error...");
		return true;
	}

	MemberList.Empty();
	PartyId = 0;
	USimpleDialog::Show(pGameMode.Get(), "Party Dissoluted,");

	return true;
}

// 離脱結果を受信した。
bool PartyInformation::OnRecvExitResult(MemoryStreamInterface *pStream)
{
	PacketPartyExitResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result == PacketPartyExitResult::Error)
	{
		USimpleDialog::Show(pGameMode.Get(), "Exit Error...");
		return true;
	}

	MemberList.Empty();
	PartyId = 0;
	USimpleDialog::Show(pGameMode.Get(), "Party Exit.");

	return true;
}

// 参加を受信した。
bool PartyInformation::OnRecvJoin(MemoryStreamInterface *pStream)
{
	PacketPartyJoin Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	PartyId = Packet.Uuid;
	for (int i = 0; i < Packet.MemberList.GetCurrentSize(); i++)
	{
		MemberList.Add(Packet.MemberList[i].Uuid, Packet.MemberList[i]);
	}

	bIsLeader = false;

	return true;
}

// メンバ加入を受信した。
bool PartyInformation::OnRecvJoinMember(MemoryStreamInterface *pStream)
{
	PacketPartyJoinMember Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	MemberList.Add(Packet.MemberData.Uuid, Packet.MemberData);
	
	return true;
}

// メンバ離脱を受信した。
bool PartyInformation::OnRecvExitMember(MemoryStreamInterface *pStream)
{
	PacketPartyExit Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!MemberList.Contains(Packet.Uuid)) { return true; }
	MemberList.Remove(Packet.Uuid);

	return true;
}

// メンバキックを受信した。
bool PartyInformation::OnRecvKickMember(MemoryStreamInterface *pStream)
{
	PacketPartyKick Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!MemberList.Contains(Packet.Uuid)) { return true; }
	MemberList.Remove(Packet.Uuid);

	AGameCharacter *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(pGameMode.Get(), 0));
	check(pCharacter != nullptr);

	if (pCharacter->GetUuid() == Packet.Uuid)
	{
		USimpleDialog::Show(pGameMode.Get(), "Party Kicked...");
	}

	return true;
}

// 解散を受信した。
bool PartyInformation::OnRecvDissolution(MemoryStreamInterface *pStream)
{
	PacketPartyDissolution Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	MemberList.Empty();
	PartyId = 0;
	USimpleDialog::Show(pGameMode.Get(), "Party Dissoluted,");

	return true;
}
