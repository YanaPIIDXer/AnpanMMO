#include "stdafx.h"
#include "ClientAcceptor.h"

// コンストラクタ
ClientAcceptor::ClientAcceptor(asio::io_service &InIOService, int Port)
	: IOService(InIOService)
	, Acceptor(InIOService, tcp::endpoint(tcp::v4(), Port))
{
}

// 定期処理.
void ClientAcceptor::Poll()
{

}
