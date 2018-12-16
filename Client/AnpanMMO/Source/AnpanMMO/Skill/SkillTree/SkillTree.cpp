// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillTree.h"
#include "Master/MasterData.h"

// コンストラクタ
SkillTree::SkillTree()
	: RootNodeId(0)
	, DummyNode(0, 0, 0, 0, 0.0f, 0.0f, 0)
{
}

// 初期化.
void SkillTree::Initialize(uint8 Job)
{
	TArray<SkillTreeItem> Items = MasterData::GetInstance().GetSkillTreeMaster().GetAll();
	for (const auto &Item : Items)
	{
		if (Item.Job != Job) { continue; }
		Node Nd(Item.ID, Item.SkillId, Item.Cost, Item.NeedLevel, Item.NodeX, Item.NodeY, Item.ParentNode);
		NodeMap.Add(Item.ID, Nd);
	}
	Reflesh();
}

// ノードの再構築.
void SkillTree::Reflesh()
{
	for (auto &KeyValue : NodeMap)
	{
		KeyValue.Value.Children.RemoveAt(0, KeyValue.Value.Children.Num());
	}

	for(auto &KeyValue : NodeMap)
	{
		if (KeyValue.Value.ParentNodeId == 0)
		{
			RootNodeId = KeyValue.Value.NodeId;
		}
		else
		{
			if (!NodeMap.Contains(KeyValue.Value.ParentNodeId))
			{
				continue;
			}
			NodeMap[KeyValue.Value.ParentNodeId].Children.Add(&NodeMap[KeyValue.Key]);
		}
	}
}

// 開く
void SkillTree::Open(uint32 NodeId)
{
	if (!NodeMap.Contains(NodeId)) { return; }
	NodeMap[NodeId].bIsOpened = true;
}

// ルートノードを取得.
const SkillTree::Node &SkillTree::GetRootNode() const
{
	if (!NodeMap.Contains(RootNodeId)) { return DummyNode; }
	return NodeMap[RootNodeId];
}
