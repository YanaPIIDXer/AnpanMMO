// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MMOGameInstance.h"
#include "DLC/PakFileManager.h"
#include "Config.h"

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

	Script.SetScriptDir(TCHAR_TO_UTF8(*Config::GetScriptDirectory()));
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
	Close();

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
void UMMOGameInstance::OnRecvStatus(uint32 Uuid, const FString &Name, u8 Job, int32 MaxHp, int32 Atk, int32 Def, int32 Exp, u32 Gold)
{
	StatusCache.SetUuid(Uuid);
	StatusCache.Set(MaxHp, Atk, Def);
	StatusCache.SetName(Name);
	StatusCache.SetJob(Job);
	StatusCache.SetExp(Exp);
	StatusCache.SetGold(Gold);
}

// �X�L�����X�g����M�����B
void UMMOGameInstance::OnRecvSkillList(uint32 NormalAttack, uint32 Skill1, uint32 Skill2, uint32 Skill3, uint32 Skill4)
{
	StatusCache.SetSkillList(NormalAttack, Skill1, Skill2, Skill3, Skill4);
}


// �p�P�b�g����M�����B
void UMMOGameInstance::OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	OnRecvPacketDelegate.ExecuteIfBound(ID, pStream);
}
