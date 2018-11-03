#include "stdafx.h"
#include "Client.h"
#include "Packet/PacketBase.h"
#include "MemoryStream/MemorySizeCaliculateStream.h"
#include "MemoryStream/MemoryStreamWriter.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Packet/PacketHeader.h"
#include "ClientState/ClientStateBase.h"
#include "ClientState/ClientStateTitle.h"

// �R���X�g���N�^
Client::Client(const shared_ptr<tcp::socket> &pInSocket)
	: pSocket(pInSocket)
	, bIsConnected(true)
	, pState(new ClientStateTitle(this))
	, Uuid(0)
{
	AsyncRecv(&RecvData[0], 0);
}

// �f�X�g���N�^
Client::~Client()
{
	delete pState;
	pState = NULL;
}

// �p�P�b�g���M.
void Client::SendPacket(PacketBase *pPacket)
{
	//�܂��̓T�C�Y�����߂�
	MemorySizeCaliculateStream SizeStream;
	pPacket->Serialize(&SizeStream);

	//�V���A���C�Y�{��
	MemoryStreamWriter WriteStream(SizeStream.GetSize() + 2);

	u8 Id = (u8)pPacket->GetPacketID();
	u8 Size = SizeStream.GetSize();
	WriteStream.Serialize(&Id);
	WriteStream.Serialize(&Size);
	pPacket->Serialize(&WriteStream);

	//���M
	AsyncSend(WriteStream.GetStream(), WriteStream.GetSize());
}

// �X�e�[�g�؂�ւ�
void Client::ChangeState(ClientStateBase *pNextState)
{
	delete pState;
	pState = pNextState;
	pState->BeginState();
}


// ��M�J�n.
void Client::AsyncRecv(u8 *pBuffer, int Offset)
{
	pSocket->async_receive(asio::buffer(pBuffer, RecvDataSize - Offset),
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
	if (Header.Serialize(&ReadStream) && RecvBuffer.GetSize() >= Header.GetPacketSize() + 2)
	{
		RecvBuffer.Pop(2);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		pState->AnalyzePacket(Header.GetPacketId(), &BodyStream);
		
		RecvBuffer.Pop(Header.GetPacketSize());
	}

	AsyncRecv(&RecvData[0], 0);
}

// ���M.
void Client::AsyncSend(const u8 *pBuffer, int Size)
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
