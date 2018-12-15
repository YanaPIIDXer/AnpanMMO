#ifndef __SKILLTREE_H__
#define __SKILLTREE_H__

#include <boost/unordered_map.hpp>
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
		// �K�v�S�[���h
		u32 Cost;

		// ���֍ς݂��H
		bool bIsOpened;
	};

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, Node> NodeMap;

public:

	// �R���X�g���N�^
	SkillTree(u8 Job);

	// �f�X�g���N�^
	~SkillTree() {}

	// �J��
	bool Open(u32 NodeId);

	// ���ɊJ����Ă��邩�H
	bool IsOpened(u32 NodeId, bool &bOutOpened);

	// �N���C�A���g�ɑ���t����m�[�h�f�[�^���X�g�𐶐�.
	void GenerateNodeDataList(FlexArray<SkillTreeNode> &OutDataList) const;

private:

	// �m�[�h�}�b�v
	NodeMap Nodes;
	
};

#endif		// #ifndef __SKILLTREE_H__
