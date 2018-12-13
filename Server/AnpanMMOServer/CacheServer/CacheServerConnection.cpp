#include "stdafx.h"
#include "CacheServerConnection.h"
#include "ServerHost.h"
#include "Client.h"
#include "ClientManager.h"
#include "MemoryStream/MemorySizeCaliculateStream.h"
#include "MemoryStream/MemoryStreamWriter.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Packet/PacketHeader.h"
#include "Packet/ProcessPacketBase.h"

CacheServerConnection *CacheServerConnection::pInstance = NULL;

// �R���X�g���N�^
CacheServerConnection::CacheServerConnection(const shared_ptr<tcp::socket> &pInSocket)
	: TCPConnection(pInSocket)
{
	pInstance = this;
}

// �ڑ�.
bool CacheServerConnection::Connect()
{
	boost::system::error_code ErrorCode;
	GetSocket()->connect(tcp::endpoint(asio::ip::address::from_string(ServerHost::CacheServerHost), ServerHost::CacheServerPort), ErrorCode);

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

// �p�P�b�g���M.
void CacheServerConnection::SendPacket(PacketBase *pPacket)
{
	//�܂��̓T�C�Y�����߂�
	MemorySizeCaliculateStream SizeStream;
	pPacket->Serialize(&SizeStream);

	//�V���A���C�Y�{��
	MemoryStreamWriter WriteStream(SizeStream.GetSize() + 3);

	u8 Id = (u8)pPacket->GetPacketID();
	u16 Size = SizeStream.GetSize();
	WriteStream.Serialize(&Id);
	WriteStream.Serialize(&Size);
	pPacket->Serialize(&WriteStream);

	//���M
	AsyncSend(WriteStream.GetStream(), WriteStream.GetSize());
}


// �f�[�^����M�����B
void CacheServerConnection::OnRecvData(size_t Size)
{
	while (true)
	{
		u8 *pRecvData = RecvBuffer.GetTop();
		MemoryStreamReader ReadStream(pRecvData, Size);
		PacketHeader Header;
		if (!Header.Serialize(&ReadStream) || RecvBuffer.GetSize() < Header.GetPacketSize() + 3) { break; }
		RecvBuffer.Pop(3);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		ProcessPacketBase ProcessPacket;
		ProcessPacket.Serialize(&BodyStream);
		ClientManager::GetInstance().Get(ProcessPacket.ClientId).lock()->RecvPacket(Header.GetPacketId(), &BodyStream);

		RecvBuffer.Pop(Header.GetPacketSize());
	}
}

// �ؒf���ꂽ�B
void CacheServerConnection::OnDisconnected()
{
	exit(1);
}
