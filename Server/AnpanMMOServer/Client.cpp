#include "stdafx.h"
#include "Client.h"

// �R���X�g���N�^
Client::Client(const shared_ptr<tcp::socket> &pInSocket)
	: pSocket(pInSocket)
	, bIsConnected(true)
{
}
