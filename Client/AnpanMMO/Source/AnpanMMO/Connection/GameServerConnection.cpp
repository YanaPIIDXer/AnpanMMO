// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameServerConnection.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Packet/PacketHeader.h"
#include "Packet/PacketBase.h"
#include "MemoryStream/MemorySizeCaliculateStream.h"
#include "MemoryStream/MemoryStreamWriter.h"

const int GameServerConnection::RecvDataSize = 1024;

// �R���X�g���N�^
GameServerConnection::GameServerConnection()
	: pSocket(nullptr)
{
}

// �f�X�g���N�^
GameServerConnection::~GameServerConnection()
{
	Close();
}

// �ڑ�.
bool GameServerConnection::Connect(const FString &Host, int32 Port)
{
	if (pSocket != nullptr)
	{
		// ���̂܂�return�̕��������E�E�E�H
		Close();
	}

	pSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, "GameServerConnection");
	if (pSocket == nullptr) { return false; }

	TSharedRef<FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	bool bIsValidHost = false;
	Addr->SetIp(*Host, bIsValidHost);
	Addr->SetPort(Port);

	if (!pSocket->Connect(Addr.Get())) { return false; }

	pSocket->SetNonBlocking(true);
	return true;
}

// �ؒf.
void GameServerConnection::Close()
{
	if (pSocket == nullptr) { return; }
	
	pSocket->Close();
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(pSocket);
	pSocket = nullptr;
}

// �p�P�b�g���M.
void GameServerConnection::SendPacket(PacketBase *pPacket)
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
	
	const u8 *pData = WriteStream.GetStream();
	SendBuffer.Push(pData, WriteStream.GetSize());
}

// ���t���[���̏���.
void GameServerConnection::Tick(float DeltaTime)
{
	if (!IsConnected()) { return; }

	SendProc();
	RecvProc();
}


// ���M����.
void GameServerConnection::SendProc()
{
	uint8 *pData = SendBuffer.GetTop();
	int32 Size = SendBuffer.GetSize();
	int32 SendSize = 0;
	if (!pSocket->Send(pData, Size, SendSize) || SendSize <= 0) { return; }
	SendBuffer.Pop(SendSize);
}

// ��M����.
void GameServerConnection::RecvProc()
{
	uint8 RecvData[RecvDataSize];
	int32 RecvSize = 0;

	if (!pSocket->Recv(&RecvData[0], RecvDataSize, RecvSize) || RecvSize <= 0) { return; }
	RecvBuffer.Push(&RecvData[0], RecvSize);

	uint8 *pData = RecvBuffer.GetTop();
	if (pData == nullptr) { return; }

	MemoryStreamReader StreamReader(pData, RecvBuffer.GetSize());
	PacketHeader Header;
	if (Header.Serialize(&StreamReader) && RecvBuffer.GetSize() >= Header.GetPacketSize())
	{
		RecvBuffer.Pop(2);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		OnRecvPacketDelegate.ExecuteIfBound(Header.GetPacketId(), &BodyStream);

		RecvBuffer.Pop(Header.GetPacketSize());
	}
}
