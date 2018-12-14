#ifndef __SKILLTREE_H__
#define __SKILLTREE_H__

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
		// ノードＩＤ
		u32 NodeId;

		// スキルＩＤ
		u32 SkillId;

		// 必要ゴールド
		u32 Gold;

		// 解禁済みか？
		bool bIsOpened;

		// 次のノード
		Node *pNext;


		// コンストラクタ
		Node(u32 InNodeId, u32 InSkillId, u32 InGold);

		// デストラクタ
		~Node();
	};


public:

	// コンストラクタ
	SkillTree(PlayerCharacter *pInCharacter);

	// デストラクタ
	~SkillTree();

	// クライアントに送り付けるノードデータリストを生成.
	void GenerateNodeDataList(FlexArray<SkillTreeNode> &DataList);

private:

	// キャラクタ
	PlayerCharacter *pCharacter;

	// 親ノード
	Node *pParentNode;


	// ノード追加.
	void AddNode(Node *pNode);

};

#endif		// #ifndef __SKILLTREE_H__
