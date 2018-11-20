// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MMOGameInstance.h"
#include "DLC/PakFileManager.h"

// �R���X�g���N�^
UMMOGameInstance::UMMOGameInstance(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pConnection(nullptr)
{
}

// ���������̏���.
void UMMOGameInstance::Init()
{
	Super::Init();

	PakFileManager::GetInstance().Initialize();
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

	pConnection->OnRecvPacketDelegate.BindUObject(this, &UMMOGameInstance::OnRecvPacket);
	
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

// �X�e�[�^�X����M�����B
void UMMOGameInstance::OnRecvStatus(uint32 Uuid, int32 MaxHp, int32 Atk, int32 Def, int32 Exp)
{
	StatusCache.SetUuid(Uuid);
	StatusCache.Set(MaxHp, Atk, Def);
	StatusCache.SetExp(Exp);
}


// �p�P�b�g����M�����B
void UMMOGameInstance::OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	OnRecvPacketDelegate.ExecuteIfBound(ID, pStream);
}
