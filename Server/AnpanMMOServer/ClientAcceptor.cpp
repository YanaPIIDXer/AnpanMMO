#include "stdafx.h"
#include "ClientAcceptor.h"
#include "ClientManager.h"

// コンストラクタ
ClientAcceptor::ClientAcceptor(asio::io_service &InIOService, int Port)
	: IOService(InIOService)
	, Acceptor(InIOService, tcp::endpoint(tcp::v4(), Port))
	//, pSocket(NULL)
	, bWaitingAccept(false)
{
}

// 定期処理.
void ClientAcceptor::Poll()
{
	if (bWaitingAccept)
	{
		StartAccept();
	}
}

// Accept開始.
void ClientAcceptor::Start()
{
	bWaitingAccept = true;
}


// Accept開始.
void ClientAcceptor::StartAccept()
{
	pSocket = shared_ptr<tcp::socket>(new tcp::socket(IOService));
	Acceptor.async_accept(*pSocket.get(), bind(&ClientAcceptor::OnAccept, this, asio::placeholders::error));
	bWaitingAccept = false;
}

// Acceptした
void ClientAcceptor::OnAccept(const boost::system::error_code &ErrorCode)
{
	if (ErrorCode)
	{
		std::cout << "Accept Failed." << std::endl;
		return;
	}

	ClientManager::GetInstance().CreateClient(pSocket);

	bWaitingAccept = true;
}
