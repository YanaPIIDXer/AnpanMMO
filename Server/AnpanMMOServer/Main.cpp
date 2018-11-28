#include "stdafx.h"	
#include "ClientAcceptor.h"
#include "ClientManager.h"
#include "TickManager.h" 
#include "Master/MasterData.h"
#include "Area/AreaManager.h"
#include "CacheServer/CacheServerConnection.h"

// エントリポイント
int main()
{
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

	tcp::socket *pSock = new tcp::socket(IOService);
	shared_ptr<tcp::socket> pSocket = shared_ptr<tcp::socket>(pSock);
	CacheServerConnection CacheServerConn(pSocket);
	if (!CacheServerConn.Connect())
	{
		return 1;
	}
	
	ClientAcceptor Acceptor(IOService, Config::Port);
	asio::basic_repeating_timer<posix_time::ptime> AcceptorTimer(IOService);
	AcceptorTimer.start(posix_time::millisec(30),
		bind(&ClientAcceptor::Poll, &Acceptor));

	Acceptor.Start();

	asio::basic_repeating_timer<posix_time::ptime> ClientManagerTimer(IOService);
	ClientManagerTimer.start(posix_time::millisec(30),
		bind(&ClientManager::Poll, &ClientManager::GetInstance()));

	AreaManager::GetInstance().Initialize();

	asio::basic_repeating_timer<posix_time::ptime> TickTimer(IOService);
	TickTimer.start(posix_time::millisec(30),
		bind(&TickManager::Poll, &TickManager::GetInstance()));

	IOService.run();
	return 0;
}
