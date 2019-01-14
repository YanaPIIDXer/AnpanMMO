// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

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

		// �m�[�h�̍��W.
		FVector2D NodePosition;

		// �q�m�[�h�Q.
		TArray<Node *> Children;


		// �R���X�g���N�^
		Node(uint32 InNodeId, uint32 InSkillId, uint32 InCost, uint32 InNeedLevel, float NodeX, float NodeY, uint32 InParentNodeId)
			: NodeId(InNodeId)
			, SkillId(InSkillId)
			, Cost(InCost)
			, NeedLevel(InNeedLevel)
			, NodePosition(NodeX, NodeY)
			, ParentNodeId(InParentNodeId)
			, bIsOpened(false) {}

		// �f�X�g���N�^
		~Node()
		{
			Children.Empty();
		}
	};


public:

	// �R���X�g���N�^
	SkillTree();

	// �f�X�g���N�^
	~SkillTree() {}

	// ������.
	void Initialize(uint8 Job);

	// �m�[�h�̍č\�z.
	void Reflesh();

	// �J��
	void Open(uint32 NodeId);

	// ���[�g�m�[�h���擾.
	const Node &GetRootNode() const;

private:

	// �m�[�h�}�b�v
	TMap<uint32, Node> NodeMap;

	// ���[�g�m�[�hID
	uint32 RootNodeId;

	// ���[�g�m�[�h��������Ȃ��������̃_�~�[�m�[�h
	Node DummyNode;

};
