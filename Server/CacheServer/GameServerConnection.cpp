#include "stdafx.h"
#include "GameServerConnection.h"

// �R���X�g���N�^
GameServerConnection::GameServerConnection(const shared_ptr<tcp::socket> &pInSocket)
	: TCPConnection(pInSocket)
{
}
