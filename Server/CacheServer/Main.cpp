#include "stdafx.h"
#include "GameServerConnection.h"
#include "DBConnection.h"

// エントリポイント
int main()
{
	if (!DBConnection::GetInstance().Open())
	{
		std::cout << "DBConnection Open Failed..." << std::endl;
		return 1;
	}
	else
	{
		std::cout << "DBConnection Open Success!!" << std::endl;
	}

	asio::io_service IOService;

	tcp::socket *pSock = new tcp::socket(IOService);
	shared_ptr<tcp::socket> pSocket = shared_ptr<tcp::socket>(pSock);
	GameServerConnection GameServerConn(IOService, pSocket);

	IOService.run();
	return 0;
}
