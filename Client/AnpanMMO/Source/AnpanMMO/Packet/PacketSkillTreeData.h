/**
 * @file PacketSkillTreeData.h
 * @brief スキルツリーデータ
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
 * @brief スキルツリーデータ
 */
class PacketSkillTreeData  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillTreeData; }

	

	//! 
FlexArray<SkillTreeNode> ノードリスト;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillTreeData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillTreeData(FlexArray<SkillTreeNode> Inノードリスト)
	{
		ノードリスト = Inノードリスト;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ノードリスト.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEDATA_H__
