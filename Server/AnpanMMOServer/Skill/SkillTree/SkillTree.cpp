#include "stdafx.h"
#include "SkillTree.h"
#include "Character/Player/PlayerCharacter.h"
#include "Master/MasterData.h"

// �R���X�g���N�^
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

// �f�X�g���N�^
SkillTree::~SkillTree()
{
	delete pParentNode;
	pParentNode = NULL;
}


// �m�[�h�ǉ�.
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

// �R���X�g���N�^
SkillTree::Node::Node(u32 InNodeId, u32 InSkillId, u32 InGold)
	: NodeId(InNodeId)
	, SkillId(InSkillId)
	, Gold(InGold)
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
