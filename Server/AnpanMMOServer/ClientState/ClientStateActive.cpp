#include "stdafx.h"
#include  "ClientStateActive.h"

// �R���X�g���N�^
ClientStateActive::ClientStateActive(Client *pInParent)
	: ClientStateBase(pInParent)
{
}

// �J�n���̏���.
void ClientStateActive::BeginState()
{
}

// �p�P�b�g���.
void ClientStateActive::AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream)
{

}
