#include "stdafx.h"
#include "CacheServerConnection.h"
#include "Config.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Packet/PacketHeader.h"

CacheServerConnection *CacheServerConnection::pInstance = NULL;

// コンストラクタ
CacheServerConnection::CacheServerConnection(const shared_ptr<tcp::socket> &pInSocket)
	: TCPConnection(pInSocket)
	, Receiver(this)
{
	pInstance = this;
}

// 接続.
bool CacheServerConnection::Connect()
{
	boost::system::error_code ErrorCode;
	GetSocket()->connect(tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), Config::CacheServerPort), ErrorCode);

	if (ErrorCode)
	{
		std::cout << ErrorCode.message() << std::endl;
		return false;
	}
	
	std::cout << "Cache Server Connected!" << std::endl;
	bIsConnected = true;
	AsyncRecv();
	return true;
}


// データを受信した。
void CacheServerConnection::OnRecvData(size_t Size)
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

