/**
 * @file PacketSkillTreeOpenRequest.h
 * @brief �X�L���c���[�J���v��
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLTREEOPENREQUEST_H__
#define __PACKETSKILLTREEOPENREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �X�L���c���[�J���v��
 */
class PacketSkillTreeOpenRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillTreeOpenRequest; }

	

	//! 
u32 NodeId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillTreeOpenRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillTreeOpenRequest(u32 InNodeId)
	{
		NodeId = InNodeId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&NodeId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEOPENREQUEST_H__
