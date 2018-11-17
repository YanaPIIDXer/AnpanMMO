#include "stdafx.h"
#include "GameServerConnection.h"

// コンストラクタ
GameServerConnection::GameServerConnection(const shared_ptr<tcp::socket> &pInSocket)
	: TCPConnection(pInSocket)
{
}
