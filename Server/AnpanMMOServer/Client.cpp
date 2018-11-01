#include "stdafx.h"
#include "Client.h"

// �R���X�g���N�^
Client::Client(const shared_ptr<tcp::socket> &pInSocket)
	: pSocket(pInSocket)
	, bIsConnected(true)
{
	AsyncRecv(&RecvBuffer[0], 0);
}


// ��M�J�n.
void Client::AsyncRecv(u8 *pBuffer, int Offset)
{
	pSocket->async_receive(asio::buffer(pBuffer, 1024 - Offset),
		bind(&Client::OnRecv, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
}

// ��M�����B
void Client::OnRecv(const system::error_code &ErrorCode, size_t Size)
{
	if (ErrorCode)
	{
		bIsConnected = false;
		return;
	}

	AsyncRecv(&RecvBuffer[0], 0);
}

// ���M.
void Client::AsyncSend(u8 *pBuffer, int Size)
{
	tcp::socket *pSock = pSocket.get();
	asio::async_write(*pSock, asio::buffer(pBuffer, Size),
		bind(&Client::OnSend, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
}

// ���M�����B
void Client::OnSend(const system::error_code &ErrorCode, size_t Size)
{
	if (ErrorCode)
	{
		bIsConnected = false;
		return;
	}
}
