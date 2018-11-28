#include "stdafx.h"
#include "GameServerConnection.h"

// エントリポイント
int main()
{
	asio::io_service IOService;

	tcp::socket *pSock = new tcp::socket(IOService);
	shared_ptr<tcp::socket> pSocket = shared_ptr<tcp::socket>(pSock);
	GameServerConnection GameServerConn(IOService, pSocket);

	IOService.run();
	return 0;
}
