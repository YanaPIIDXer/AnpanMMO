#ifndef __SKILLTREE_H__
#define __SKILLTREE_H__

#include <boost/unordered_map.hpp>
#include "FlexArray.h"

class PlayerCharacter;
class SkillTreeNode;

/**
 * スキルツリークラス
 */
class SkillTree
{

private:	// 内部構造体定義.

	// ノード
	struct Node
	{
		// 必要ゴールド
		u32 Cost;

		// スキルＩＤ
		u32 SkillId;

		// 解禁済みか？
		bool bIsOpened;
	};

private:		// 別名定義.

	typedef boost::unordered_map<u32, Node> NodeMap;

public:

	// コンストラクタ
	SkillTree(u8 Job);

	// デストラクタ
	~SkillTree() {}

	// 開く
	bool Open(u32 NodeId);

	// 既に開かれているか？
	bool IsOpened(u32 NodeId, bool &bOutOpened) const;

	// スキルＩＤを取得.
	bool GetSkillId(u32 NodeId, u32 &OutSkillId) const;

	// クライアントに送り付けるノードデータリストを生成.
	void GenerateNodeDataList(FlexArray<SkillTreeNode> &OutDataList) const;

private:

	// ノードマップ
	NodeMap Nodes;
	
};

#endif		// #ifndef __SKILLTREE_H__
