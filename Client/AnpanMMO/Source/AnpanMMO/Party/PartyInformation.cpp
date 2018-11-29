// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PartyInformation.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketPartyCreateResult.h"

// �R���X�g���N�^
PartyInformation::PartyInformation()
	: PartyId(0)
	, pGameMode(nullptr)
{
}

// �쐬���ʂ���M�����B
void PartyInformation::OnRecvCreateResult(MemoryStreamInterface *pStream)
{
	PacketPartyCreateResult Packet;
	Packet.Serialize(pStream);
}
