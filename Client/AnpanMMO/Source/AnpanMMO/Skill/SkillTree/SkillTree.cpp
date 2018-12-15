// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillTree.h"
#include "Master/MasterData.h"

// コンストラクタ
SkillTree::SkillTree(uint8 Job)
	: pRootNode(nullptr)
{
	TArray<SkillTreeItem> Items = MasterData::GetInstance().GetSkillTreeMaster().GetAll();
	TMap<uint32, SkillTreeNode *> NodeMap;
	for (const auto &Item : Items)
	{
		if (Item.Job != Job) { continue; }
		SkillTreeNode *pNode = new SkillTreeNode(Item.ID, Item.SkillId, Item.Cost, Item.NeedLevel, Item.ParentNode);
		NodeMap.Add(Item.ID, pNode);
	}
	for (auto KeyValue : NodeMap)
	{
		if (KeyValue.Key == 0)
		{
			delete pRootNode;
			pRootNode = KeyValue.Value;
		}
		else
		{
			if (!NodeMap.Contains(KeyValue.Value->ParentNodeId))
			{
				delete KeyValue.Value;
				continue;
			}
			NodeMap[KeyValue.Value->ParentNodeId]->Children.Add(KeyValue.Value);
		}
	}
}

// デストラクタ
SkillTree::~SkillTree()
{
	delete pRootNode;
	pRootNode = nullptr;
}
