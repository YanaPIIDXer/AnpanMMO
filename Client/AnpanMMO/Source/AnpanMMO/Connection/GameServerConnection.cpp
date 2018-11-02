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

	return true;
}

// �ؒf.
void GameServerConnection::Close()
{
	if (pSocket == nullptr) { return; }
	
	pSocket->Close();
	pSocket = nullptr;
}

// �p�P�b�g���M.
void GameServerConnection::SendPacket(PacketBase *pPacket)
{
	// �T�C�Y�����߂�B
	MemorySizeCaliculateStream CalcStream;
	pPacket->Serialize(&CalcStream);

	int32 SendSize = CalcStream.GetSize();

	// �V���A���C�Y
	MemoryStreamWriter WriteStream(SendSize);
	pPacket->Serialize(&WriteStream);
	
	const u8 *pData = WriteStream.GetStream();
	SendBuffer.Push(pData, SendSize);
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
	if (pData == nullptr) { return; }

	int32 Size = SendBuffer.GetSize();
	int32 SendSize = 0;
	pSocket->Send(pData, Size, SendSize);
	SendBuffer.Pop(SendSize);
}

// ��M����.
void GameServerConnection::RecvProc()
{
	uint8 RecvData[RecvDataSize];
	int32 RecvSize = 0;
	pSocket->Recv(&RecvData[0], RecvDataSize, RecvSize);
	RecvBuffer.Push(&RecvData[0], RecvSize);

	MemoryStreamReader StreamReader(RecvBuffer.GetTop(), RecvBuffer.GetSize());
	PacketHeader Header;
	if (Header.Serialize(&StreamReader) && RecvBuffer.GetSize() >= Header.GetPacketSize() + 2)
	{
		RecvBuffer.Pop(2);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		// @TODO:�p�P�b�g��͏���.
		UE_LOG(LogTemp, Log, TEXT("RecvPacket PacketID:%X"), Header.GetPacketId());

		RecvBuffer.Pop(Header.GetPacketSize());
	}
}
