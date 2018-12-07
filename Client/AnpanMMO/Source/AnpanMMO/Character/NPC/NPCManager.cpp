// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "NPCManager.h"
#include "NPCCharacter.h"
#include "Master/MasterData.h"

// コンストラクタ
NPCManager::NPCManager()
	: pWorld(nullptr)
{
}

// マップが切り替わった。
void NPCManager::OnMapChanegd(uint32 MapId)
{
	TArray<NPCItem> Items = MasterData::GetInstance().GetNPCMaster().GetAll();
	for (const auto &Item : Items)
	{
		if (Item.AreaId != MapId) { continue; }
		auto *pChara = ANPCCharacter::Spawn(pWorld.Get(), &Item);
		NPCs.Add(pChara);
	}
}

// リセット
void NPCManager::Reset()
{
	for (auto pChara : NPCs)
	{
		pChara->Destroy();
	}
	NPCs.Empty();
}
