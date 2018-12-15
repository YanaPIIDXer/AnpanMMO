// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// スキルツリーノード
struct SkillTreeNode
{
	// ノードＩＤ
	uint32 NodeId;

	// スキルＩＤ
	uint32 SkillId;

	// コスト
	uint32 Cost;

	// 必要レベル
	uint32 NeedLevel;

	// 親ノードＩＤ
	uint32 ParentNodeId;

	// 子ノード群.
	TArray<SkillTreeNode *> Children;


	// コンストラクタ
	SkillTreeNode(uint32 InNodeId, uint32 InSkillId, uint32 InCost, uint32 InNeedLevel, uint32 InParentNodeId)
		: NodeId(InNodeId)
		, SkillId(InSkillId)
		, Cost(InCost)
		, NeedLevel(InNeedLevel)
		, ParentNodeId(InParentNodeId) {}

	// デストラクタ
	~SkillTreeNode()
	{
		for (auto *pChild : Children)
		{
			delete pChild;
		}
	}

};

/**
 * スキルツリー
 */
class ANPANMMO_API SkillTree
{

public:

	// コンストラクタ
	SkillTree(uint8 Job);

	// デストラクタ
	~SkillTree();

private:

	// ルートノード
	SkillTreeNode *pRootNode;

};
