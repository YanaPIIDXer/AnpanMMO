#include "stdafx.h"	
#include "ClientAcceptor.h"

// エントリポイント
int main()
{
	asio::io_service IOService;

	ClientAcceptor Acceptor(IOService, Config::Port);
	asio::basic_repeating_timer<posix_time::ptime> AcceptorTimer(IOService);
	AcceptorTimer.start(posix_time::millisec(30),
		bind(&ClientAcceptor::Poll, &Acceptor));

	Acceptor.Start();

	IOService.run();
	return 0;
}
