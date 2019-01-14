// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * スキルツリー
 */
class ANPANMMO_API SkillTree
{

public:		// 内部構造体の定義.

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

		// ノードの座標.
		FVector2D NodePosition;

		// 子ノード群.
		TArray<Node *> Children;


		// コンストラクタ
		Node(uint32 InNodeId, uint32 InSkillId, uint32 InCost, uint32 InNeedLevel, float NodeX, float NodeY, uint32 InParentNodeId)
			: NodeId(InNodeId)
			, SkillId(InSkillId)
			, Cost(InCost)
			, NeedLevel(InNeedLevel)
			, NodePosition(NodeX, NodeY)
			, ParentNodeId(InParentNodeId)
			, bIsOpened(false) {}

		// デストラクタ
		~Node()
		{
			Children.Empty();
		}
	};


public:

	// コンストラクタ
	SkillTree();

	// デストラクタ
	~SkillTree() {}

	// 初期化.
	void Initialize(uint8 Job);

	// ノードの再構築.
	void Reflesh();

	// 開く
	void Open(uint32 NodeId);

	// ルートノードを取得.
	const Node &GetRootNode() const;

private:

	// ノードマップ
	TMap<uint32, Node> NodeMap;

	// ルートノードID
	uint32 RootNodeId;

	// ルートノードが見つからなかった時のダミーノード
	Node DummyNode;

};
