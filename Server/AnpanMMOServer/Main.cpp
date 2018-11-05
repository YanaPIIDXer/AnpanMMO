#include "stdafx.h"	
#include "ClientAcceptor.h"
#include "ClientManager.h"
#include "DBConnection.h"
#include "World.h"

// エントリポイント
int main()
{
	if (DBConnection::GetInstance().Open())
	{
		std::cout << "DB Open Success!!" << std::endl;
	}
	else
	{
		std::cout << "DB Open Failed..." << std::endl;
		return 1;
	}
	
	asio::io_service IOService;

	ClientAcceptor Acceptor(IOService, Config::Port);
	asio::basic_repeating_timer<posix_time::ptime> AcceptorTimer(IOService);
	AcceptorTimer.start(posix_time::millisec(30),
		bind(&ClientAcceptor::Poll, &Acceptor));

	Acceptor.Start();

	asio::basic_repeating_timer<posix_time::ptime> ClientManagerTimer(IOService);
	ClientManagerTimer.start(posix_time::millisec(30),
		bind(&ClientManager::Poll, &ClientManager::GetInstance()));

	asio::basic_repeating_timer<posix_time::ptime> WorldTimer(IOService);
	WorldTimer.start(posix_time::millisec(30),
		bind(&World::Poll, &World::GetInstance()));

	World::GetInstance().Initialize();

	asio::basic_repeating_timer<posix_time::ptime> AnpanSpawnTimer(IOService);
	AnpanSpawnTimer.start(posix_time::millisec(5000),
		bind(&World::SpawnAnpan, &World::GetInstance()));

	IOService.run();
	return 0;
}
