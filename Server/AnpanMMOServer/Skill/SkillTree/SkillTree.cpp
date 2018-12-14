#include "stdafx.h"
#include "SkillTree.h"
#include "Character/Player/PlayerCharacter.h"
#include "Master/MasterData.h"
#include "Packet/SkillTreeNode.h"

// �R���X�g���N�^
SkillTree::SkillTree(PlayerCharacter *pInCharacter)
	: pCharacter(pInCharacter)
	, pRootNode(NULL)
{
	std::vector<SkillTreeItem> Items = MasterData::GetInstance().GetSkillTreeMaster().GetAll();
	for (u32 i = 0; i < Items.size(); i++)
	{
		if (Items[i].Job != pCharacter->GetJob()) { continue; }
		Node *pNode = new Node(Items[i].ID, Items[i].SkillId, Items[i].Cost);
		AddNode(pNode);
	}
}

// �f�X�g���N�^
SkillTree::~SkillTree()
{
	delete pRootNode;
	pRootNode = NULL;
}

// �R�X�g���擾.
bool SkillTree::GetCost(u32 NodeId, u32 &OutCost) const
{
	Node *pNode = pRootNode;
	while (pNode != NULL)
	{
		if (pNode->NodeId == NodeId)
		{
			OutCost = pNode->Cost;
			return true;
		}
		pNode = pNode->pNext;
	}
	return false;
}

// �J��
bool SkillTree::Open(u32 NodeId)
{
	Node *pNode = pRootNode;
	while (pNode != NULL)
	{
		if (pNode->NodeId == NodeId)
		{
			pNode->bIsOpened = true;
			return true;
		}
		pNode = pNode->pNext;
	}
	return false;
}

// �N���C�A���g�ɑ���t����m�[�h�f�[�^���X�g�𐶐�,
void SkillTree::GenerateNodeDataList(FlexArray<SkillTreeNode> &OutDataList) const
{
	Node *pNode = pRootNode;
	while (pNode != NULL)
	{
		u8 State = (pNode->bIsOpened ? SkillTreeNode::Open : SkillTreeNode::Closed);
		SkillTreeNode Data(pNode->NodeId, State);
		OutDataList.PushBack(Data);

		pNode = pNode->pNext;
	}
}


// �m�[�h�ǉ�.
void SkillTree::AddNode(Node *pNode)
{
	if (pRootNode == NULL)
	{
		pRootNode = pNode;
		return;
	}

	Node *pCurrentNode = pRootNode;
	while (pCurrentNode->pNext != NULL)
	{
		pCurrentNode = pCurrentNode->pNext;
	}
	pCurrentNode->pNext = pNode;
}

// =========== SkillTree::Node ================

// �R���X�g���N�^
SkillTree::Node::Node(u32 InNodeId, u32 InSkillId, u32 InCost)
	: NodeId(InNodeId)
	, SkillId(InSkillId)
	, Cost(InCost)
	, bIsOpened(false)
	, pNext(NULL)
{
}

// �f�X�g���N�^
SkillTree::Node::~Node()
{
	delete pNext;
	pNext = NULL;
}
