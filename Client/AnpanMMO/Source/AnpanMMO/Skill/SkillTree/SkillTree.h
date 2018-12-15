// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * �X�L���c���[
 */
class ANPANMMO_API SkillTree
{

public:		// �����\���̂̒�`.

	// �m�[�h
	struct Node
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

		// �J����Ă��邩�H
		bool bIsOpened;

		// �q�m�[�h�Q.
		TArray<Node *> Children;


		// �R���X�g���N�^
		Node(uint32 InNodeId, uint32 InSkillId, uint32 InCost, uint32 InNeedLevel, uint32 InParentNodeId)
			: NodeId(InNodeId)
			, SkillId(InSkillId)
			, Cost(InCost)
			, NeedLevel(InNeedLevel)
			, ParentNodeId(InParentNodeId)
			, bIsOpened(false) {}

		// �f�X�g���N�^
		~Node()
		{
			for (auto *pChild : Children)
			{
				delete pChild;
			}
			Children.Empty();
		}

		// �J��
		void Open(uint32 OpenNodeId);

	};


public:

	// �R���X�g���N�^
	SkillTree();

	// �f�X�g���N�^
	~SkillTree();

	// ������.
	void Initialize(uint8 Job);

	// �J��
	void Open(uint32 NodeId);

	// �m�[�h���擾.
	Node *GetNode() const { return pRootNode; }

private:

	// ���[�g�m�[�h
	Node *pRootNode;

};
