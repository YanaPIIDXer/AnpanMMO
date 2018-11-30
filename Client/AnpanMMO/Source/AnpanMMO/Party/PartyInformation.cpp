// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PartyInformation.h"
#include "Active/ActiveGameMode.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "UI/SimpleDialog.h"
#include "Packet/PacketPartyCreateResult.h"
#include "Packet/PacketPartyDissolutionResult.h"
#include "Packet/PacketPartyJoin.h"
#include "Packet/PacketPartyJoinMember.h"
#include "Packet/PacketPartyDissolution.h"
#include "Packet/PacketPartyExit.h"

// �R���X�g���N�^
PartyInformation::PartyInformation()
	: PartyId(0)
	, bIsLeader(false)
	, pGameMode(nullptr)
{
}

// �쐬���ʂ���M�����B
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

	// �������g��o�^.
	AGameCharacter *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(pGameMode.Get(), 0));
	check(pCharacter != nullptr);

	PartyMemberData Data(pCharacter->GetUuid(), TCHAR_TO_UTF8(*pCharacter->GetName()));
	MemberList.Add(Data.Uuid, Data);

	bIsLeader = true;

	USimpleDialog::Show(pGameMode.Get(), "Party Create Success!!");
}

// ���U���ʂ���M�����B
void PartyInformation::OnRecvDissolutionResult(MemoryStreamInterface *pStream)
{
	PacketPartyDissolutionResult Packet;
	Packet.Serialize(pStream);

	if (Packet.Result == PacketPartyDissolutionResult::Error)
	{
		USimpleDialog::Show(pGameMode.Get(), "Dissolution Error...");
		return;
	}

	MemberList.Empty();
	PartyId = 0;
	USimpleDialog::Show(pGameMode.Get(), "Party Dissoluted,");
}

// �Q������M�����B
void PartyInformation::OnRecvJoin(MemoryStreamInterface *pStream)
{
	PacketPartyJoin Packet;
	Packet.Serialize(pStream);

	PartyId = Packet.Uuid;
	for (int i = 0; i < Packet.MemberList.GetCurrentSize(); i++)
	{
		MemberList.Add(Packet.MemberList[i].Uuid, Packet.MemberList[i]);
	}

	bIsLeader = false;
}

// �����o��������M�����B
void PartyInformation::OnRecvJoinMember(MemoryStreamInterface *pStream)
{
	PacketPartyJoinMember Packet;
	Packet.Serialize(pStream);

	MemberList.Add(Packet.MemberData.Uuid, Packet.MemberData);
}

// �����o���E����M�����B
void PartyInformation::OnRecvExitMember(MemoryStreamInterface *pStream)
{
	PacketPartyExit Packet;
	Packet.Serialize(pStream);

	if (!MemberList.Contains(Packet.Uuid)) { return; }
	MemberList.Remove(Packet.Uuid);
}

// ���U����M�����B
void PartyInformation::OnRecvDissolution(MemoryStreamInterface *pStream)
{
	PacketPartyDissolution Packet;
	Packet.Serialize(pStream);

	MemberList.Empty();
	PartyId = 0;
	USimpleDialog::Show(pGameMode.Get(), "Party Dissoluted,");
}
