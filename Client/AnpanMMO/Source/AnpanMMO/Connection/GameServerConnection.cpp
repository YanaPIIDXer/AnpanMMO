// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameServerConnection.h"

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

}
