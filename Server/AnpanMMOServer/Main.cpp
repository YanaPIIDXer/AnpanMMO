#include "stdafx.h"	
#include "ClientAcceptor.h"
#include "ClientManager.h"
#include "DBConnection.h"
#include "World.h"
#include "TickManager.h" 
#include "Master/MasterData.h"

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

	if (MasterData::GetInstance().Read())
	{
		std::cout << "Master Read Success!!" << std::endl;
	}
	else
	{
		std::cout << "Master Read Faled..." << std::endl;
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

	World::GetInstance().Initialize();

	asio::basic_repeating_timer<posix_time::ptime> TickTimer(IOService);
	TickTimer.start(posix_time::millisec(30),
		bind(&TickManager::Poll, &TickManager::GetInstance()));

	IOService.run();
	return 0;
}
