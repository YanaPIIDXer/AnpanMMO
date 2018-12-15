// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillTree.h"
#include "Master/MasterData.h"

// �R���X�g���N�^
SkillTree::SkillTree()
	: pRootNode(nullptr)
{
}

// �f�X�g���N�^
SkillTree::~SkillTree()
{
	delete pRootNode;
	pRootNode = nullptr;
}

// ������.
void SkillTree::Initialize(uint8 Job)
{
	TArray<SkillTreeItem> Items = MasterData::GetInstance().GetSkillTreeMaster().GetAll();
	TMap<uint32, Node *> NodeMap;
	for (const auto &Item : Items)
	{
		if (Item.Job != Job) { continue; }
		Node *pNode = new Node(Item.ID, Item.SkillId, Item.Cost, Item.NeedLevel, Item.ParentNode);
		NodeMap.Add(Item.ID, pNode);
	}
	for (auto KeyValue : NodeMap)
	{
		if (KeyValue.Key == 0)
		{
			delete pRootNode;
			pRootNode = KeyValue.Value;
		}
		else
		{
			if (!NodeMap.Contains(KeyValue.Value->ParentNodeId))
			{
				delete KeyValue.Value;
				continue;
			}
			NodeMap[KeyValue.Value->ParentNodeId]->Children.Add(KeyValue.Value);
		}
	}
}

// �J��
void SkillTree::Open(uint32 NodeId)
{
	if (pRootNode == nullptr) { return; }
	pRootNode->Open(NodeId);
}


// =============== SkillTree::Node ===================

// �J��
void SkillTree::Node::Open(uint32 OpenNodeId)
{
	if (NodeId == OpenNodeId)
	{
		bIsOpened = true;
		return;
	}

	for (auto *pChild : Children)
	{
		pChild->Open(OpenNodeId);
	}
}
