#include "stdafx.h"
#include "TCPConnection.h"

// コンストラクタ
TCPConnection::TCPConnection(const shared_ptr<tcp::socket> &pInSocket)
	: pSocket(pInSocket)
	, bIsConnected(true)
{
}

// デストラクタ
TCPConnection::~TCPConnection()
{
}


// 受信開始.
void TCPConnection::AsyncRecv()
{
	u8 *pBuffer = &RecvData[0];
	pSocket->async_receive(asio::buffer(pBuffer, RecvDataSize),
		bind(&TCPConnection::OnRecv, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
}

// 受信した。
void TCPConnection::OnRecv(const boost::system::error_code &ErrorCode, size_t Size)
{
	if (ErrorCode)
	{
		bIsConnected = false;
		return;
	}

	RecvBuffer.Push(&RecvData[0], Size);

	OnRecvData(Size);

	AsyncRecv();
}

// 送信.
void TCPConnection::AsyncSend(const u8 *pBuffer, int Size)
{
	shared_ptr<asio::streambuf> pSendBuffer = shared_ptr<asio::streambuf>(new asio::streambuf());
	pSendBuffer->sputn((const char *)pBuffer, Size);

	tcp::socket *pSock = pSocket.get();
	asio::async_write(*pSock, *pSendBuffer,
		bind(&TCPConnection::OnSend, this, asio::placeholders::error, asio::placeholders::bytes_transferred, pSendBuffer));
}

// 送信した。
void TCPConnection::OnSend(const boost::system::error_code &ErrorCode, size_t Size, shared_ptr<asio::streambuf> SendBuffer)
{
	if (ErrorCode)
	{
		bIsConnected = false;
		return;
	}
}
