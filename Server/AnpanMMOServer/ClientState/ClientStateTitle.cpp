#include "stdafx.h"
#include "ClientStateTitle.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInRequest.h"
#include "Packet/PacketLogInResult.h"
#include "Client.h"

// �R���X�g���N�^
ClientStateTitle::ClientStateTitle(Client *pInParent)
	: ClientStateBase(pInParent)
{
}

// �p�P�b�g���.
void ClientStateTitle::AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream)
{
	switch (ID)
	{
		case LogInRequest:

			OnRecvLogInRequest(pStream);
			break;

	}
}


// ���O�C�����N�G�X�g����M�����B
void ClientStateTitle::OnRecvLogInRequest(MemoryStreamInterface *pStream)
{
	PacketLogInRequest Packet;
	Packet.Serialize(pStream);

	// �Ƃ肠�����_�~�[�f�[�^��Ԃ��B
	PacketLogInResult ResultPacket(PacketLogInResult::Success, 1);
	GetParent()->SendPacket(&ResultPacket);
}
