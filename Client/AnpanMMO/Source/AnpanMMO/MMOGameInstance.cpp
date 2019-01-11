// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MMOGameInstance.h"
#include "DLC/PakFileManager.h"
#include "Config.h"
#include "Packet/SkillTreeNode.h"
#include "Packet/ItemData.h"

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

	QuestMgr.SetGameInstance(this);

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
void UMMOGameInstance::OnRecvStatus(uint32 Uuid, const FString &Name, u8 Job, uint32 Level, int32 MaxHp, int32 Str, int32 Def, int32 Int, int32 Mnd, int32 Vit, int32 Exp, u32 Gold, uint32 RightEquipId, uint32 LeftEquipId)
{
	StatusCache.SetUuid(Uuid);
	StatusCache.Set(Level, MaxHp, Str, Def, Int, Mnd, Vit);
	StatusCache.SetName(Name);
	StatusCache.SetJob(Job);
	StatusCache.SetExp(Exp);
	StatusCache.SetGold(Gold);
	StatusCache.SetEquip(RightEquipId, LeftEquipId);
}

// �X�L�����X�g����M�����B
void UMMOGameInstance::OnRecvSkillList(uint32 Skill1, uint32 Skill2, uint32 Skill3, uint32 Skill4)
{
	StatusCache.SetSkillList(Skill1, Skill2, Skill3, Skill4);
}

// �X�L���c���[�f�[�^����M�����B
void UMMOGameInstance::OnRecvSkillTreeData(const FlexArray<SkillTreeNode> &Nodes)
{
	for (int i = 0; i < Nodes.GetCurrentSize(); i++)
	{
		if (Nodes[i].State == SkillTreeNode::Open)
		{
			StatusCache.OpenSkillTreeNode(Nodes[i].NodeId);
		}
	}
}

// �A�C�e�����X�g����M�����B
void UMMOGameInstance::OnRecvItemList(const FlexArray<ItemData> &Items)
{
	for (int i = 0; i < Items.GetCurrentSize(); i++)
	{
		StatusCache.AddItem(Items[i].ItemId, Items[i].Count);
	}
}

// �A�C�e���V���[�g�J�b�g����M�����B
void UMMOGameInstance::OnRecvItemShortcht(uint32 ItemId1, uint32 ItemId2)
{
	StatusCache.UpdateItemShortcut(ItemId1, ItemId2);
}

// �N�G�X�g�f�[�^�ǉ�.
void UMMOGameInstance::AddQuestData(const QuestData &Data)
{
	QuestMgr.Add(Data);
}

// �N�G�X�g�ł̃A���p���E�Q.
void UMMOGameInstance::QuestKillAnpan(uint32 QuestId)
{
	QuestMgr.KillAnpan(QuestId);
}

// �N�G�X�g�i�s.
void UMMOGameInstance::ProgressQuest(uint32 QuestId, uint32 StageNo)
{
	QuestMgr.ProgressStage(QuestId, StageNo);
}

// �N�G�X�g�N���A
void UMMOGameInstance::ClearQuest(uint32 QuestId)
{
	QuestMgr.Clear(QuestId);
}

// �N�G�X�g�j��.
void UMMOGameInstance::RetireQuest(uint32 QuestId)
{
	QuestMgr.Retire(QuestId);
}


// �p�P�b�g����M�����B
void UMMOGameInstance::OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream)
{
	OnRecvPacketDelegate.ExecuteIfBound(ID, pStream);
}
