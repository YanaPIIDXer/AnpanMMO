#include "stdafx.h"
#include "ClientStateTitle.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInRequest.h"

// �R���X�g���N�^
ClientStateTitle::ClientStateTitle(Client *pInParent)
	: ClientStateBase(pInParent)
{
}

// �p�P�b�g���.
void ClientStateTitle::AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream)
{

}
