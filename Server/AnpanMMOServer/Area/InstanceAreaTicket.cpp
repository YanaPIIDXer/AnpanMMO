#include "stdafx.h"
#include "InstanceAreaTicket.h"
#include "Client.h"

// �R���X�g���N�^
InstanceAreaTicket::InstanceAreaTicket()
{
}

// �N���C�A���g�ǉ�.
void InstanceAreaTicket::AddClient(ClientPtr pClient)
{
	ClientList[pClient.lock()->GetUuid()] = pClient;
}
