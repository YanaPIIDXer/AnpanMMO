#ifndef __SKILLTREE_H__
#define __SKILLTREE_H__

#include "FlexArray.h"

class PlayerCharacter;
class SkillTreeNode;

/**
 * �X�L���c���[�N���X
 */
class SkillTree
{

private:	// �����\���̒�`.

	// �m�[�h
	struct Node
	{
		// �m�[�h�h�c
		u32 NodeId;

		// �X�L���h�c
		u32 SkillId;

		// �K�v�S�[���h
		u32 Cost;

		// ���֍ς݂��H
		bool bIsOpened;

		// ���̃m�[�h
		Node *pNext;


		// �R���X�g���N�^
		Node(u32 InNodeId, u32 InSkillId, u32 InCost);

		// �f�X�g���N�^
		~Node();
	};


public:

	// �R���X�g���N�^
	SkillTree(PlayerCharacter *pInCharacter);

	// �f�X�g���N�^
	~SkillTree();

	// �R�X�g�擾.
	bool GetCost(u32 NodeId, u32 &OutCost) const;

	// �J��
	bool Open(u32 NodeId);

	// �N���C�A���g�ɑ���t����m�[�h�f�[�^���X�g�𐶐�.
	void GenerateNodeDataList(FlexArray<SkillTreeNode> &DataList);

private:

	// �L�����N�^
	PlayerCharacter *pCharacter;

	// �ŏ��̃m�[�h
	Node *pRootNode;


	// �m�[�h�ǉ�.
	void AddNode(Node *pNode);

};

#endif		// #ifndef __SKILLTREE_H__
