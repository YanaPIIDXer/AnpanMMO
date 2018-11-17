#include "stdafx.h"
#include "GameServerConnection.h"
#include "Config.h"

// コンストラクタ
GameServerConnection::GameServerConnection(asio::io_service &IOService, const shared_ptr<tcp::socket> &pInSocket)
	: TCPConnection(pInSocket)
	, Acceptor(IOService, tcp::endpoint(tcp::v4(), Config::CacheServerPort))
{
}
