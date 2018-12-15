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
	uint32 ParentId;


	// コンストラクタ
	SkillTreeNode(uint32 InNodeId, uint32 InSkillId, uint32 InCost, uint32 InNeedLevel, uint32 InParentId)
		: NodeId(InNodeId)
		, SkillId(InSkillId)
		, Cost(InCost)
		, NeedLevel(InNeedLevel)
		, ParentId(InParentId) {}

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
	~SkillTree() {}

private:

	// ノードリスト
	TMap<uint32, SkillTreeNode> Nodes;

};
