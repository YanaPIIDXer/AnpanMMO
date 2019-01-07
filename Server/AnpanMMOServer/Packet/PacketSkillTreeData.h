/**
 * @file PacketSkillTreeData.h
 * @brief �X�L���c���[�f�[�^�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLTREEDATA_H__
#define __PACKETSKILLTREEDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"
#include "SkillTreeNode.h"
#include "PacketID.h"


/**
 * @brief �X�L���c���[�f�[�^�p�P�b�g
 */
class PacketSkillTreeData  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillTreeData; }

	

	//! �m�[�h���X�g
	FlexArray<SkillTreeNode> Nodes;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillTreeData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillTreeData(FlexArray<SkillTreeNode> InNodes)
	{
		Nodes = InNodes;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Nodes.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEDATA_H__
