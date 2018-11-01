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

// 送信.
void Client::AsyncSend(u8 *pBuffer, int Size)
{
	tcp::socket *pSock = pSocket.get();
	asio::async_write(*pSock, asio::buffer(pBuffer, Size),
		bind(&Client::OnSend, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
}

// 送信した。
void Client::OnSend(const system::error_code &ErrorCode, size_t Size)
{
	if (ErrorCode)
	{
		bIsConnected = false;
		return;
	}
}
