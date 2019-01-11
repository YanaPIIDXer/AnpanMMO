// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MMOGameInstance.h"
#include "DLC/PakFileManager.h"
#include "Config.h"
#include "Packet/SkillTreeNode.h"
#include "Packet/ItemData.h"

// コンストラクタ
UMMOGameInstance::UMMOGameInstance(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pConnection(nullptr)
{
}

// 初期化時の処理.
void UMMOGameInstance::Init()
{
	Super::Init();

	QuestMgr.SetGameInstance(this);

	PakFileManager::GetInstance().Initialize();

	Script.SetScriptDir(TCHAR_TO_UTF8(*Config::GetScriptDirectory()));
}

// 終了時の処理.
void UMMOGameInstance::Shutdown()
{
	Super::Shutdown();
	
	Close();
}

// 接続.
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

// 切断.
void UMMOGameInstance::Close()
{
	if (pConnection == nullptr) { return; }

	delete pConnection;
	pConnection = nullptr;
}

// パケット送信.
void UMMOGameInstance::SendPacket(PacketBase *pPacket)
{
	check(pConnection != nullptr);
	pConnection->SendPacket(pPacket);
}

// ステータスを受信した。
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

// スキルリストを受信した。
void UMMOGameInstance::OnRecvSkillList(uint32 Skill1, uint32 Skill2, uint32 Skill3, uint32 Skill4)
{
	StatusCache.SetSkillList(Skill1, Skill2, Skill3, Skill4);
}

// スキルツリーデータを受信した。
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

// アイテムリストを受信した。
void UMMOGameInstance::OnRecvItemList(const FlexArray<ItemData> &Items)
{
	for (int i = 0; i < Items.GetCurrentSize(); i++)
	{
		StatusCache.AddItem(Items[i].ItemId, Items[i].Count);
	}
}

// アイテムショートカットを受信した。
void UMMOGameInstance::OnRecvItemShortcht(uint32 ItemId1, uint32 ItemId2)
{
	StatusCache.UpdateItemShortcut(ItemId1, ItemId2);
}

// クエストデータ追加.
void UMMOGameInstance::AddQuestData(const QuestData &Data)
{
	QuestMgr.Add(Data);
}

// クエストでのアンパン殺害.
void UMMOGameInstance::QuestKillAnpan(uint32 QuestId)
{
	QuestMgr.KillAnpan(QuestId);
}

// クエスト進行.
void UMMOGameInstance::ProgressQuest(uint32 QuestId, uint32 StageNo)
{
	QuestMgr.ProgressStage(QuestId, StageNo);
}

// クエストクリア
void UMMOGameInstance::ClearQuest(uint32 QuestId)
{
	QuestMgr.Clear(QuestId);
}

// クエスト破棄.
void UMMOGameInstance::RetireQuest(uint32 QuestId)
{
	QuestMgr.Retire(QuestId);
}


// パケットを受信した。
void UMMOGameInstance::OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream)
{
	OnRecvPacketDelegate.ExecuteIfBound(ID, pStream);
}
