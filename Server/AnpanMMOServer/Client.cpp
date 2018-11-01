#include "stdafx.h"
#include "Client.h"

// コンストラクタ
Client::Client(const shared_ptr<tcp::socket> &pInSocket)
	: pSocket(pInSocket)
	, bIsConnected(true)
{
}
