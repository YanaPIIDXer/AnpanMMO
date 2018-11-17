#include "stdafx.h"
#include "GameServerConnection.h"
#include "Config.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Packet/PacketHeader.h"

// �R���X�g���N�^
GameServerConnection::GameServerConnection(asio::io_service &IOService, const shared_ptr<tcp::socket> &pInSocket)
	: TCPConnection(pInSocket)
	, Acceptor(IOService, tcp::endpoint(tcp::v4(), Config::CacheServerPort))
	, Receiver(this)
{
	Accept();
}


// �f�[�^����M�����B
void GameServerConnection::OnRecvData(size_t Size)
{
	u8 *pRecvData = RecvBuffer.GetTop();
	MemoryStreamReader ReadStream(pRecvData, Size);
	PacketHeader Header;
	if (Header.Serialize(&ReadStream) && RecvBuffer.GetSize() >= Header.GetPacketSize() + 3)
	{
		RecvBuffer.Pop(3);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		Receiver.RecvPacket(Header.GetPacketId(), &BodyStream);
		
		RecvBuffer.Pop(Header.GetPacketSize());
	}
}


// Accept����B
void GameServerConnection::Accept()
{
	Acceptor.async_accept(*GetSocket(), bind(&GameServerConnection::OnAccept, this, asio::placeholders::error));
}

// Accept�����B
void GameServerConnection::OnAccept(const boost::system::error_code &ErrorCode)
{
	if (ErrorCode)
	{
		std::cout << ErrorCode.message() << std::endl;
		return;
	}
	bIsConnected = true;
	AsyncRecv();
}
