#include "stdafx.h"
#include "SkillTree.h"
#include "Character/Player/PlayerCharacter.h"
#include "Master/MasterData.h"
#include "Packet/SkillTreeNode.h"

// コンストラクタ
SkillTree::SkillTree(PlayerCharacter *pInCharacter)
	: pCharacter(pInCharacter)
	, pParentNode(NULL)
{
	std::vector<SkillTreeItem> Items = MasterData::GetInstance().GetSkillTreeMaster().GetAll();
	for (u32 i = 0; i < Items.size(); i++)
	{
		if (Items[i].Job != pCharacter->GetJob()) { continue; }
		Node *pNode = new Node(Items[i].ID, Items[i].SkillId, Items[i].Cost);
		AddNode(pNode);
	}
}

// デストラクタ
SkillTree::~SkillTree()
{
	delete pParentNode;
	pParentNode = NULL;
}

// クライアントに送り付けるノードデータリストを生成,
void SkillTree::GenerateNodeDataList(FlexArray<SkillTreeNode> &DataList)
{
	Node *pNode = pParentNode;
	while (pNode != NULL)
	{
		u8 State = (pNode->bIsOpened ? SkillTreeNode::Open : SkillTreeNode::Closed);
		SkillTreeNode Data(pNode->NodeId, State);
		DataList.PushBack(Data);

		pNode = pNode->pNext;
	}
}

// ノード追加.
void SkillTree::AddNode(Node *pNode)
{
	if (pParentNode == NULL)
	{
		pParentNode = pNode;
		return;
	}

	Node *pCurrentNode = pParentNode;
	while (pCurrentNode->pNext != NULL)
	{
		pCurrentNode = pCurrentNode->pNext;
	}
	pCurrentNode->pNext = pNode;
}

// =========== SkillTree::Node ================

// コンストラクタ
SkillTree::Node::Node(u32 InNodeId, u32 InSkillId, u32 InGold)
	: NodeId(InNodeId)
	, SkillId(InSkillId)
	, Gold(InGold)
	, bIsOpened(false)
	, pNext(NULL)
{
}

// デストラクタ
SkillTree::Node::~Node()
{
	delete pNext;
	pNext = NULL;
}
