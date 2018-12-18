#include "stdafx.h"	
#include "ClientAcceptor.h"
#include "ClientManager.h"
#include "TickManager.h" 
#include "Master/MasterData.h"
#include "Area/AreaManager.h"
#include "Party/PartyManager.h"
#include "Time/TimeManager.h"
#include "ServerHost.h"
#include "CacheServer/CacheServerConnection.h"
#include "WordCheckServer/WordCheckServerConnection.h"

// エントリポイント
int main()
{
	if (MasterData::GetInstance().Read())
	{
		std::cout << "Master Read Success!!" << std::endl;
	}
	else
	{
		std::cout << "Master Read Failed..." << std::endl;
		return 1;
	}

	asio::io_service IOService;

	tcp::socket *pCacheServerSock = new tcp::socket(IOService);
	shared_ptr<tcp::socket> pCacheServerSocket = shared_ptr<tcp::socket>(pCacheServerSock);
	CacheServerConnection CacheServerConn(pCacheServerSocket);
	if (!CacheServerConn.Connect())
	{
		std::cout << "CacheServer Connect Failed..." << std::endl;
		return 1;
	}

	tcp::socket *pWordCheckServerSock = new tcp::socket(IOService);
	shared_ptr<tcp::socket> pWordCheckServerSocket = shared_ptr<tcp::socket>(pWordCheckServerSock);
	WordCheckServerConnection WordCheckServerConn(pWordCheckServerSocket);
	if (!WordCheckServerConn.Connect())
	{
		std::cout << "WordCheckServer Connect Failed..." << std::endl;
		return 1;
	}
	
	ClientAcceptor Acceptor(IOService, ServerHost::GameServerPort);
	asio::basic_repeating_timer<posix_time::ptime> AcceptorTimer(IOService);
	AcceptorTimer.start(posix_time::millisec(30),
		bind(&ClientAcceptor::Poll, &Acceptor));

	Acceptor.Start();

	asio::basic_repeating_timer<posix_time::ptime> ClientManagerTimer(IOService);
	ClientManagerTimer.start(posix_time::millisec(30),
		bind(&ClientManager::Poll, &ClientManager::GetInstance()));

	AreaManager::GetInstance().Initialize();

	asio::basic_repeating_timer<posix_time::ptime> PartyManagerTimer(IOService);
	PartyManagerTimer.start(posix_time::millisec(30),
		bind(&PartyManager::Poll, &PartyManager::GetInstance()));

	TickManager::GetInstance().Add(bind(&TimeManager::Poll, &TimeManager::GetInstance(), _1));
	TimeManager::GetInstance().Initialize();
	
	asio::basic_repeating_timer<posix_time::ptime> TickTimer(IOService);
	TickTimer.start(posix_time::millisec(30),
		bind(&TickManager::Poll, &TickManager::GetInstance()));

	IOService.run();
	return 0;
}
