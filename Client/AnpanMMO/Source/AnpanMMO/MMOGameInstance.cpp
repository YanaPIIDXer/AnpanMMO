// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MMOGameInstance.h"

// �R���X�g���N�^
UMMOGameInstance::UMMOGameInstance(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pConnection(nullptr)
{
}

// �I�����̏���.
void UMMOGameInstance::Shutdown()
{
	Super::Shutdown();
	
	Close();
}

// �ڑ�.
bool UMMOGameInstance::Connect(const FString &Host, int Port)
{
	pConnection = new GameServerConnection();
	if (!pConnection->Connect(Host, Port))
	{
		Close();
		return false;
	}
	return true;
}

// �ؒf.
void UMMOGameInstance::Close()
{
	if (pConnection == nullptr) { return; }

	delete pConnection;
	pConnection = nullptr;
}

// �p�P�b�g���M.
void UMMOGameInstance::SendPacket(PacketBase *pPacket)
{
	check(pConnection != nullptr);

	pConnection->SendPacket(pPacket);
}
