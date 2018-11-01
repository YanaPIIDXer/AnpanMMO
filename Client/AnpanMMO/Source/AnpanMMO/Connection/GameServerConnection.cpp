// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameServerConnection.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Packet/PacketHeader.h"

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
	int32 Size = SendBuffer.GetSize();
	int32 SendSize = 0;
	pSocket->Send(SendBuffer.GetTop(), Size, SendSize);
	SendBuffer.Pop(SendSize);
}

// ��M����.
void GameServerConnection::RecvProc()
{
	uint8 RecvData[1024];
	int32 RecvSize = 0;
	pSocket->Recv(&RecvData[0], 1024, RecvSize);
	RecvBuffer.Push(&RecvData[0], RecvSize);

	MemoryStreamReader StreamReader(RecvBuffer.GetTop(), RecvBuffer.GetSize());
	PacketHeader Header;
	if (Header.Serialize(&StreamReader) && RecvBuffer.GetSize() >= Header.GetPacketSize() + 2)
	{
		RecvBuffer.Pop(2);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		// @TODO:�p�P�b�g��͏���.

		RecvBuffer.Pop(Header.GetPacketSize());
	}
}
