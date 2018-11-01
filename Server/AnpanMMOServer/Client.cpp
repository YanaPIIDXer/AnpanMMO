#include "stdafx.h"
#include "Client.h"

// コンストラクタ
Client::Client(const shared_ptr<tcp::socket> &pInSocket)
	: pSocket(pInSocket)
	, bIsConnected(true)
{
	AsyncRecv(&RecvBuffer[0], 0);
}


// 受信開始.
void Client::AsyncRecv(u8 *pBuffer, int Offset)
{
	pSocket->async_receive(asio::buffer(pBuffer, 1024 - Offset),
		bind(&Client::OnRecv, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
}

// 受信した。
void Client::OnRecv(const system::error_code &ErrorCode, size_t Size)
{
	if (ErrorCode)
	{
		bIsConnected = false;
		return;
	}

	AsyncRecv(&RecvBuffer[0], 0);
}
