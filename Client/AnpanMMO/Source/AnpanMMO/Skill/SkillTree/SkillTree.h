// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * スキルツリー
 */
class ANPANMMO_API SkillTree
{

private:		// 内部構造体の定義.

	// ノード
	struct Node
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

		// 開かれているか？
		bool bIsOpened;

		// 子ノード群.
		TArray<Node *> Children;


		// コンストラクタ
		Node(uint32 InNodeId, uint32 InSkillId, uint32 InCost, uint32 InNeedLevel, uint32 InParentNodeId)
			: NodeId(InNodeId)
			, SkillId(InSkillId)
			, Cost(InCost)
			, NeedLevel(InNeedLevel)
			, ParentNodeId(InParentNodeId)
			, bIsOpened(false) {}

		// デストラクタ
		~Node()
		{
			for (auto *pChild : Children)
			{
				delete pChild;
			}
		}

		// 開く
		void Open(uint32 OpenNodeId);

	};


public:

	// コンストラクタ
	SkillTree();

	// デストラクタ
	~SkillTree();

	// 初期化.
	void Initialize(uint8 Job);

	// 開く
	void Open(uint32 NodeId);

private:

	// ルートノード
	Node *pRootNode;

};
