// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// �X�L���c���[�m�[�h
struct SkillTreeNode
{
	// �m�[�h�h�c
	uint32 NodeId;

	// �X�L���h�c
	uint32 SkillId;

	// �R�X�g
	uint32 Cost;

	// �K�v���x��
	uint32 NeedLevel;

	// �e�m�[�h�h�c
	uint32 ParentNodeId;

	// �q�m�[�h�Q.
	TArray<SkillTreeNode *> Children;


	// �R���X�g���N�^
	SkillTreeNode(uint32 InNodeId, uint32 InSkillId, uint32 InCost, uint32 InNeedLevel, uint32 InParentNodeId)
		: NodeId(InNodeId)
		, SkillId(InSkillId)
		, Cost(InCost)
		, NeedLevel(InNeedLevel)
		, ParentNodeId(InParentNodeId) {}

	// �f�X�g���N�^
	~SkillTreeNode()
	{
		for (auto *pChild : Children)
		{
			delete pChild;
		}
	}

};

/**
 * �X�L���c���[
 */
class ANPANMMO_API SkillTree
{

public:

	// �R���X�g���N�^
	SkillTree(uint8 Job);

	// �f�X�g���N�^
	~SkillTree();

private:

	// ���[�g�m�[�h
	SkillTreeNode *pRootNode;

};
