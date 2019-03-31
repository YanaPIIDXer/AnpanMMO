/**
 * @file SkillTreeNode.h
 * @brief �X�L���c���[�m�[�h�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __SKILLTREENODE_H__
#define __SKILLTREENODE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief �X�L���c���[�m�[�h�p�P�b�g
 */
class SkillTreeNode 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	enum NodeState
	{
		//! ���Ă���
		Closed,
		//! �J���Ă���
		Open,
	};

	//! �m�[�h�h�c
	u32 NodeId;
	//! �X�e�[�g
	u8 State;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	SkillTreeNode()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	SkillTreeNode(u32 InNodeId, u8 InState)
	{
		NodeId = InNodeId;
		State = InState;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&NodeId);
		pStream->Serialize(&State);
		
		return true;
	}
};

#endif		// #ifndef __SKILLTREENODE_H__
