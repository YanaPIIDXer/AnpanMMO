#include "stdafx.h"
#include "Client.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Packet/PacketHeader.h"

// �R���X�g���N�^
Client::Client(const shared_ptr<tcp::socket> &pInSocket)
	: pSocket(pInSocket)
	, bIsConnected(true)
{
	AsyncRecv(&RecvData[0], 0);
}


// ��M�J�n.
void Client::AsyncRecv(u8 *pBuffer, int Offset)
{
	pSocket->async_receive(asio::buffer(pBuffer, RECV_DATA_SIZE - Offset),
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

	RecvBuffer.Push(&RecvData[0], Size);

	u8 *pRecvData = RecvBuffer.GetTop();
	MemoryStreamReader ReadStream(pRecvData, Size);
	PacketHeader Header;
	if (Header.Serialize(&ReadStream) && RecvBuffer.GetSize() >= Header.GetPacketSize())
	{
		RecvBuffer.Pop(2);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		// @TODO:�p�P�b�g��͏���.

		RecvBuffer.Pop(Header.GetPacketSize());
	}

	AsyncRecv(&RecvData[0], 0);
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
