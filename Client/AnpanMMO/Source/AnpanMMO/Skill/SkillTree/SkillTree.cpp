// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillTree.h"
#include "Master/MasterData.h"

// コンストラクタ
SkillTree::SkillTree(uint8 Job)
{
	TArray<SkillTreeItem> Items = MasterData::GetInstance().GetSkillTreeMaster().GetAll();
	for (const auto &Item : Items)
	{
		if (Item.Job != Job) { continue; }
		SkillTreeNode Node(Item.ID, Item.SkillId, Item.Cost, Item.NeedLevel, Item.ParentNode);
		Nodes.Add(Item.ID, Node);
	}
}
