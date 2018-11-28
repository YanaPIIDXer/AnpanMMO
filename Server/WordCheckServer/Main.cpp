#include "stdafx.h"
#include "GameServerConnection.h"
#include "WordChecker.h"

// エントリポイント
int main()
{
	if (!WordChecker::GetInstance().LoadMaster()) { return 1; }

	asio::io_service IOService;

	tcp::socket *pSock = new tcp::socket(IOService);
	shared_ptr<tcp::socket> pSocket = shared_ptr<tcp::socket>(pSock);
	GameServerConnection GameServerConn(IOService, pSocket);

	IOService.run();
	return 0;
}
