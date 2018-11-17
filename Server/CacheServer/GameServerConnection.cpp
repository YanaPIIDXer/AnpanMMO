#include "stdafx.h"
#include "GameServerConnection.h"
#include "Config.h"

// コンストラクタ
GameServerConnection::GameServerConnection(asio::io_service &IOService, const shared_ptr<tcp::socket> &pInSocket)
	: TCPConnection(pInSocket)
	, Acceptor(IOService, tcp::endpoint(tcp::v4(), Config::CacheServerPort))
{
	Acceptor.async_accept(*pInSocket.get(), bind(&GameServerConnection::OnAccept, this, asio::placeholders::error));
}


// Acceptした。
void GameServerConnection::OnAccept(const system::error_code &ErrorCode)
{
	if (ErrorCode)
	{
		std::cout << ErrorCode.message() << std::endl;
		return;
	}
	bIsConnected = true;
}
