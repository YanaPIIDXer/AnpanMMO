#include "stdafx.h"	
#include "ClientAcceptor.h"
#include "ClientManager.h"

// エントリポイント
int main()
{
	asio::io_service IOService;

	ClientAcceptor Acceptor(IOService, Config::Port);
	asio::basic_repeating_timer<posix_time::ptime> AcceptorTimer(IOService);
	AcceptorTimer.start(posix_time::millisec(30),
		bind(&ClientAcceptor::Poll, &Acceptor));

	Acceptor.Start();

	asio::basic_repeating_timer<posix_time::ptime> ClientManagerTimer(IOService);
	ClientManagerTimer.start(posix_time::millisec(30),
		bind(&ClientManager::Poll, &ClientManager::GetInstance()));

	IOService.run();
	return 0;
}
